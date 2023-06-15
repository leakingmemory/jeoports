#ifndef LINUX_HDREG_H
#define LINUX_HDREG_H

#include <stdint.h>

struct hd_driveid {
	unsigned short config;
	unsigned short cyls;
	unsigned short reserved2;
	unsigned short heads;
	unsigned short track_bytes;
	unsigned short sector_bytes;
	unsigned short sectors;
	unsigned short vendor0;
	unsigned short vendor1;
	unsigned short vendor2;
	unsigned char serial_no[20];
	unsigned short buf_type;
	unsigned short buf_size;
	unsigned short ecc_bytes;
	unsigned char fw_rev[8];
	unsigned char model[40];
	unsigned char max_multsect;
	unsigned char vendor3;
	unsigned short dword_io;
	unsigned char vendor4;
	unsigned char capability;
	unsigned short reserved50;
	unsigned char vendor5;
	unsigned char tPIO;
	unsigned char vendor6;
	unsigned char tDMA;
	unsigned short field_valid;
	unsigned short cur_cyls;
	unsigned short cur_heads;
	unsigned short cur_sectors;
	unsigned short cur_capacity0;
	unsigned short cur_capacity1;
	unsigned short multsect;
	unsigned short multsect_valid;
	unsigned int lba_capacity;
	unsigned short dma_1word;
	unsigned short dma_mword;
	unsigned short eide_pio_modes;
	unsigned short eide_dma_min;
	unsigned short eide_dma_time;
	unsigned short eide_pio;
	unsigned short eide_pio_iordy;
	unsigned short words69_70[2];
	unsigned short words71_74[4];
	unsigned short queue_depth;
	unsigned short words76_79[4];
	unsigned short major_rev_num;
	unsigned short minor_rev_num;
	unsigned short command_set_1;
	unsigned short command_set_2;
	unsigned short cfsse;
	unsigned short cfs_enable_1;
	unsigned short cfs_enable_2;
	unsigned short csf_default;
	unsigned short dma_ultra;
	unsigned short trseuc;
	unsigned short trsEuc;
	unsigned short CurAPMvalues;
	unsigned short mprc;
	unsigned short hw_config;
	unsigned short acoustic;
	unsigned short msrqs;
	unsigned short sxfert;
	unsigned short sal;
	unsigned int spg;
	unsigned long long lba_capacity_2;
	unsigned short words104_125[22];
	unsigned short last_lun;
	unsigned short word127;
	unsigned short dlf;
	unsigned short csfo;
	unsigned short words130_155[26];
	unsigned short word156;
	unsigned short word157_159[3];
	unsigned short cfa_power;
	unsigned short words161_175[15];
	unsigned short words176_205[30];
	unsigned short words206_254[49];
	unsigned short integrity_word;
};

struct hd_geometry {
	unsigned char heads;
	unsigned char sectors;
	unsigned short cylinders;
	unsigned long start;
};

#define HDIO_DRIVE_CMD 0x031f
#define HDIO_GET_32BIT 0x0309
#define HDIO_GET_DMA 0x030b
#define HDIO_GET_IDENTITY 0x030d
#define HDIO_GET_KEEPSETTINGS 0x0308
#define HDIO_GET_MULTCOUNT 0x0304
#define HDIO_GET_NOWERR 0x030a
#define HDIO_GET_UNMASKINTR 0x0302
#define HDIO_SET_32BIT 0x0324
#define HDIO_SET_DMA 0x0326
#define HDIO_SET_KEEPSETTINGS 0x0323
#define HDIO_GET_KEEPSETTINGS 0x0308
#define HDIO_SET_MULTCOUNT 0x0321
#define HDIO_SET_NOWERR 0x0325
#define HDIO_SET_UNMASKINTR 0x0322
#define HDIO_GET_UNMASKINTR 0x0302
#define HDIO_GETGEO 0x0301


#endif
