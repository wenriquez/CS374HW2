#ifndef FIFODEFS_H
#define FIFODEFS_H


extern char *FIFO_FILE1;
extern char *FIFO_FILE2;

void makeFIFOS(void);
void *readFIFO(void *FIFOname);
void *writeFIFO(void *FIFOname);

#endif // FIFODEFS_H

