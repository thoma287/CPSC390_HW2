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
    }
  }
}

Euclidean::~Euclidean() {
  delete mapData;
}

int* Euclidean::getPath(){
  int* hello = new int(5);
  cout << "Map loaded successfully!" << endl;
  for (int i = 0; i < mapSize; ++i) {
    for (int j = 0; j < mapSize; ++j) {
      cout << mapData[i][j];
    }
    cout << endl;
  }
  return hello;
}
