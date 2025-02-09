exec = Flexxin.out
sources = $(wildcard flexxin.c)
objects = $(sources:.c=.o)
flags = -g


$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

install:
	make
	cp ./Flexxin.out /usr/local/bin/Flexxin

clean:
	-rm *.out
	-rm *.o
	-rm src/*.o