#include <stdio.h>
#include <stdlib.h>

int inCir = 0;

double pi_serial(int N) {
	int i, inCir = 0, temp = rand();
	for (i = 0; i < N; ++i) {
		double x = 2*(double)rand_r(&temp)/RAND_MAX - 1;
        	double y = 2*(double)rand_r(&temp)/RAND_MAX - 1;
        	if (x*x + y*y <= 1) inCir++;
	}
	return (double) 4 * inCir/N; 
}


int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Invalid input!\n");
		return -1;
	}
	else if (atoi(argv[1]) <= 0) {
		printf("%d must be > 0\n", atoi(argv[1]));
		return -1;
	}
	else {
		printf("pi = %lf\n", pi_serial(atoi(argv[1])));
	}
	return 0;
}
