#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fifodefs.h>

int void main()
{
    int pass = runTests();

    if(pass == 0){

      printf("Tests passed");
     }
     else{
 
       printf("Tests didn't pass");
     }
   
}



int TestreadLine(void) {
         
         //need to test if the exit condition will work
	 
          char temp[8] = "_exit_"; 
            
          // tests the custom method to read input from STDIN
          
          char* line = readLine();
        
          return strncmp(temp,line, compareLimit); // should be 0
}

int runTests() {

    int passCount = 0;

    passCount += TestreadLine();

    return passCount;
}
