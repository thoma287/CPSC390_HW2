#include <iostream>
#include <vector>
#include "Distance.cpp"

using namespace std;

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int&rhs) const
  {
    if (reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }
};

class Robot {
  public:
    Robot();
    ~Robot();

    void loadMap(vector< vector < char > > inputMap, int inputSize);
    void run();

  private:
    char** mapData;
    int mapSize;

    point current;
    point goal;

};

void Robot::run() {

}

void Robot::loadMap(vector< vector < char > > inputMap, int inputSize){
  this->mapSize = inputSize;
  this->mapData = new char* [inputSize];
  for (int i = 0; i < inputSize; ++i) {
    this->mapData[i] = new char [inputSize];
    for (int j = 0; j < inputSize; ++j) {
      this->mapData[i][j] = inputMap[i][j];
      if(inputMap[i][j] == 'O'){
        this->current.x = j;
        this->current.y = i;
      }
      if(inputMap[i][j] == 'G'){
        this->goal.x = j;
        this->goal.y = i;
      }
    }
  }
}
