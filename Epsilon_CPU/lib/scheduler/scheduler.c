/*
    By CasTolax 2026
*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "scheduler.h"

/*
    1* Process listesini al

    2* Quantum belirle

    3* İlk processi çalıştır

    4* Quantum kadar çalıştır

      5*İş bitti mi?
        Evet → listeden çıkar
        Hayır → kuyruğun sonuna ekle

    6*Sıradaki processi çalıştır
    
    7*Liste boşalana kadar devam et
    
*/

void run_scheduler(Process p[])
{    

    int finished = 0;

    // bitene kadar döngüye devam et
    while(finished < PROCESS_COUNT)
    {   
        // iş parçacıklarında gezin
        for(int i = 0; i<PROCESS_COUNT; i++)
        {
            p[i]++;
            printf("process = %d\n",p[i]);
        }
    }

}
