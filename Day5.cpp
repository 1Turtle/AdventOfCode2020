/*+++ Task +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
* | Given is a list of board passes.                                 |
* | The first 7 describe the row & the last 3 describe the column    |
* | by dividing the difference again by half and indicating          |
* | in which half the seat is located.                               |
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/* +++ Libs +++ */
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h> 


/* +++ Puzzle input +++ */
std::string input = "BFFFBBFRRR\\nFFFBBBFRRR\\nBBFFBBFRLL\\nFBFBBFFRLR\\n";


/* Gets the list Input from .txt file. */
std::string getInput() {
    std::ifstream file("./Input.txt");
    std::string str; 

    /* Looks where the input is located. */
    getline(file, str);
    int line = str.find("day05:", 0);
    if(line == std::string::npos && str.substr(line+6, 2).find_first_not_of("0123456789") != std::string::npos)
        return str;
    line = std::stoi(str.substr(line+6, 2), nullptr, 0);
    
    /* Jumps to the requested line: */
    for(int i=1; i<line; i++) {
        getline(file, str);
    }

    return str;
};

/* +++ Part-1 +++ */
std::vector<int> part1() {
    int result[2] = { 0, 0 };
    int differenz[2] = { 0, 127 };
    std::string boardcard;
    int lastP = 0; /* Lines Start (last saved position). */
    std::vector<int> cardId;

    for(int i=1; i<input.length(); i++) {
        if(input.substr(i, 2)=="\\n") {
            result[0] = 0; result[1] = 0;
            differenz[0] = 0; differenz[1] = 127;
            boardcard = input.substr(lastP, i-lastP);
            lastP = i+2;
            /* row */
            for(int j=0; j<7; j++) {
                if(boardcard.substr(j, 1) == "F") {
                    differenz[1] = (differenz[0]+differenz[1])/2;
                    result[0] = differenz[0];
                } if(boardcard.substr(j, 1) == "B") {
                    differenz[0] = round(differenz[0]+differenz[1])/2+0.5;
                    result[0] = differenz[1];
                }
            }

            differenz[0] = 0; differenz[1] = 7;

            /* column */
            for(int j=0; j<3; j++) {
                if(boardcard.substr(j+7, 1) == "L") {
                    differenz[1] = (differenz[0]+differenz[1])/2;
                    result[1] = differenz[0];
                } if(boardcard.substr(j+7, 1) == "R") {
                    differenz[0] = round(differenz[0]+differenz[1])/2+0.5;
                    result[1] = differenz[1];
                } 
            }

            cardId.push_back(result[0]*8+result[1]);
        }
    }

    std::sort(cardId.begin(), cardId.end(), std::greater<int>());

    return cardId;
}

/* +++ Part-2 +++ */
std::vector<int> part2(std::vector<int> list) {
    std::vector<int> emptySeats;

    /* Goes through the list and looks for gaps. */
    for(int i=0; i<list.size(); i++)
        if(list[i] == list[i+1]+2 || list[i] == list[i+1]-2)
            emptySeats.push_back(list[i]-1);

    return emptySeats;
}

int main(void) {
    input = getInput();

    /* Calculates the input. */
    std::vector<int> result1, result2;
    result1 = part1();
    result2 = part2(result1);

    /* Prints the results here: */
    std::cout << "Part1: " << result1[0] << std::endl;
    std::cout << "Part2: ";

    for(int i=0; i<result2.size(); i++)
        std::cout << result2[i] << " ";
    std::cout << std::endl;

    return 0;
}