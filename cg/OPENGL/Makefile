CFLAGS= -L/usr/local/lib64
LIBS= -I/usr/local/include -lm -lGL -lglfw3

q1: basics.c
	gcc basics.c $(CFLAGS) $(LIBS) -o basics
q11: 11-opengl_line.c
	gcc 11-opengl_line.c $(CFLAGS) $(LIBS) -o line
q12: 12-traingle.c
	gcc 12-traingle.c $(CFLAGS) $(LIBS) -o triangle

clean:
	rm basics line triangle
