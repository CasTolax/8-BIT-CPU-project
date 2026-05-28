/*
	By CasTolax 2026

	burada işlemcinin sınırını korumaya yönelik 
	kodlar bulunacaktır.

	işlemci de bellek boyutu, önbellek boyutu, işlem sınırıları
	ve bir çok hata yönetimi burada olucak. eğer ki aşılan 3'den 
	fazla işlem olursa ekrana panic vericek ve sistem kendini durdurucaktır.
*/

#include <stdint.h>
#include <stdio.h>

#ifndef PANIC_H
#define PANIC_H

/*
	Burada özellikle herhangi birisinin sınırı aşılır ise,
	otomatik olarak kapanacak ve sistemin durumuna göre
	ya yeniden başlatıcak yada kısa süreliğine durdurucaktır.
	aslında bu scheduler mantığına benziyor ancak bu olmadan 
	scheduler yapmayı düşünmüyorum.
*/
typedef struct 
{
	uint8_t RAM_HANDLING;
	uint8_t CACHE_HANDLING;
	uint8_t ALU_HANDLING;
	uint8_t INTERRUPTS_HANDLING;

}panic_datas_cpu_t;


uint8_t sys_control_handling(void);

#endif