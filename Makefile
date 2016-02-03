#
# Makefile for SGML scanner using flex
#

CC = gcc
CFLAGS = 
OBJS = lex.yy.o util.o main.o

scanner: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o scanner -ll

main.o: main.c globals.h util.h scan.h
	$(CC) $(CFLAGS) -c main.c

util.o: util.c util.h globals.h
	$(CC) $(CFLAGS) -c util.c

lex.yy.c: sgml.l
	flex sgml.l

lex.yy.o: lex.yy.c globals.h util.h
	$(CC) $(CFLAGS) -c lex.yy.c

clean:
	rm -f scanner $(OBJS) lex.yy.c
