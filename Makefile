.PHONY: clean

game: main.o
	g++ -o game main.o

main.o: main.cpp
	g++ -c main.cpp

test_parseBoard: test_parseBoard.o
	g++ -o test_parseBoard test_parseBoard.o

test_parseBoard.o: tests/test_parseBoard.cpp tests/acutest.h
	g++ -c tests/test_parseBoard.cpp

test_init_display: test_init_display.o
	g++ -o test_init_display test_init_display.o

test_init_display.o: tests/test_init_display.cpp tests/acutest.h
	g++ -c tests/test_init_display.cpp

clean:
	rm -f *.o game test_parseBoard test_init_display
