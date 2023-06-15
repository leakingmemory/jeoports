#ifndef LINUX_FD_H
#define LINUX_FD_H

#include <stdint.h>

struct floppy_struct {
	unsigned int size, sect, head, track, stretch;
	unsigned char gap, rate, spec1, fmt_gap;
	const char *name;
};

struct floppy_max_errors {
	unsigned int abort, read_track, reset, recal, reporting;
};

#define FD_AUTODETECT_SIZE 8

struct floppy_drive_params {
	signed char cmos;
	unsigned long max_dtr;
	unsigned long hlt;
	unsigned long hut;
	unsigned long srt;
	unsigned long spinup;
	unsigned long spindown;
	unsigned char spindown_offset;
	unsigned char select_delay;
	unsigned char rps;
	unsigned char tracks;
	unsigned long timeout;
	unsigned char interleave_sect;
	struct floppy_max_errors max_errors;
	char flags;
	char read_track;
	short autodetect[FD_AUTODETECT_SIZE];
	int checkfreq;
	int native_format;
};

struct floppy_drive_struct {
	unsigned long flags;
	unsigned long spinup_date;
	unsigned long select_date;
	unsigned long first_read_date;
	short probed_format;
	short track;
	short maxblock;
	short maxtrack;
	int generation;
	int keep_data;
	int fd_ref;
	int fd_device;
	unsigned long last_checked;
	char *dmabuf;
	int bufblocks;
};

struct floppy_fdc_state {
	int spec1;
	int spec2;
	int dtr;
	unsigned char version;
	unsigned char dor;
	unsigned long address;
	unsigned int rawcmd : 2;
	unsigned int reset : 1;
	unsigned int need_configure : 1;
	unsigned int perp_mode : 2;
	unsigned int has_fifo : 1;
	unsigned int driver_version;
	unsigned char track[4];
};

#define FD_RAW_CMD_SIZE (16)
#define FD_RAW_REPLY_SIZE (16)
#define FD_RAW_CMD_FULLSIZE (FD_RAW_CMD_SIZE + FD_RAW_REPLY_SIZE + 1)

struct floppy_raw_cmd {
	unsigned int flags;
	void *data;
	char *kernel_data;
	struct floppy_raw_cmd *next;
	long length;
	long phys_length;
	int buffer_length;
	unsigned char rate;
	unsigned char cmd_count;
	union {
		struct {
			unsigned char cmd[FD_RAW_CMD_SIZE];
			unsigned char reply_count;
			unsigned char reply[FD_RAW_REPLY_SIZE];
		};
		unsigned char fullcmd[FD_RAW_CMD_FULLSIZE];
	};
	int track;
	int resultcode;
	int reserved1;
	int reserved2;
};

struct floppy_write_errors {
	unsigned int write_errors;
	unsigned long first_error_sector;
	int first_error_generation;
	unsigned long last_error_sector;
	int last_error_generation;
	unsigned int badness;
};

struct format_descr {
	unsigned int device, head, track;
};

typedef char floppy_drive_name[16];

#define FDCLRPRM _IO(2, 0x41)
#define FDDEFPRM _IOW(2, 0x43, struct floppy_struct)
#define FDFLUSH _IO(2, 0x4b)
#define FDFMTBEG _IO(2, 0x47)
#define FDFMTTRK _IOW(2, 0x48, struct format_descr)
#define FDGETDRVPRM _IOR(2, 0x11, struct floppy_drive_params)
#define FDGETDRVSTAT _IOR(2, 0x12, struct floppy_drive_struct)
#define FDGETDRVTYP _IOR(2, 0x0f, floppy_drive_name)
#define FDGETFDCSTAT _IOR(2, 0x15, struct floppy_fdc_state)
#define FDGETMAXERRS _IOR(2, 0x0e, struct floppy_max_errors)
#define FDGETPRM _IOR(2, 0x04, struct floppy_struct)
#define FDMSGOFF _IO(2, 0x46)
#define FDMSGON _IO(2, 0x45)
#define FDPOLLDRVSTAT _IOR(2, 0x13, struct floppy_drive_struct)
#define FDRAWCMD _IO(2, 0x58)
#define FDRESET _IO(2, 0x54)
#define FDSETDRVPRM _IOW(2, 0x90, struct floppy_drive_params)
#define FDSETEMSGTRESH _IO(2, 0x4a)
#define FDFMTEND _IO(2, 0x49)
#define FDSETMAXERRS _IOW(2, 0x4c, struct floppy_max_errors)
#define FDSETPRM _IOW(2, 0x42, struct floppy_struct)
#define FDTWADDLE _IO(2, 0x59)
#define FDWERRORCLR _IO(2, 0x56)
#define FDWERRORGET _IOR(2, 0x17, struct floppy_write_errors)


#endif
