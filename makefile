CC = g++
OUTPUT = ./compiled/

all:	day1 day2 day3 day4 day5 day6

day1:	Day1.cpp
	$(CC) -o $(OUTPUT)Day1 ./Day1.cpp

day2:	Day2.cpp
	$(CC) -o $(OUTPUT)Day2 ./Day2.cpp

day3:	Day3.cpp
	$(CC) -o $(OUTPUT)Day3 ./Day3.cpp

day4:	Day4.cpp
	$(CC) -o $(OUTPUT)Day4 ./Day4.cpp

day5:	Day5.cpp
	$(CC) -o $(OUTPUT)Day5 ./Day5.cpp

day6:	Day6.cpp
	$(CC) -o $(OUTPUT)Day6 ./Day6.cpp