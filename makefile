CC = g++
OUTPUT = ./compiled/

all:	day1 day2

day1:	Day1.cpp
	$(CC) -o $(OUTPUT)Day1 ./Day1.cpp

day2:	Day2.cpp
	$(CC) -o $(OUTPUT)Day2 ./Day2.cpp