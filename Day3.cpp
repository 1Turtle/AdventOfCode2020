/*+++ Task +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
* | You have a map that repeats itself from                          |
* | left to right infinitely often.                                  |
* | You start at the top and try to get to the bottom                |
* | with certain steps (3 right, 1 down).                            |
* | You have to count how often you hit a tree (#).                  |
* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/* +++ Libs +++ */
#include <iostream>
#include <vector>
#include <math.h>

#define X   0
#define Y   1

using namespace std;


/* +++ Puzzle input +++ */
vector<int> size = { 31, 323 };
string map = ".#.......#...........#...........##.......#.#.#.....##...#...........#..#.....#...#.............#..........###...#........###.#..#.#.##.#........#.#.....#.#..#....#..#....#..............#..#........#....................#.#...#.#...#....#.#.#..#..................#..#..............##....#...................#...........#..........#......#...#.##..#..#...##..........#...#...#...#....#.........#...#.....#.#........##............#.#...............#..............##....#..#......#..#..............#...#.#.#...........#........#.....###..........#....#.#......#........#...##..........#...............#...#......................#....#..#.......#........#........##.#......#.....#...##....#.#........................#..#.....#.##..............#.#.....#.#...#.#..#....#....#........#....##.....#....#........#.....#...........#.##....#...#......#.##...#....#.#.....##...#..........#...####...#...#.......#.#...#................................................#............#.#.........#..........#.##.........#............###..#.......#.#.............###..........#..#........#.#.......#........................#....#.........#..#...#............#..##......#.....#....#.......##......#.....#....#...##..#..#...#...#...........#...........#.#.#......#.......#...#.....#......#............#.......##......#..#.#..#.....#..#.###...#.#......#..#....#...#..#...#.....#..........#......#..#.......#.#.....#..#......#...#......#.....##.#...........##.......#.......#......#.#...............#.........................#...#.#....#.........#......#.#..#......#..........##....#....#...#.............#...............#...........#..#.#...#.#.....#.....#...#.#......##...........#.....#..#...#..#.#...##.#.#......#......#.....##.....#.......##....#.#.#...........#...........#....#....#.....#...........#......#.####........#....#...#...##.......#........................#.#####....#...#.#...#..#..#......#.........#........##.......##....#..#.#......##.........##.#..#...#.#.#....#...#..#...#...##....#......##...#....#....#.#..............#..#....#.#...#...................#...................#.............#.###....#.#..........#.#.....#......#....#.#..#................#..#.#.#.#.......#..##...................##.......#.......#..#.........##..#............##...#......#........#..#.........#........##.###.#.............#.#....#.....###......#....##.#..#.##....#.....##....#.....#.##..................##....#.......................................#..#...#.#.............#..#.#.##....#..........#..#.........#.####.....#.............#..#.#..........#...#..........#.................#..#.#......#..........#..................#.....#............#....##......#.....#........#......................#.....#...#................#....#.#...............#.....#.........#......#..#.#.....#..#......#......#.......#.......#......#.#....#..#...#...#......................#..##.................#.........###....##..............#.#..........##....#.#.................##.................#.#.....#....................#.................#.#.........#........#...#..##...#.........#......##.......###..................#.#.#.............#.....###...##.#......#.....#..............#......#.#.#...#.#..#.........#.......#.....#..........#........#...##......#....##..........##......#.#.....#...#.##....#....#.....................#...#..#.....#.....#...#........##..##..#............##...............#...##........#..#....#................#..#.............#.......#.#.#...#............#.......#..............#.#.#..#...#........#....#..####...#........#...........#.....#..##...........................#.............#...........#......#.....#.#...#.........#.................#...#....#....#.......#..#........##....#..................###......##...#...................#.#.#..#.#....#..............##..#.........#....#...........#.#......#.#...#.#..#......#....................#.##..##....#..#...........#.....#.#....#..............##...##..#.#.......#.##.#.......#..#...#........#..#..##.....#.....#.#....#.......#....##.##..............#..##....#.....#.#...............................#......#..#....#......#...#..#.......#...#.............#....#.#.....#......#..#...##.........###..#......#.......#......................##.......#....................#...#..#..........#..#..#....#....##..#..#.....#.#..##..........#..###.......#..##..#...#..#.#......##......###.....#.#.##...#..............#...#....#.#.....#...........#................................#....#..##..#..#..........#.............#........#.#....#....#...............##.##.##.#.....###.....#.............#..............##......#.......#........##....................#.....#....#....##....##....#........#......#......#..........#..........#...............##..........#......#.....#.............#.#..#.#..#.....##.......##......#.#.......#.#..#......#.......#......#...........#....#.#..#.#..................#.....#...#...#...##......#........#...##....#...#...#...#..............#.#.......#..............#.##.#.....#...........#.##.#..#.##.#........#...##...........#.....#.....#....#..#............##.............##............#........##.....#.......#...#............#..#..##........##.......#..#........................#.......#.........................#......#....#....#.......#........#..#.#.....#......#..............#..#.....#......#..............#####.....#........#.........#..#...#.#....#......#..........#...#....#.#................#....##..........#...#...#..............###.#.#..........#.#............##......#.#..#.......#...........................#..#......#.......#....#...#.......#....##.....#.#......##............#..........#..#................#..#.....###......#........#....#..##......#................#.#.#.......#..#...#.........#.......##.....##...#.................#....#.....#........#....#.....#.#..........##..###.........#.............#.......##......#.#........#....#..##....###.......#...#.#......##.....#...##.......#......#.....#.....#......#..................#........##....#....#.#................#.......###...#................#..#.......###.......................#......#..#......#......#.....#....#.#...........#......##.#.#.....#...#.#....#.##...........#..#.##.....#.........#.....................#....#..#...#...##.#...#..................#.......##..#.#..#.............##.....#.....#...........................#.............#........#..#.......##.........#...#..###.#..#....#.#.###.......#.......#.......#.......#..................#............##...#...#..#...##.........#....#..#...........#...#.....................#.....#......#..#.....#...........#......#.............##.........###..##.#....#..#.#...............###..............#..##.............##.....#.........##...................#..#......#.....#..............#..#.#........#........##...#.....##.#...........#.##..........##...#......##.....#...............#..##..#....#.................#.#.......##....................................#.##..##......#...#.##..#.#....#.......##............##....#............##.....#..#..##.....#.##....#........#.........#..........#...#....#...#.......#.............#.#.#...##............#...##........#.......#.#.#........#...............#.............#.....#..............#.........#.........#.#.....#....#.......#....................#....#.............#.#.##..#.......#...#......#..........#....#....#........#....#..............#.......#..#......#.#............#.##........##.....#...##...#....#...#.#...#..#.#...#..........#..##.........#...#.........................#.#...........#.........#..#.##....#..................#..#.............#......#...........#..#.....##.....#.....#..#.......#............#.#.......#......#...............#................#.......#...#..#............##.....#.......#..#....#..........#..#.....#..#.....#..##.......##.....#.......#...#....#...#.#..##...#...##......#....#....#............###.#..#.......#......#.........#.#...#..#..#...#....#.....#.........##.#.....#...........#.........#..##........#.....#...........#......#....#.##......................#............................##......#..#......#.#.....##..##..........#..#.##........#.#.#..........#..#.......#...##.#....#....#....#.#......#..#..#.......#....................#........#.......#....#...#.....#........#...#.....#..............##..#...........#.................#..#...##......#..#...#.........................#.........##.#..#..#...##........#..#....#.......#.#.##..#...#...........#..........#..##.....#...#............##...#..##.....#...#...................#.......####.#..##.##.#......#.............#...#..#..#..........#.##.........#.#....#..................##...##....#....##..........#......#...#......................#..#...#....#.##......##....#..........#....#...#..#....#.#.#.......#.#.................#............##..........#.#.###..#....#.......#...#.....#......##..#..#.#.........#..#..#.........#........#....#..........##.#.......##....#..#..##.............#...#............#......#......#...#.#.#.##.#....#.#...#.##.....#..............#..........#.............##.##..#......#....#...#.#.#.#..#....#........#........#...#.#......#.....#...........#........................#....#..........#.......####...#..##....#.#.........#......#...#..#...........#...#......###..#.##.###.............#...........#.........#....#.................#.#....#..#.##....................#......#........#.#.....#.......#...###.##..#........#.#....#...#..#...#......#..###.................#..#.....#.#..#........#......#..#.....#.....#...............#...#............##.#.........#..#.........#..#..##.#.#...##.........#..........##..#..#........#...............#..#...#...............#.#....#........##........#.....##....#..#...#.......##...............#.##.............#..#..#...##....##.#.....##.#....#...###..#.........##................##......#.....#..###........#......##.###.................#.....#.#..#.#..#..............#..#.......#...........#....#.............#..#......##......#.#......#.#........................#.#.#............#..#.........###....##............#..#.........#....#......#...................#...............#..#.";


