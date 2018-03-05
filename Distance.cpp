// 1. f(N) = Euclidean Distance from N to goal
//    length of straight line between 2 options
//    E((i,j),(i',j')) = sqrt[(i-i')^2+(j-j')^2]

#include <vector>
#include <stdlib.h> //abs
#include <math.h>   //sqrt

using namespace std;

struct Point {
  int x;
  int y;
  int cost;
  Point() {
    x = 0;
    y = 0;
    cost = 0;
  }
  Point(int _x, int _y, int _cost) {
    x = _x;
    y = _y;
    cost = _cost;
  }
};

class Distance {
  public:
    Distance(char** inputMap, int inputSize, int inputMode);
    double getDistance();

    bool operator() (const Point& lhs, const Point& rhs) const
    {
      switch (mode) {
        case 0:
          // euclidean only
          break;
        case 1:
          // manhattan only
          break;
        case 2:
          // euclidean + Cost
          break;
        case 3:
          // manhattan + Cost
          break;
        default:
          break;
      }
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

    Point goal;

    void loadMap(char** inputMap, int inputSize);
    double euclidean(Point current, bool addCost);
    double manhattan(Point current, bool addCost);

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
      if(inputMap[i][j] == 'g'){
        this->goal = Point(j, i, 0);
      }
    }
  }
}

double Distance::manhattan(Point current, bool addCost) {
  int exes = abs(this->goal.x-current.x);
  int whys = abs(this->goal.y-current.y);
  int output = exes+whys;
  if (addCost) {
    output += current.cost;
  }
  return (double) output;
}

double Distance::euclidian(Point current, bool addCost) {
  double exes = (double) abs(this->goal.x-current.x);
  double whys = (double) abs(this->goal.y-current.y);
  double output = sqrt (pow(exes,2) + pow(whys,2));
  if (addCost) {
    output += (double) current.cost;
  }
  return output;
}
