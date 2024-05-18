//3. Find the size of pipe buﬀer in your system.

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

int arr[2];
void sigint_handler(int sig)
{
   close(arr[1]);
   close(arr[0]);
   _exit(0);
}

int main()
{
  char ch='A';
  int ret;
  struct sigaction sa;
  memset(&sa, 0, sizeof(struct sigaction));
  sa.sa_handler = sigint_handler;
  ret= sigaction(SIGINT, &sa, NULL);

 ret=pipe(arr);
  int count=0;

  while(1)
  {
    write(arr[1], &ch, 1);
	count++;
	printf("bytes written: %d\n",count);

  }
 return 0;

}