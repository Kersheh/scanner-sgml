# Makefile for SGML scanner using flex

CC = gcc
OBJS = lex.yy.o util.o stack.o main.o

scanner: $(OBJS)
	$(CC) $(OBJS) -o scanner -ll

main.o: main.c globals.h util.h scan.h
	$(CC) -c main.c

stack.o: stack.c stack.h
	$(CC) -c stack.c

util.o: util.c util.h globals.h
	$(CC) -c util.c

lex.yy.c: sgml.lex
	flex sgml.lex

lex.yy.o: lex.yy.c globals.h util.h
	$(CC) -c lex.yy.c

clean:
	rm -f scanner $(OBJS) lex.yy.c sample.out

test:
	@echo "TEST 1 -----------------------------------------------"
	@./scanner < data/test1.txt
	@echo "TEST 2 -----------------------------------------------"
	@./scanner < data/test2.txt
	@echo "TEST 3 -----------------------------------------------"
	@./scanner < data/test3.txt

run:
	@./scanner < data/newsdata.txt

run_out:
	@echo "Output printed to sample.out"
	@./scanner < data/newsdata.txt > sample.out