all: 

bstream.o: bstream.cpp
	g++ -c bstream.cpp -o bstream.o
error.o: error.cpp
	g++ -c error.cpp -o error.o
strlib.o: strlib.cpp
	g++ -c strlib.cpp -o strlib.o
lab5.o: lab5.cpp
	g++ -c lab5.cpp -o lab5.o
lab5: lab5.o bstream.o error.o strlib.o
	g++ lab5.o bstream.o error.o strlib.o -o run 
	./run
clean:
	$(RM) lab5
