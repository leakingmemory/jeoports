#ifndef LINUX_AIO_ABI_H
#define LINUX_AIO_ABI_H

#include <linux/types.h>

typedef __kernel_ulong_t aio_context_t;

#define IOCB_CMD_PREAD (0)
#define IOCB_CMD_PWRITE (1)

#define IOCB_FLAG_RESFD (1)
#define IOCB_FLAG_IOPRIO (2)

struct io_event {
	uint64_t data;
	uint64_t obj;
	int64_t res;
	int64_t res2;
};

struct iocb {
	uint64_t aio_data;
	uint32_t aio_key;
	__kernel_rwf_t aio_rw_flags;
	uint16_t aio_lio_opcode;
	int16_t aio_reqprio;
	uint32_t aio_fildes;
	uint64_t aio_buf;
	uint64_t aio_nbytes;
	int64_t aio_offset;
	uint64_t aio_reserved2;
	uint32_t aio_flags;
	uint32_t aio_resfd;
};

#endif
