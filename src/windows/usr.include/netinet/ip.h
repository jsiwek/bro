#pragma once

#include <inaddr.h>
#include <stdint.h>

struct ip {
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
	uint8_t ip_hl:4;
	uint8_t ip_v:4;
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
	uint8_t ip_v:4;
	uint8_t ip_hl:4;
#else
#error Unknown byte order.
#endif
	uint8_t  ip_tos;
	uint16_t ip_len;
	uint16_t ip_id;
	uint16_t ip_off;
	uint8_t  ip_ttl;
	uint8_t  ip_p;
	uint16_t ip_sum;
	struct in_addr ip_src, ip_dst;
};
