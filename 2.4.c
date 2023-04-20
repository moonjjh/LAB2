#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void enterName(int childNum)
{
    char name[50];
    printf("\nPlease enter the name for child %d:  ", childNum);
    scanf("%s", name);
    printf("The name for child process %d is %s \n", childNum, name);
}

int main()
{
   for (int i = 1; i < 5; i++) // Create 4 child  process
   {  
      pid_t pid = fork();
   
      if (pid == 0) // Check if its a child process
      {
         enterName(i);
         exit(0); 
      }
      else if (pid > 0) // Check if its a parent process
         wait(NULL);
    }
    
    printf("\nJob is done\n");

    return 0;
}
