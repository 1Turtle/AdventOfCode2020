/*+++ Task +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
* | Given is a list. This has several passports                      |
* | (separated by line breaks). The task is to find out              |
* | how many of them are correct.                                    |
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/* +++ Libs +++ */
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

#define BYR     0
#define IYR     1
#define EYR     2
#define HGT     3
#define HCL     4
#define ECL     5
#define PID     6
#define CID     7
#define CM      0
#define IN      1

using namespace std;


/* +++ Puzzle input +++ */
string input;


/* Gets the list Input from .txt file. */
string getInput() {
    std::ifstream file("./Input.txt");
    std::string str; 

    getline(file, str);
    int n = str.find("day04:", 0);
    if(n != (-1)) {
        n = std::stoi(str.substr(n+6, 2), nullptr, 0);
        
        for(int i=0; i<(n-1); i++) {
            getline(file, str);
        }
        return str;
    }
    return "";
};

/* Checks whether the expected measured values are available. */
int module1(string passport) {
    vector<int> data = { 0,0,0,0,0,0,0,0,0 };

    for(int j=0; j<(passport.length()-4); j++) {
        if(passport.substr(j, 4) == "byr:")     data[BYR]++;
        if(passport.substr(j, 4) == "iyr:")     data[IYR]++;
        if(passport.substr(j, 4) == "eyr:")     data[EYR]++;
        if(passport.substr(j, 4) == "hgt:")     data[HGT]++;
        if(passport.substr(j, 4) == "hcl:")     data[HCL]++;
        if(passport.substr(j, 4) == "ecl:")     data[ECL]++;
        if(passport.substr(j, 4) == "pid:")     data[PID]++;
    }
    
    for(int k=0; k<7; k++)
        data[8] += data[k];

    return data[8];
}

/* Checks if the data is correct. */
int module2(string passport) {
    vector<int> data = { 0,0,0,0,0,0,0,0,0 };

    for(int j=0; j<(passport.length()-4); j++) {
        string str = passport.substr(j, 4);
        if(str == "byr:") {
            int year = stoi(passport.substr(j+4, 4), nullptr, 0);
            if(year >= 1920  &&  year <= 2002)
                data[BYR]++;
        }   
        if(str == "iyr:") {
            int year = stoi(passport.substr(j+4, 4), nullptr, 0);
            if(year >= 2010  &&  year <= 2020)
                data[IYR]++;
        }    
        if(str == "eyr:") {
            int year = stoi(passport.substr(j+4, 4), nullptr, 0);
            if(year >= 2020  &&  year <= 2030)
                data[EYR]++;
        }    
        if(str == "hgt:") {
            vector<string> numbers = { passport.substr(j+4, 3), passport.substr(j+4, 2) };

            if(numbers[CM].find_first_not_of("0123456789") == string::npos   &&   passport.substr(j+7, 2) == "cm") {
                if(stoi(numbers[CM], nullptr, 0) >= 150   &&   stoi(numbers[CM], nullptr, 0) <= 193)
                    data[HGT]++;
            }
            else if(numbers[IN].find_first_not_of("0123456789") == string::npos   &&   passport.substr(j+6, 2) == "in") {
                if(stoi(numbers[IN], nullptr, 0) >= 59   &&   stoi(numbers[IN], nullptr, 0) <= 76)
                    data[HGT]++;
            }
        }
        if(str == "hcl:") {
            if(passport.substr(j+5, 6).find_first_not_of("0123456789abcdefABCDEF")==string::npos)
                data[HCL]++;
        }
        if(str == "ecl:") {
            string color = passport.substr(j+4, 3);
            if(color=="amb" || color=="blu" || color=="brn" || color=="gry" || color=="grn" || color=="hzl" || color=="oth")
                data[ECL]++;
        }
        if(str == "pid:") {
            if(passport.substr(j+4, 9).find_first_not_of("0123456789")==string::npos)
                data[PID]++;
        }
    }

    for(int k=0; k<7; k++)
        data[8] += data[k];
    return data[8];
}


/* +++ Part 1/2 +++ */
int *scanner(void) {
    static int valid[2] = { 0, 0 };
    int lastP = 0; /* Lines Start (last saved position). */
    string passport = "";

    /* Goes through the whole string letter by letter. */
    for(int i=0; i<input.length(); i++) {
        /* Checks if the end of a line has been reached. */
        if(input.substr(i, 2)=="\\n") {
            passport += input.substr(lastP, i-lastP) + " "; /* Saves the current line to the pass. */
            lastP = i+2;

            /* Checks against the criteria for part1/2 if the pass has ended at the current position. */
            if(input.substr(i+2, 2)=="\\n") {
                if(module1(passport)>=7)   valid[0]++;
                if(module2(passport)>=7)   valid[1]++;
                passport = "";
            }
        }
    }

    return valid;
}

int main(void) {
    input = getInput();
    int *results = scanner();

    /* Prints the results here: */
    cout << "Part1:" << results[0] << endl;
    cout << "Part2:" << (results[1]-1) << endl;

    return 0;
}
