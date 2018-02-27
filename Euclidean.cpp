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

class Euclidean {
  public:
    char** mapData;
    int mapSize;

    point initial;
    point goal;

    Euclidean(vector< vector < char > > inputMap, int mapSize);
    ~Euclidean();

    int* getPath();
};

Euclidean::Euclidean(vector< vector < char > > inputMap, int inputSize){
  this->mapSize = inputSize;
  this->mapData = new char* [inputSize];
  for (int i = 0; i < inputSize; ++i) {
    this->mapData[i] = new char [inputSize];
    for (int j = 0; j < inputSize; ++j) {
      this->mapData[i][j] = inputMap[i][j];
      if(inputMap[i][j] == 'I'){
        this->initial.x = i;
        this->initial.y = j;
      }
      if(inputMap[i][j] == 'G'){
        this->goal.x = i;
        this->goal.y = j;
      }
    }
  }
  this->getPath();
}

Euclidean::~Euclidean() {
  delete mapData;
}

int* Euclidean::getPath(){
  int* hello = new int(5);
  cout << "Map loaded successfully!" << endl;
  cout << " 0123456789" << endl;
  for (int i = 0; i < mapSize; ++i) {
    cout << to_string(i);
    for (int j = 0; j < mapSize; ++j) {
      cout << mapData[i][j];
    }
    cout << endl;
  }
  printf("Initial: (%i,%i)\nGoal: (%i,%i)\n", this->initial.x, this->initial.y, this->goal.x, this->goal.y);
  return hello;
}
