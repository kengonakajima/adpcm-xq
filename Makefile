all: test

test: hoge.cpp adpcm-lib.o
	g++ -O3 hoge.cpp adpcm-lib.o -o test
adpcm-lib.o: adpcm-lib.c
	g++ -O3 -g -c adpcm-lib.c

clean:
	rm *.o test


