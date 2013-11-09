// libadsr Copyright (C) Travis Whitaker Stephen Demos 2013

#ifndef ADSR_MUX_ALSA_H
#define ADSR_MUX_ALSA_H

#ifndef ADSR_MUX_H
#include <adsr/mux.h>
#endif

typedef struct
{
	unsigned char bit_depth;
	unsigned char sample_rate;
	unsigned int sample_buffer_size;
	short *sample_buffer;
	adsr_gen_t *init_gen;
	mpfr_t *tick;
	mpfr_t *tick_inc;
} adsr_mux_alsa_t;

adsr_mux_alsa_t *adsr_mux_alsa_init(unsigned char bit_depth, unsigned char sample_rate, adsr_gen_t *init_gen, mdfr *tick, unsigned int sample_buffer_size, short *samble_buffer);
void adsr_mux_alsa(unsigned int samples, adsr_mux_alsa_t *mux);

#endif
