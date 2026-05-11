/*
	By CasTolax 2026
*/

#include <stdint.h>
#include <stdio.h>

#ifndef WRITE_CACHE
#define WRITE_CACHE

#define WRITE_CACHE_FALSE // 0 yazdırılmayacak ise hayır
#define WRITE_CACHE_TRUE  // 1 yazdırılacak ise evet

#define CACHE_SIZE	64 // size of cache(64kb)

void write_cache(int write_process);

#endif
