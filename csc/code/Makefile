all: fibo

fibo: main.o fibo.o
	gcc  main.o fibo.o -c

main.o: main.c
	gcc main.c -c  -I/home/jovyan/work/77066004-lab/csc/include

fibo.o: fibo.c
	gcc fibo.c -c  -I/home/jovyan/work/77066004-lab/csc/include

clean:
	rm -rf *.o
