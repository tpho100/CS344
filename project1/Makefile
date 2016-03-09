all:	CS344_Project1_Test

CS344_Project1_Test: test.o Integer.o
	g++ -std=c++11 test.o Integer.o -o CS344_Project1_Test

main.o: test.cpp
	g++ -std=c++11 test.cpp

clean:
	rm -rf *.o *.gch
purge:
	rm -rf *.0 *.gch CS344_Project1_Test
