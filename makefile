#makefile

line: main.cpp change_code.h change_code.cpp
	g++ main.cpp change_code.h change_code.cpp -o line

.PHONY: clean
clean:
	rm line
