/*2. f(N) = Manhattan Distance
  length of shortest path obtainable by traversing only in the cardinal
  directions, ingoring any obstacles, M((i,j),(i',j'))=|i-i'|+|j-j'|*/


#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>     /* abs */
#include "Distance.cpp"


using namespace std;


class Manhattan{

public:
  char** mapData;

  Manhattan(vector< vector < char > > inputMap, int mapSize);
  ~Manhattan();

  int calcDistance(point initial, point goal);
  int distance;
  point initial;
  point goal;
  int exes;
  int whys;
  vector < point > obstacles;

  int* getPath(char** arr);

  int* getIntial(char** arr);

};

Manhattan::Manhattan(vector< vector < char > > inputMap, int mapSize){

  this->mapData = new char* [mapSize];
  for (int i = 0; i < mapSize; ++i) {
    this->mapData[i] = new char [mapSize];
    for (int j = 0; j < mapSize; ++j) {
      this->mapData[i][j] = inputMap[i][j];
      if(inputMap[i][j] == 'o'){
        this->initial.x = j;
        this->initial.y = i;
        printf("Inital: (%i,%i)\n", this->initial.x,this->initial.y);
      }

      if(inputMap[i][j] == 'g'){
        this->goal.x = j;
        this->goal.y = i;

        printf("Goal: (%i,%i)\n", this->goal.x,this->goal.y);
      }
      if(inputMap[i][j] == '+'){
        point nipple;
        nipple.x = j;
        nipple.y = i;
        this->obstacles.push_back(nipple);

        printf("Obstacle: (%i,%i)\n", nipple.x,nipple.y);

      }

    }
  }

}
int Manhattan::calcDistance(point initial, point goal){
  exes = abs(this->goal.x-this->initial.x);
  whys = abs(this->goal.y-this->initial.y);
  this->distance = this->exes+this->whys;
  return this->distance;
}
Manhattan::~Manhattan() {
  delete mapData;
}
