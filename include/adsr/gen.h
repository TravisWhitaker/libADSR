// libadsr Copyright (C) Travis Whitaker Stephen Demos 2013

#ifndef ADSR_GENERATOR_H
#define ADSR_GENERATOR_H

typedef struct
{
	mpfr_t freq;
	mpfr_t (*gen_handler)(gen_t);
	void *opt;
	void *mod_next;
	gen_t *gen_next;
} gen_t;

mpfr_t gen_square(gen_t gen);
mpfr_t gen_triangle(gen_t gen);
mpfr_t gen_sawtooth(gen_t gen);
mpfr_t gen_sine(gen_t gen);
mpfr_t gen_custom_register(gen_t gen);
mpfr_t gen_custom_function(gen_t gen);

#endif
