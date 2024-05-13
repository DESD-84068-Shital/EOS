#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
   int i, ret1,ret2,ret3,ret4,ret5,s,child_pid;
   ret1=fork();
     if(ret1==0)
   {
     //first child process
      for(i=1;i<=5;i++){
         printf("child1:%d\n ",i);
		 printf("child1: pid:%d\n",getpid());
		sleep(1);
	 }
	 _exit(0);
   }

   ret2=fork();
     if(ret2==0)
      {
       //second child process
	   for(i=1;i<=5;i++){
	   printf("child2:%d\n",i);
	   printf("child2: pid:%d\n",getpid());
	   sleep(1); 
	  }
	  _exit(0);
   }

   ret3=fork();
     if(ret3==0)
    {
      //second child process
         for(i=1;i<=5;i++){
         printf("child3:%d\n",i);
         printf("child3: pid:%d\n",getpid());
         sleep(1);
     }
       _exit(0);
   }
 
  ret4=fork();
    // printf("fork2():%d\n",ret2);
     if(ret2==0)
     {
         //second child process
         for(i=1;i<=5;i++){
         printf("child4:%d\n",i);
         printf("child4: pid:%d\n",getpid());
         sleep(1);
        }
        _exit(0);
     }

  ret5=fork();
    // printf("fork2():%d\n",ret2);
     if(ret5==0)
     {
         //second child process
         for(i=1;i<=5;i++){
         printf("child5:%d\n",i);
         printf("child5: pid:%d\n",getpid());
         sleep(1);
        }
        _exit(0);
     }

  for( i=1;i<=2;i++)
  {
    child_pid=wait(&s);
  }

  
return 0;

}
