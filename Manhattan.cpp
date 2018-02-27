/*2. f(N) = Manhattan Distance
  length of shortest path obtainable by traversing only in the cardinal
  directions, ingoring any obstacles, M((i,j),(i',j'))=|i-i'|+|j-j'|*/

using namespace std;
#include stdio.h
#include <array>

public class Manhattan{

public:
  char** mapData;
  Manhattan(vector< vector < char > > inputMap, int mapSize);
  ~Manhattan();

  int* getPath(char arr[][n])();

  int* getIntial(char arr[][n]);

};

Manhattan(vector< vector < char > > inputMap, int mapSize){
  self.mapData = new char* [mapSize];
  for (int i = 0; i < mapSize; ++i) {
    self.mapData[i] = new char [mapSize];
    for (int j = 0; j < mapSize; ++j) {
      self.mapData[i][j] = inputMap[i][j];
    }
  }
}

~Manhatten() {
  delete mapData;
}
