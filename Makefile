CFLAGS = -O
CC = g++
main: main.o shape.o dcontext2d.o
	rm -rf release
	mkdir release
	$(CC) $(CFLAGS) -o release/main main.o shape.o dcontext2d.o `sdl2-config --cflags --libs`
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
shape.o:
	$(CC) $(CFLAGS) -c sources/shape.cpp
dcontext2d.o:
	$(CC) $(CFLAGS) -c sources/dcontext2d.cpp
clean:
	rm -rf release *.o