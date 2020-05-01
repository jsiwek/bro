#pragma once

#include <stdint.h>

#define ICMP6_DST_UNREACH          1
#define ICMP6_PACKET_TOO_BIG       2
#define ICMP6_TIME_EXCEEDED        3
#define ICMP6_PARAM_PROB           4

#define ICMP6_ECHO_REQUEST       128
#define ICMP6_ECHO_REPLY         129

#define MLD_LISTENER_QUERY       130
#define MLD_LISTENER_REPORT      131
#define MLD_LISTENER_REDUCTION   132

#define ND_ROUTER_SOLICIT        133
#define ND_ROUTER_ADVERT         134
#define ND_NEIGHBOR_SOLICIT      135
#define ND_NEIGHBOR_ADVERT       136
#define ND_REDIRECT              137

#define ICMP6_ROUTER_RENUMBERING 138

struct icmp6_hdr {
	uint8_t  icmp6_type;   /* type field */
	uint8_t  icmp6_code;   /* code field */
	uint16_t icmp6_cksum;  /* checksum field */
	union {
		uint32_t icmp6_un_data32[1]; /* type-specific field */
		uint16_t icmp6_un_data16[2]; /* type-specific field */
		uint8_t  icmp6_un_data8[4];  /* type-specific field */
	} icmp6_dataun;
};
