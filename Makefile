CC = gcc
CFALGS = -Wall -g 
INCLUDE = sighandle.c graphicutils.c calculator.c stack.c
OUT = calculator.out

default: build


build:
	$(CC) $(CFLAGS) `pkg-config --cflags gtk4` $(INCLUDE) calcMain.c -o $(OUT) `pkg-config --libs gtk4` -lm

clean:
	rm $(OUT) || echo "nothing to remove"

push:
	$(CC) $(CFLAGS) `pkg-config --cflags gtk4` $(INCLUDE) calcMain.c -o ~/.local/bin/calc `pkg-config --libs gtk4` -lm

sbuild:
	$(CC) $(CFLAGS) calculator.c stack.c stacktest.c -o stacktest.out -lm

tbuild:
	$(CC) $(CFLAGS) $(INCLUDE) `pkg-config --cflags gtk4` CalcTest.c -o test.out `pkg-config --libs gtk4` -lm

cbuild: clean build
