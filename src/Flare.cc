// See the file "COPYING" in the main distribution directory for copyright.

#include "Flare.h"
#include "Reporter.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <winsock2.h>
#include <iostream>

using namespace bro;

#define fatalError(...)					\
do							\
	{						\
	if ( reporter )					\
		reporter->FatalError(__VA_ARGS__);	\
	else						\
		{					\
		fprintf(stderr, __VA_ARGS__);		\
		fprintf(stderr, "\n");			\
		_exit(1);				\
		}					\
	}						\
while (0)


Flare::Flare()
	{
	WSADATA wsaData;
	if ( WSAStartup(MAKEWORD(2,2), &wsaData) != 0 )
		fatalError("WSAStartup failure: %d", WSAGetLastError());

	recvfd = WSASocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP, nullptr, 0,
			   WSA_FLAG_OVERLAPPED | WSA_FLAG_NO_HANDLE_INHERIT);
	if ( recvfd == (int) INVALID_SOCKET )
		fatalError("WSASocket failure: %d", WSAGetLastError());
	sendfd = WSASocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP, nullptr, 0,
			   WSA_FLAG_OVERLAPPED | WSA_FLAG_NO_HANDLE_INHERIT);
	if ( sendfd == (int) INVALID_SOCKET )
		fatalError("WSASocket failure: %d", WSAGetLastError());
	
	sockaddr_in sa;
	memset(&sa, 0, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = inet_addr("127.0.0.1");
	if ( bind(recvfd, (sockaddr*) &sa, sizeof(sa)) == SOCKET_ERROR )
		fatalError("bind failure: %d", WSAGetLastError());
	int salen = sizeof(sa);
	if ( getsockname(recvfd, (sockaddr*) &sa, &salen) == SOCKET_ERROR )
		fatalError("getsockname failure: %d", WSAGetLastError());
	if ( connect(sendfd, (sockaddr*) &sa, sizeof(sa)) == SOCKET_ERROR )
		fatalError("connect failure: %d", WSAGetLastError());
	}

[[noreturn]] static void bad_pipe_op(const char* which, bool signal_safe)
	{
	if ( signal_safe )
		abort();

	char buf[256];
	bro_strerror_r(errno, buf, sizeof(buf));

	if ( reporter )
		reporter->FatalErrorWithCore("unexpected pipe %s failure: %s", which, buf);
	else
		{
		fprintf(stderr, "unexpected pipe %s failure: %s", which, buf);
		abort();
		}
	}

void Flare::Fire(bool signal_safe)
	{
	char tmp = 0;

	for ( ; ; )
		{
		int n = send(sendfd, &tmp, 1, 0);

		if ( n > 0 )
			// Success -- wrote a byte to pipe.
			break;

		if ( n < 0 )
			{
			errno = WSAGetLastError();
			bad_pipe_op("send", signal_safe);
			}

		// No error, but didn't write a byte: try again.
		}
	}

int Flare::Extinguish(bool signal_safe)
	{
	int rval = 0;
	char tmp[256];

	for ( ; ; )
		{
		int n = recv(recvfd, tmp, sizeof(tmp), 0);

		if ( n >= 0 )
			{
			rval += n;
			// Pipe may not be empty yet: try again.
			continue;
			}

		if ( WSAGetLastError() == WSAEWOULDBLOCK )
			break;

		errno = WSAGetLastError();
		bad_pipe_op("recv", signal_safe);
		}

	return rval;
	}
