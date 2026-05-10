/*
	By CasTolax 2026
*/

#include <stdint.h>
#include <stdio.h>

#ifndef WRITE_CACHE
#define WRITE_CACHE

#define WRITE_CACHE_FALSE // yazdırılmayacak ise hayır
#define WRITE_CACHE_TRUE  // yazdırılacak ise evet

void write_cache(CACHE_SIZE);

#endif