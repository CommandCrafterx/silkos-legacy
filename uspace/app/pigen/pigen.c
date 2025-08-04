/*
 * Copyright (c) 2025 CommandCrafterx
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - The name of the author may not be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/** @addtogroup pigen
 * @file
 * @brief PI Generator using Nilakantha series.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	long long iterations;
	double pi = 3.0;
	int sgn = 1;

	// Check if the user provided the number of iterations
	if (argc < 2) {
		printf("Usage: pigen <number_of_iterations>\n");
		return 1;
	}

	// Convert the argument to an integer
	iterations = atoll(argv[1]);

	printf("Calculating PI with %lld iterations...\n", iterations);

	// Use the Nilakantha series to calculate PI
	for (long long i = 0; i < iterations; i++) {
		long long d1 = 2 * (i + 1);
		long long d2 = d1 + 1;
		long long d3 = d1 + 2;
		pi += sgn * (4.0 / (d1 * d2 * d3));
		sgn *= -1;
	}

	printf("PI is approximately: %.15f\n", pi);

	return 0;
}
