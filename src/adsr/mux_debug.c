// libadsr Copyright (C) Travis Whitaker Stephen Demos 2013

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <mpfr.h>

#include <adsr/debug.h>
#include <adsr/gen.h>
#include <adsr/mux_debug.h>

adsr_mux_debug_t *adsr_mux_debug_init(unsigned char bit_depth, unsigned int sample_rate, adsr_gen_t *init_gen, mpfr_t *tick, unsigned int sample_buffer_size, short *sample_buffer)
{
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
