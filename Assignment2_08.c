#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
  int i,ret1,ret2,ret3,ret4,ret5,s1,s2,s3,s4,s5;
  ret1=fork();
  if(ret1==0)
  {
   ret2=fork();
   if(ret2==0)
   {
     ret3=fork();
	  if(ret3==0)
	  {
       ret4=fork();
	    if(ret4==0)
		{
          ret5=fork();
		   if(ret5==0)
		   {
		     //child 5 process
             for(i=1;i<=5;i++)
			 {
               printf("child5:%d\n",i);
			   sleep(1);
			 }
			 _exit(0);
		   }

		   //child 4 process
		   waitpid(ret5,&s5,0);
		   for(i=0;i<=5;i++)
		   {
            printf("child4:%d\n",i);
			sleep(1);
		   }
		   _exit(0);
		  }
          
		  //child 3 process
		  waitpid(ret4,&s4,0);
		  for(i=1;i<=5;i++)
		  {
           printf("child3:%d\n",i);
		   sleep(1);
		  }
		  _exit(0);
	     }
        

		 //child 2 process
		 waitpid(ret3,&s3,0);
		 for(i=1;i<=5;i++)
		 {
           printf("child2:%d\n",i);
		   sleep(1);
		 }
		 _exit(0);
        }
      

	     //child 1 process
		 waitpid(ret2,&s2,0);
		 for(i=1;i<=5;i++)
		 {
          printf("child1:%d\n",i);
		  sleep(1);
		 }
		 _exit(0);
        }

      waitpid(ret1,&s1,0);




  }





