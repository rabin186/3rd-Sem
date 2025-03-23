CFLAGS= $(shell pkg-config --cflags glfw3)
LIBS= $(shell pkg-config --libs glfw3) -lm -lGL

q1: opengl.c
	gcc opengl.c $(CFLAGS) $(LIBS) -o test

clean:
	rm test
