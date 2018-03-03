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

    int calcDistance(point initial, point goal);

  private:
    char** mapData;
    int mapSize;

    point current;
    point goal;

};

void Robot::run() {
  Distance test (this->mapData, this->mapSize, 0);
  priority_queue<point, test> queue0;
  Distance test (this->mapData, this->mapSize, 1);
  priority_queue<point, test> queue1;
  Distance test (this->mapData, this->mapSize, 2);
  priority_queue<point, test> queue2;
  Distance test (this->mapData, this->mapSize, 3);
  priority_queue<point, test> queue3;


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
