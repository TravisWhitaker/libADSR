// libadsr Copyright (C) Travis Whitaker Stephen Demos 2013

#ifndef ADSR_MUX_RAW_H
#define ADSR_MUX_RAW_H

#ifndef ADSR_MUX_H
#include <adsr/mux.h>
#endif

typedef struct
{
	unsigned char bit_depth;
	unsigned char sample_rate;
	unsigned int sample_buffer_size;
	short *sample_buffer;
	adsr_gen_t *gen_root;
	mpfr_t *tick;
	mpfr_t *tick_inc;
	mpfr_t *tmp;
} adsr_mux_raw_t;

adsr_mux_raw_t *adsr_mux_raw_init(unsigned char bit_depth, unsigned char sample_rate, adsr_gen_t *init_gen, mdfr *tick, unsigned int sample_buffer_size, short *samble_buffer);
void adsr_mux_raw(unsigned int samples, adsr_mux_raw_t *mux);

#endif
