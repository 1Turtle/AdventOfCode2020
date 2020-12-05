CC = g++
OUTPUT = ./compiled/

all:	day1 day2 day3 day4

day1:	Day1.cpp
	$(CC) -o $(OUTPUT)Day1 ./Day1.cpp

day2:	Day2.cpp
	$(CC) -o $(OUTPUT)Day2 ./Day2.cpp

day3:	Day3.cpp
	$(CC) -o $(OUTPUT)Day3 ./Day3.cpp

day4:	Day4.cpp
	$(CC) -o $(OUTPUT)Day4 ./Day4.cpp