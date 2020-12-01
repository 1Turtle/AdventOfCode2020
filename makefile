CC = g++
OUTPUT = "./compiled/"

all:	day1

day1:	Day1.cpp
	$(CC) -o $(OUTPUT)"Day1" ./Day1.cpp
