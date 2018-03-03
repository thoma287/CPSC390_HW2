// 1. f(N) = Euclidean Distance from N to goal
//    length of straight line between 2 options
//    E((i,j),(i',j')) = sqrt[(i-i')^2+(j-j')^2]


#include <iostream>
#include <vector>

using namespace std;


class Euclidean {
  public:
    char** mapData;
    int mapSize;

    point current;
    point goal;

    Euclidean(vector< vector < char > > inputMap, int mapSize);
    ~Euclidean();

    double getDistance();
};

Euclidean::Euclidean(vector< vector < char > > inputMap, int inputSize){
  this->mapSize = inputSize;
  this->mapData = new char* [inputSize];
  for (int i = 0; i < inputSize; ++i) {
    this->mapData[i] = new char [inputSize];
    for (int j = 0; j < inputSize; ++j) {
      this->mapData[i][j] = inputMap[i][j];
      if(inputMap[i][j] == 'o'){
        this->current.x = j;
        this->current.y = i;
      }
      if(inputMap[i][j] == 'g'){
        this->goal.x = j;
        this->goal.y = i;
      }
    }
  }
  this->getPath();
}

Euclidean::~Euclidean() {
  delete mapData;
}

double Euclidean::getDistance(){
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
  printf("current: (%i,%i)\nGoal: (%i,%i)\n", this->current.x, this->current.y, this->goal.x, this->goal.y);
  return hello;
}
