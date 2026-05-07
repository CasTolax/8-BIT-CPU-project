/*
    By CasTolax 2026
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "scheduler.h"

/*
    * sürekli tekrar edicek, eğer tüm işlemler biterse kapanır.
    * eğer işlem var ise -> verilen zaman kadar işle ve sonrakine geç
    * eğer daha bitmeyen işlem varsa -> kuyruğa al
    * eğer işlem işlenmeye hazır ise -> başlat
    * biterse  = TERMINATED yap
    * bitmeyen işlem var ise kontrol et
    * bitir
    * işlemleri tekrar et
    
*/

void run_scheduler(Process p[]){
    //! GEL YAZ DAHA SONRA AÇIKLA

    int finished = 0;

    while(finished < PROCESS_COUNT)
    {

    }
}