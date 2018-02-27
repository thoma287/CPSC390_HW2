/*2. f(N) = Manhattan Distance
  length of shortest path obtainable by traversing only in the cardinal
  directions, ingoring any obstacles, M((i,j),(i',j'))=|i-i'|+|j-j'|*/


#include <iostream>
#include <vector>
#include <string>
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

  state initial;
  state goal;
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
        this->initial.x = i;
        this->initial.y = j;
        printf("Inital: (%i,%i)\n", this->initial.x,this->initial.y);
      }

      if(inputMap[i][j] == 'G'){
        this->goal.x = i;
        this->goal.y = j;

        printf("Goal: (%i,%i)\n", this->goal.x,this->goal.y);
      }
      if(inputMap[i][j] == '+'){
        state nipple;
        nipple.x = i;
        nipple.y = j;
        this->obstacles.push_back(nipple);

        printf("Obstacle: (%i,%i)\n", nipple.x,nipple.y);


      }

    }
  }

}

Manhattan::~Manhattan() {
  delete mapData;
}
