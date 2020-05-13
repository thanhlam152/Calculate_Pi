#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 10

int inCir = 0;

void *runner(void* param) {
	int i, cnt = 0, temp = rand();
	for (i = 0; i < (int)param; ++i) {
		double x = 2*(double)rand_r(&temp)/RAND_MAX - 1;
        	double y = 2*(double)rand_r(&temp)/RAND_MAX - 1;
        	if (x*x + y*y <= 1) cnt++;
	}
	inCir += cnt;
}

double pi_multi_thread(int N) {
	pthread_t tid[NUM_THREADS];
	int i;
	for (i = 0; i < N % NUM_THREADS; ++i) {
		pthread_create(&tid[i], NULL, runner, (void*)(N / NUM_THREADS + 1));
	}
	for (; i < NUM_THREADS; ++i) {
		pthread_create(&tid[i], NULL, runner, (void*)(N / NUM_THREADS));
	}
	for (i = 0; i < NUM_THREADS; ++i) {	
		pthread_join(tid[i], NULL);
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
		printf("pi = %lf\n", pi_multi_thread(atoi(argv[1])));		
	}
	return 0;
}



