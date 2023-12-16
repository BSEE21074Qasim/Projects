all: ./a.out

compRun:
	g++ -std=c++11 -pedantic *.cpp -o r.out

compTest:
	g++ -std=c++11 -pedantic *.cpp -o t.out

debug:
#	objects := $(wildcard *.o)
	g++ -g -O0 -Wall -Wextra -std=c++11 -pedantic *.cpp -o d.out;
	#./d.out


test: clean compTest; ./t.out

run: clean compRun; ./r.out

clean:
	rm -f *.out
