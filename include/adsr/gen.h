// libadsr Copyright (C) Travis Whitaker Stephen Demos 2013

#ifndef ADSR_GEN_H
#define ADSR_GEN_H

typedef struct
{
	mpfr_t freq;
	mpfr_t (*gen_handler)(*adsr_gen_t);
	void *opt;
	void *mod_next;
	gen_t *gen_next;
} adsr_gen_t;

mpfr_t adsr_gen_square(adsr_gen_t gen);
mpfr_t adsr_gen_triangle(adsr_gen_t gen);
mpfr_t adsr_gen_sawtooth(adsr_gen_t gen);
mpfr_t adsr_gen_sine(adsr_gen_t gen);
mpfr_t adsr_gen_noise(adsr_gen_t gen);
mpfr_t adsr_gen_custom_register(adsr_gen_t gen);
mpfr_t adsr_gen_custom_function(adsr_gen_t gen);

#endif
