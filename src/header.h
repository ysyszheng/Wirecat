/*
 * The part of TCP and IPv4 packet header refers to
 * https://www.tcpdump.org/other/sniffex.c
 */
#ifndef HEADER_H
#define HEADER_H

#include <arpa/inet.h>
#include <ctype.h>
#include <errno.h>
#include <netinet/in.h>
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

/* ethernet headers are always exactly 14 bytes */
#define SIZE_ETHERNET 14

/* Ethernet addresses are 6 bytes */
#define ETHER_ADDR_LEN 6

/* Ethernet header */
typedef struct {
  uint8_t ether_dhost[ETHER_ADDR_LEN]; /* destination host address */
  uint8_t ether_shost[ETHER_ADDR_LEN]; /* source host address */
  uint16_t ether_type;                 /* IP? ARP? RARP? etc */
} ethernet_header;                     /* 14 bytes in total */

/* IPv4 header */
typedef struct {
  uint8_t ip_vhl;                 /* version << 4 | header length >> 2 */
  uint8_t ip_tos;                 /* type of service */
  uint16_t ip_len;                /* total length */
  uint16_t ip_id;                 /* identification */
  u_short ip_off;                /* fragment offset field */
#define IP_RF 0x8000             /* reserved fragment flag */
#define IP_DF 0x4000             /* don't fragment flag */
#define IP_MF 0x2000             /* more fragments flag */
#define IP_OFFMASK 0x1fff        /* mask for fragmenting bits */
  uint8_t ip_ttl;                 /* time to live */
  uint8_t ip_p;                   /* protocol */
  u_short ip_sum;                /* checksum */
  struct in_addr ip_src, ip_dst; /* source and dest address */
} IPv4_header;
#define IPv4_HL(ip) (((ip)->ip_vhl) & 0x0f)
#define IPv4_V(ip) (((ip)->ip_vhl) >> 4)

/* IPv6 header */
typedef struct{
  u_int version: 4 ;             /* version, 4 bits */
  uint8_t flow_type ;            /* flow type, 1 byte */
  u_int flow_id: 20 ;            /* flow id, 20 bits*/
  uint16_t len_load;             /* length of load， 2 bytes*/
  uint8_t next_head;             /* next head，1 byte */
  uint8_t hop_limit;             /* hop limit，1 byte */
  u_short src_addr[8];           /* source address，16 bytes */
  u_short dest_addr[8];          /* dest address，16 bytes */
} IPv6_header;




/* TCP header */
typedef u_int tcp_seq;

typedef struct {
  u_short th_sport; /* source port */
  u_short th_dport; /* destination port */
  tcp_seq th_seq;   /* sequence number */
  tcp_seq th_ack;   /* acknowledgement number */
  u_char th_offx2;  /* data offset, rsvd */
#define TH_OFF(th) (((th)->th_offx2 & 0xf0) >> 4)
  u_char th_flags;
#define TH_FIN 0x01
#define TH_SYN 0x02
#define TH_RST 0x04
#define TH_PUSH 0x08
#define TH_ACK 0x10
#define TH_URG 0x20
#define TH_ECE 0x40
#define TH_CWR 0x80
#define TH_FLAGS (TH_FIN | TH_SYN | TH_RST | TH_ACK | TH_URG | TH_ECE | TH_CWR)
  u_short th_win; /* window */
  u_short th_sum; /* checksum */
  u_short th_urp; /* urgent pointer */
} TCP_header;


/* UDP header */
typedef struct {
    u_short src_port;        /* source port, 2 bytes */
    u_short dst_port;        /* dest port, 2 bytes */
    u_short length;          /* length of data packet，2 bytes */
    u_short check_sum;       /* check sum, 2 bytes */
} UDP_header;


/* ICMP header */
typedef struct {
    u_char type;             /* type, 1 byte */ 
    u_char code;             /* code, 1 byte */
    u_short check_sum;       /* check sum, 2 bytes */
    uint32_t rst_of_header;  /* Rest of header, 4 bytes */
} ICMP_header;

/* IGMP header */
typedef struct {
  u_int version: 4;          /* version, 4 bits */
  u_int type: 4;             /* type, 4 bits */
  uint8_t unused;            /* Unused part, 1 byte */
  u_short check_sum;         /* check sum, 2 bytes */
} IGMP_header;


/* ARP header */
typedef struct {
    u_short hard_type;       /* hardware type, 2 bytes */
    u_short pro_type;        /* protocal type, 2 bytes */
    u_char hard_adr_len;     /* hardware address len, 1 byte */
    u_char pro_adr_len;      /* protocal address len, 1 byte */
    u_short oper_type;       /* operation type, 2 bytes,1 for request, 2 for response */
    u_char src_mac[6];       /* MAC for source, 6 bytes */
    u_char src_ip[4];        /* IP for source, 4 bytes */
    u_char dest_mac[6];      /* MAC for dest, 6 bytes */
    u_char dest_ip[4];       /* IP for dest, 4 bytes */
} ARP_header;

/* data_packet */
typedef struct{
    char type[8];            /* packet type */
    int time[6];             /* time */
    int len;                 /* length */
    ethernet_header *ethh;   /* Ethernet header */
    ARP_header *arph;        /* ARP header */
    IPv4_header *ip4h;       /* IPv4 header */
    IPv6_header *ip6h;       /* IPv6 header */
    ICMP_header *icmph;      /* ICMP header */
    UDP_header *udph;        /* UDP header */
    TCP_header *tcph;        /* TCP header */
    void *apph;              /* Application layer packet header */
} data_packet;
#endif // HEADER_H