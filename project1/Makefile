all:	CS344_Project1_Test

CS344_Project1_Test: sort_example.o Integer.o
	g++ -std=c++11 sort_example.o Integer.o -o CS344_Project1_Test

main.o: sort_example.cpp
	g++ -std=c++11 sort_example.cpp

clean:
	rm -rf *.o *.gch
purge:
	rm -rf *.0 *.gch CS344_Project1_Test
