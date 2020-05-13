all: 
	make pi_serial
	make pi_multi-thread
	make code
pi_serial: pi_serial.o
	gcc pi_serial.o -o pi_serial

pi_serial.o: pi_serial.c
	gcc -c pi_serial.c

pi_multi-thread: pi_multi-thread.o
	gcc pi_multi-thread.o -o pi_multi-thread -lpthread 

pi_multi-thread.o: pi_multi-thread.c
	gcc -c pi_multi-thread.c -lpthread 

code: code.o
	gcc code.c -o code -lpthread

code.o: code.c
	gcc -c code.c -lpthread
clean:
	rm -f *.o pi_serial pi_multi-thread code
