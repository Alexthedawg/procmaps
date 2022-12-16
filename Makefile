CC=gcc
CXX=g++
CFLAGS=-Wall -Werror -g

TARGETS= procmaps

All: $(TARGETS)

procmaps: procmaps.o
	$(CC) $(CFLAGS) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o

distclean: clean
	rm -f $(TARGETS)
