CC=gcc
CXX=g++
CFLAGS=-Wall -Werror -g

TARGETS= procmaps

All: $(TARGETS)

procmaps: procmaps.o
	$(CXX) $(CFLAGS) -o $@ $<

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $<

clean:
	rm -f *.o

distclean: clean
	rm -f $(TARGETS)
