/*2. f(N) = Manhattan Distance
  length of shortest path obtainable by traversing only in the cardinal
  directions, ingoring any obstacles, M((i,j),(i',j'))=|i-i'|+|j-j'|*/


#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Manhattan{

public:
  char** mapData;
  int** initial;
  int** goal;
  Manhattan(vector< vector < char > > inputMap, int mapSize);
  ~Manhattan();

  int* getPath(char arr[][n]);

  int* getIntial(char arr[][n]);

};

Manhattan::Manhattan(vector< vector < char > > inputMap, int mapSize){
  this->mapData = new char* [mapSize];
  for (int i = 0; i < mapSize; ++i) {
    this->mapData[i] = new char [mapSize];
    for (int j = 0; j < mapSize; ++j) {
      this->mapData[i][j] = inputMap[i][j];
      if(inputMap[i][j] == 'i'){
        this->initial = inputMap[i][j];
      }
      if(inputMap[i][j] == 'g'){
        this->goal = inputMap[i][j];
      }
    }
  }
}

~Manhattan::Manhattan() {
  delete mapData;
}