/* +++ Part 1/2 +++ */
int navigator(int factor[2]) {
    int hits = 0;
    vector<int> toboggan = { 0, 0 };
    
    /* Goes from the top start down to the target. */
    for(int i=0; i<size[Y]-1; i++) {
        /* moves the toboggan according to the given factor. */
        /* if it goes further to the right (where the map would normally repeat tself) it starts back again. */
        toboggan[X] += factor[X];   toboggan[Y] += factor[Y];
        toboggan[X] -= size[X]*abs(toboggan[X]/size[X]);

        /* Simply stops here if it should shoot over the target. */
        if(toboggan[Y]>size[Y]) return hits;
        
        /* Counts how often the toboggan has suffered damage. */
        if(map.substr(toboggan[Y]*size[X]+toboggan[X], 1) == "#")
            hits += 1;
    }

    return hits;
}

int main(void) {
    /* The five given factors (routes) & the corresponding results. */
    int factor[5][2] = { {1,1}, {3,1}, {5,1}, {7,1}, {1,2} };
    int result[5];

    /* Goes through every route. */
    for(int i=0; i<5; i++) {
        result[i] = navigator(factor[i]);
        cout << "Slope" << (i+1) << ": " << result[i] << endl;
    }
        
    /* Prints the results here: */
    cout << "Part2: " << (result[0]*result[1]*result[2]*result[3]*result[4]) << endl;

    return 0;
}