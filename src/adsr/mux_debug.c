// libadsr Copyright (C) Travis Whitaker Stephen Demos 2013

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <mpfr.h>

#include <adsr/debug.h>
#include <adsr/gen.h>
#include <adsr/mux_debug.h>

adsr_mux_debug_t *adsr_mux_debug_init(unsigned char init_bit_depth, unsigned int init_sample_rate, adsr_gen_t *init_gen, mpfr_t *init_tick, unsigned int init_sample_buffer_size, short *init_sample_buffer)
{
	adsr_mux_debug_t *output = malloc(sizeof(*output));
	if(output == NULL)
	{
		DEBUG_MSG("malloc failed while allocating adsr_mux_debug_t*");
		errno = ENOMEM;
		return NULL;
	}

	// Populate trivial fields:
	output->bit_depth = init_bit_depth;
	output->sample_rate = init_sample_rate;
	output->gen_root = init_gen;
	output->tick = init_tick;
	output->sample_buffer_size = init_sample_buffer_size;
	output->sample_buffer = init_sample_buffer;

	// Compute the tick increment value:
	mpfr_t *init_tick_inc = malloc(sizeof(mpfr_t));
	mpfr_t freq;
	mpfr_init2(*init_tick_inc, TICK_PREC);
	mpfr_init2(freq, TICK_PREC);
	mpfr_set_ui(freq, output->sample_rate);
	mpfr_ui_div(*init_tick_inc, 1, freq, MPFR_RNDN);

	output->tick_inc = init_tick_inc;
	mpfr_clear(freq);

	return output;
}

void adsr_mux_debug(unsigned int samples, adsr_mux_debug_t *mux)
{
	for(unsigned int i = 0; i < samples; i++)
	{
		//evaluate generator tree
		//scale mpfr_t to -32768/32767 and cast
		//add to buffer
		//increment tick
	}
	//push buffer to stack
}
