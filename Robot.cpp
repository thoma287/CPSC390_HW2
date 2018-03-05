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

    int calcDistance(Point initial, Point goal);

  private:
    char** mapData;
    int mapSize;

    Point current;
    Point goal;

};

void Robot::run() {
  typedef priority_queue<Point, vector<Point>, Distance> SuperQueue;
  SuperQueue queue0 ();
}

void Robot::loadMap(vector< vector < char > > inputMap, int inputSize){
  this->mapSize = inputSize;
  this->mapData = new char* [inputSize];
  for (int i = 0; i < inputSize; ++i) {
    this->mapData[i] = new char [inputSize];
    for (int j = 0; j < inputSize; ++j) {
      this->mapData[i][j] = inputMap[i][j];
      if(inputMap[i][j] == 'i'){
        this->initial = Point(j, i, 0);
      }
      if(inputMap[i][j] == 'g'){
        this->goal = Point(j, i, 0);
      }
    }
  }
}
