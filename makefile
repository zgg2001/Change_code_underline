#makefile

line: main.o change_code.o
	g++ main.o change_code.o -o line
	find ./ -maxdepth 1 -regex ".*.o" | xargs rm
main.o: main.cpp
	g++ -c main.cpp -o main.o
change_code.o: change_code.cpp
	g++ -c change_code.cpp -o change_code.o

.PHONY: clean
clean:
	find ./ -maxdepth 1 -regex ".*.o" -or -name line | xargs rm
