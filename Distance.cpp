// 1. f(N) = Euclidean Distance from N to goal
//    length of straight line between 2 options
//    E((i,j),(i',j')) = sqrt[(i-i')^2+(j-j')^2]


#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h> //abs

using namespace std;

struct point {
  int x;
  int y;
};

class Distance {
  public:
    Distance(char** inputMap, int inputSize, int inputMode);
    int ManhattanCalcDistance(point initial, point goal);
    double getDistance();



    bool operator() (const point& lhs, const point& rhs) const
    {
      // depending on mode, evaluate lhs and rhs
      // if lhs is closer to the goal
      //   return true
      // else
      //   return false
    }

  private:
    char** mapData;
    int mapSize;
    int mode;
    point current;
    point goal;
    point initial;


    //Manhattan
    int distance;
    int exes;
    int whys;

    void loadMap(char** inputMap, int inputSize);
    double euclidean(char** inputMap, int inputSize);
    double manhattan(char** inputMap, int inputSize);

};

Distance::Distance(char** inputMap, int inputSize, int inputMode) {
  this->loadMap(inputMap, inputSize);
  this->mode = inputMode;
}


void Distance::loadMap(char** inputMap, int inputSize){
  this->mapSize = inputSize;
  this->mapData = inputMap;
  for (int i = 0; i < inputSize; ++i) {
    for (int j = 0; j < inputSize; ++j) {
      if(inputMap[i][j] == 'x'){
        this->current.x = j;
        this->current.y = i;
      }
      if(inputMap[i][j] == 'i'){
        this->goal.x = j;
        this->goal.y = i;
      }
    }
  }
}



int Distance::ManhattanCalcDistance(point initial, point goal){
  exes = abs(this->goal.x-this->initial.x);
  whys = abs(this->goal.y-this->initial.y);
  this->distance = this->exes+this->whys;
  return this->distance;
}
