#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

// Function to check if number is a prime number
bool is_prime(int n) {
    	if (n <= 1) return false;
    	for (int i = 2; i * i <= n; ++i)
        	if (n % i == 0)
            	return false;
    	return true;
}

int main() {
	// Initilizing pids
    	pid_t pid1, pid2, pid3;
	
	// First pid child
    	pid1 = fork();
	// Check if pid is equal to 0
    	if (pid1 == 0) {
        	int sum = 0;
		// Calculate sum of evens
        	for (int i = 2; i <= 1000; i += 2)
            		sum += i;
		// Print results
        	printf("Child 1 (Even sum): %d\n", sum);
        	printf("DONE. MY PID IS %d. MY PARENT’S PID IS %d.\n", getpid(), getppid());
        	// Exit child
		exit(0);
    	}

	// Second pid child
    	pid2 = fork();
	// Check if pid is equal to 0
    	if (pid2 == 0) {
        	int sum = 0;
		// Calculate sum of odds
        	for (int i = 1; i <= 1000; i += 2)
            		sum += i;
		// Prints results
        	printf("Child 2 (Odd sum): %d\n", sum);
        	printf("DONE. MY PID IS %d. MY PARENT’S PID IS %d.\n", getpid(), getppid());
        	// Exit child
		exit(0);
    	}

	// Third pid child
    	pid3 = fork();
	// Check if pid is equal to 0
    	if (pid3 == 0) {
        	printf("Child 3 (Primes between 1 and 1000):\n");
		// Loop through 1 - 1000
        	for (int i = 1; i <= 1000; ++i)
			// Check if i is a prime
            		if (is_prime(i))
				// print the i value if it is a prime
                		printf("%d ", i);
		// Print results
        	printf("\nDONE. MY PID IS %d. MY PARENT’S PID IS %d.\n", getpid(), getppid());
        	// Exit child
		exit(0);
    	}
	
	// Wait for children to stop
    	for (int i = 0; i < 3; i++) {
        	wait(NULL);
    	}
	
	// Print parents results
    	printf("Parent DONE. MY PID IS %d. MY PARENT’S PID IS %d.\n", getpid(), getppid());
    	
	return 0;
}

