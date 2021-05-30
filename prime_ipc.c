#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
	
	int n;
	
	while(1){
		int pipefds[2];
		
		pipe(pipefds);
		
		pid_t pid = fork();
		
		if(pid == 0){
			printf("Enter number to check is prime: ");
			scanf("%d", &n);
			close(pipefds[0]);
			write(pipefds[1], n);
			printf("SENDING NUMBER TO PARENT PROCESS");
			exit(EXIT_SUCCESS);
		}
		
		if(pid > 0){
			wait(NULL);
			for (int c = 2; c <= n/2; c++){
				if (n%c == 0){
					printf("%d is a composite number.\n", n);
					break;
				}
		}

		if(c == n/2 + 1)
			printf("%d is prime.\n" ,n);
	}
	return 0;
}