#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "fifodefs.h"

int compareLimit = 100;

char *FIFO_FILE1 = "FIFO1";
char *FIFO_FILE2 = "FIFO2";

char readbuf[4096];
int readLimit = 4096;

char* readLine(void);
void makeFIFOS(void);
void *readFIFO(void *FIFOname);
void *writeFIFO(void *FIFOname);


char * readLine(void) {
    char * line = malloc(100), * linep = line;
    size_t lenmax = 100, len = lenmax;
    int c;
    int curSize = 0;

    if(line == NULL)
        return NULL;

    for(;;) {
        c = fgetc(stdin);
        curSize++;

        if(curSize == 4094)
        {
            break;
        }

        if(c == EOF || c == '\n')
            break;

        if(--len == 0) {
            len = lenmax;
            char * linen = realloc(linep, lenmax *= 2);

            if(linen == NULL) {
                free(linep);
                return NULL;
            }
            line = linen + (line - linep);
            linep = linen;
        }

        if((*line++ = c) == '\n')
            break;
    }
    *line = '\0';
    return linep;
}

void makeFIFOS(void)
{

        /* Create the FIFOS if they do not exist */


            
              
            umask(0);
             mknod(FIFO_FILE1, S_IFIFO|0666, 0);


             umask(0);
             mknod(FIFO_FILE2, S_IFIFO|0666, 0);


}


void *readFIFO(void *FIFOname)
{
   char temp[8] = "_exit_";
    FILE *fp;
    fp = fopen(FIFOname, "r");
    
    fgets(readbuf,readLimit,fp);

   
    int result = strncmp(temp,readbuf, compareLimit);

    if(result == 0)
    {
      exit(0);
    }
    
    printf("\n%s%s\n","[reply]",readbuf);
    fflush(fp);
    fflush(stdout);
    //printf("[send]:");
    fclose(fp);
    
}

void *writeFIFO(void *FIFOname)
{
   char temp[8] = "_exit_";
    fflush(stdout);
    //printf("[send]:");
    char* line = readLine();
     
    
    int result = strncmp(temp,line, compareLimit);

    if(result == 0)
    {
      exit(0);
    }
   
    FILE *fp;
    fp = fopen(FIFOname, "w");
    fputs(line, fp);
    //printf(readbuf);
    fflush(fp);
    fclose(fp);
    free(line);
    
}








