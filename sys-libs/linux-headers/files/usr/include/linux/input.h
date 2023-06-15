#ifndef LINUX_INPUT_H
#define LINUX_INPUT_H

#include <stdint.h>
#include <linux/input-event-codes.h>

struct ff_trigger {
	uint16_t button;
	uint16_t interval;
};

struct ff_replay {
	uint16_t length;
	uint16_t delay;
};

struct ff_envelope {
	uint16_t attack_length;
	uint16_t attack_level;
	uint16_t fade_length;
	uint16_t fade_level;
};

struct ff_constant_effect {
	int16_t level;
	struct ff_envelope envelope;
};

struct ff_ramp_effect {
	int16_t start_level;
	int16_t end_level;
	struct ff_envelope envelope;
};

struct ff_periodic_effect {
	uint16_t waveform;
	uint16_t period;
	int16_t magnitude;
	int16_t offset;
	uint16_t phase;

	struct ff_envelope envelope;

	uint32_t custom_len;
	int16_t *custom_data;
};

struct ff_condition_effect {
	uint16_t right_saturation;
	uint16_t left_saturation;
	int16_t right_coeff;
	int16_t left_coeff;
	uint16_t deadband;
	int16_t center;
};

struct ff_rumble_effect {
	uint16_t strong_magnitude;
	uint16_t weak_magnitude;
};

struct ff_effect {
	uint16_t type;
	int16_t id;
	uint16_t direction;
	struct ff_trigger trigger;
	struct ff_replay replay;

	union {
		struct ff_constant_effect constant;
		struct ff_ramp_effect ramp;
		struct ff_periodic_effect periodic;
		struct ff_condition_effect condition[2];
		struct ff_rumble_effect rumble;
	} u;
};

struct input_absinfo {
	int32_t value;
	int32_t minimum;
	int32_t maximum;
	int32_t fuzz;
	int32_t flat;
	int32_t resolution;
};

struct input_id {
	uint16_t bustype;
	uint16_t vendor;
	uint16_t product;
	uint16_t version;
};

#define EVIOCGABS(abs) _IOR('E', 0x40 + (abs), struct input_absinfo)
#define EVIOCGBIT(ev,len) _IOC(_IOC_READ, 'E', 0x20 + (ev), len)
#define EVIOCGEFFECTS _IOR('E', 0x84, int)
#define EVIOCGID _IOR('E', 0x02, struct input_id)
#define EVIOCGKEY(len) _IOC(_IOC_READ, 'E', 0x18, len)
#define EVIOCGKEYCODE _IOR('E', 0x04, unsigned int[2])
#define EVIOCGLED(len) _IOC(_IOC_READ, 'E', 0x19, len)
#define EVIOCGNAME(len) _IOC(_IOC_READ, 'E', 0x06, len)
#define EVIOCGPHYS(len) _IOC(_IOC_READ, 'E', 0x07, len)
#define EVIOCGRAB _IOW('E', 0x90, int)
#define EVIOCGREP _IOR('E', 0x03, unsigned int[2])
#define EVIOCGSND(len) _IOC(_IOC_READ, 'E', 0x1a, len)
#define EVIOCGUNIQ(len) _IOC(_IOC_READ, 'E', 0x08, len)
#define EVIOCGVERSION _IOR('E', 0x01, int)
#define EVIOCRMFF _IOW('E', 0x81, int)
#define EVIOCSABS(abs) _IOW('E', 0xc0 + (abs), struct input_absinfo)
#define EVIOCGSW(len) _IOC(_IOC_READ, 'E', 0x1b, len)
#define EVIOCSFF _IOW('E', 0x80, struct ff_effect)
#define EVIOCSKEYCODE _IOW('E', 0x04, unsigned int[2])
#define EVIOCSREP _IOW('E', 0x03, unsigned int[2])

#endif
