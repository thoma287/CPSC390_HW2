// 1. f(N) = Euclidean Distance from N to goal
//    length of straight line between 2 options
//    E((i,j),(i',j')) = sqrt[(i-i')^2+(j-j')^2]


#include <iostream>
#include <vector>

using namespace std;

struct point {
  int x;
  int y;
};

class Distance {
  public:
    Distance(char** inputMap, int inputSize, int inputMode);
    ~Distance();

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

    void loadMap(char** inputMap, int inputSize);
    double euclidean(char** inputMap, int inputSize);
    double manhattan(char** inputMap, int inputSize);

};

Distance::Distance(char** inputMap, int inputSize, int inputMode) {
  this->loadMap(inputMap, inputSize);
  this->mode = inputMode;
}

Distance::~Distance() {
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

double Euclidean::getDistance(){
  int* hello = new int(5);
  cout << "Map loaded successfully!" << endl;
  cout << " 0123456789" << endl;
  for (int i = 0; i < this->mapSize; ++i) {
    cout << to_string(i);
    for (int j = 0; j < this->mapSize; ++j) {
      cout << mapData[i][j];
    }
    cout << endl;
  }
  printf("Initial: (%i,%i)\nGoal: (%i,%i)\n", this->initial.x, this->initial.y, this->goal.x, this->goal.y);
  return hello;
}
