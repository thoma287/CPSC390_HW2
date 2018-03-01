/*2. f(N) = Manhattan Distance
  length of shortest path obtainable by traversing only in the cardinal
  directions, ingoring any obstacles, M((i,j),(i',j'))=|i-i'|+|j-j'|*/


#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>     /* abs */

using namespace std;

struct state {
  int x;
  int y;
};


class Manhattan{

public:
  char** mapData;

  Manhattan(vector< vector < char > > inputMap, int mapSize);
  ~Manhattan();
  int calcDistance(state initial, state goal);
  int distance;
  state initial;
  state goal;
  int exes;
  int whys;
  vector < state > obstacles;

  int* getPath(char** arr);

  int* getIntial(char** arr);

};

Manhattan::Manhattan(vector< vector < char > > inputMap, int mapSize){
  this->mapData = new char* [mapSize];
  for (int i = 0; i < mapSize; ++i) {
    this->mapData[i] = new char [mapSize];
    for (int j = 0; j < mapSize; ++j) {
      this->mapData[i][j] = inputMap[i][j];
      if(inputMap[i][j] == 'I'){
        this->initial.x = j;
        this->initial.y = i;
        printf("Inital: (%i,%i)\n", this->initial.x,this->initial.y);
      }

      if(inputMap[i][j] == 'G'){
        this->goal.x = j;
        this->goal.y = i;

        printf("Goal: (%i,%i)\n", this->goal.x,this->goal.y);
      }
      if(inputMap[i][j] == '+'){
        state nipple;
        nipple.x = j;
        nipple.y = i;
        this->obstacles.push_back(nipple);

        printf("Obstacle: (%i,%i)\n", nipple.x,nipple.y);

      }

    }
  }

}
int Manhattan::calcDistance(state initial, state goal){
  exes = abs(this->goal.x-this->initial.x);
  whys = abs(this->goal.y-this->initial.y);
  this->distance = this->exes+this->whys;
  return this->distance;
}
Manhattan::~Manhattan() {
  delete mapData;
}
