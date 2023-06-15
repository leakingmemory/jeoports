#ifndef LINUX_CDROM_H
#define LINUX_CDROM_H

#include <stdint.h>

struct cdrom_msf {
	uint8_t cdmsf_min0;
	uint8_t cdmsf_sec0;
	uint8_t cdmsf_frame0;
	uint8_t cdmsf_min1;
	uint8_t cdmsf_sec1;
	uint8_t cdmsf_frame1;
};

union cdrom_addr {
	struct cdrom_msf msf;
	int lba;
};

struct cdrom_multisession {
	union cdrom_addr addr;
	uint8_t xa_flag;
	uint8_t addr_format;
};

struct cdrom_read_audio {
	union cdrom_addr addr;
	uint8_t addr_format;
	int nframes;
	uint8_t *buf;
};

struct cdrom_subchnl {
	uint8_t cdsc_format;
	uint8_t cdsc_audiostatus;
	uint8_t cdsc_adr : 4;
	uint8_t cdsc_ctrl : 4;
	uint8_t cdsc_trk;
	uint8_t cdsc_ind;
	union cdrom_addr cdsc_absaddr;
	union cdrom_addr cdsc_reladdr;
};

struct cdrom_ti {
	uint8_t cdti_trk0;
	uint8_t cdti_ind0;
	uint8_t cdti_trk1;
	uint8_t cdti_ind1;
};

struct cdrom_tocentry {
	uint8_t cdte_track;
	uint8_t cdte_adr : 4;
	uint8_t cdte_ctrl : 4;
	uint8_t cdte_format;
	union cdrom_addr cdte_addr;
	uint8_t cdte_datamode;
};

struct cdrom_tochdr {
	uint8_t cdth_trk0;
	uint8_t cdth_trk1;
};

struct cdrom_volctrl {
	uint8_t channel0;
	uint8_t channel1;
	uint8_t channel2;
	uint8_t channel3;
};

#define CDROMAUDIOBUFSIZ 0x5382
#define CDROMEJECT 0x5309
#define CDROMEJECT_SW 0x530f
#define CDROMMULTISESSION 0x5310
#define CDROMPAUSE 0x5301
#define CDROMPLAYMSF 0x5303
#define CDROMPLAYTRKIND 0x5304
#define CDROMREADAUDIO 0x530e
#define CDROMREADCOOKED 0x5315
#define CDROMREADMODE1 0x530d
#define CDROMREADMODE2 0x530c
#define CDROMREADRAW 0x5314
#define CDROMREADTOCENTRY 0x5306
#define CDROMREADTOCHDR 0x5305
#define CDROMRESET 0x5312
#define CDROMRESUME 0x5302
#define CDROMSEEK 0x5316
#define CDROMSTART 0x5308
#define CDROMSTOP 0x5307
#define CDROMSUBCHNL 0x530b
#define CDROMVOLCTRL 0x530a
#define CDROMVOLREAD 0x5313
#define CDROM_GET_MCN 0x5311
#define CDROM_GET_UPC CDROM_GET_MCN

#endif
