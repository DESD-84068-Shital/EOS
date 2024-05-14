#include<stdio.h>
#include<signal.h>
#include<sys/wait.h>
#include<string.h>

int main()
{
   int ret,signum,pid;
   printf("Enter signal_number and process_id\n");
   scanf("%d %d",&signum,&pid);

   ret=kill(pid,signum);
   
   if(ret==0)
   {
    printf("killed");
   }

   else
   {
     perror("failed");
	 _exit(1);
   }
 
return 0;
}
