#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "fifodefs.h"

void run(void);
void *LoopRead(void *FIFOname);
void *LoopWrite(void *FIFOname);

int main()
{
    
    run();
  
    //makeFIFOS();

    //while(1)
        //{
            //readFIFO(FIFO_FILE1);
            

        //}

        //remove(FIFO_FILE1);

    pthread_exit(NULL);
    return 0;
}

void run(void)
{
  
   pthread_t read;
   pthread_t write;
 

   pthread_create(&read, NULL,LoopRead, (void *)FIFO_FILE1);
   pthread_create(&write, NULL,LoopWrite, (void *)FIFO_FILE2);  


}

void *LoopRead(void *FIFOname)
{
    while(1){

    readFIFO(FIFOname);

    }

}

void *LoopWrite(void *FIFOname)
{
    while(1){

    writeFIFO(FIFOname);

    }

}
