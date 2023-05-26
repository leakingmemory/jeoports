#ifndef LINUX_IF_ALG_H
#define LINUX_IF_ALG_H

#define ALG_SET_OP 3
#define ALG_SET_IV 2
#define ALG_SET_KEY 1

struct af_alg_iv {
	uint32_t ivlen;
	uint8_t iv[];
};

struct sockaddr_alg {
	uint16_t salg_family;
	uint8_t salg_type[14];
	uint32_t salg_feat;
	uint32_t salg_mask;
	uint8_t salg_name[64];
};

#endif
