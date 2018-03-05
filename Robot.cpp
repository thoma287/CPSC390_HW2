#include "Distance.cpp"

using namespace std;

class Robot {
  typedef priority_queue<Point, vector<Point>, Distance> SuperQueue;
  char** mapData;
  int mapSize;
  Point initial;
  Point goal;
  int finalCost;

public:
  Robot();
  ~Robot();

  void run();
  void loadMap(vector< vector < char > > inputMap, int inputSize);
  char** makeMapCopy(char** map, int size);
  char** recursiveBFS(char** previousState, SuperQueue pathTree, int cost);
  bool checkSpot(char** previousState, Point spot);
};

void Robot::run() {
  // dusplay input map
  cout << "Input map: " << endl;
  for (int i = 0; i < mapSize; ++i) {
    for (int j = 0; j < mapSize; ++j) {
      cout << mapData[i][j];
    }
    cout << endl;
  }
  cout << endl;

  // run calculations
  for (int i = 0; i < 4; i++) {
    SuperQueue pathTree (Distance(this->mapData, this->mapSize, i));
    pathTree.push(initial);
    char** finalPath = this->recursiveBFS(this->makeMapCopy(this->mapData, this->mapSize), pathTree, 0);

    cout << "Path for mode " << to_string(i) << endl;
    for (int k = 0; k < mapSize; ++k) {
      for (int j = 0; j < mapSize; ++j) {
        cout << mapData[k][j];
      }
      cout << endl;
    }
    cout << "Cost: " << to_string(this->finalCost) << endl << endl;
  }
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

char** Robot::makeMapCopy(char** map, int size) {
  char** output = new char* [size];
  for (int i = 0; i < size; ++i) {
    output[i] = new char [inputSize];
    for (int j = 0; j < inputSize; ++j) {
      output[i][j] = map[i][j];
    }
  }
  return output;
}

char** Robot::recursiveBFS(char** previousState, SuperQueue pathTree, int cost) {
  Point current = pathTree.top();
  if (previousState[current.y][current.x] == 'g') {
    this->finalCost = cost;
    return previousState;
  }
  if (previousState[current.y][current.x] == '.') {
    previousState[current.y][current.x] = 'o';
  }
  cost += 1;
  if (this->checkSpot(previousState, Point(current.x-1, current.y, cost))) {
    pathTree.push(Point(current.x-1, current.y, cost));
  }
  if (this->checkSpot(previousState, Point(current.x+1, current.y, cost))) {
    pathTree.push(Point(current.x+1, current.y, cost));
  }
  if (this->checkSpot(previousState, Point(current.x, current.y-1, cost))) {
    pathTree.push(Point(current.x, current.y-1, cost));
  }
  if (this->checkSpot(previousState, Point(current.x, current.y+1, cost))) {
    pathTree.push(Point(current.x, current.y+1, cost));
  }
  return this->recursiveBFS(previousState, pathTree, cost);
}

bool Robot::checkSpot(char** previousState, Point spot) {
  if ((spot.x < 0 || spot.y < 0) || (spot.x >= this->mapSize || spot.y >= this->mapSize)) {
    return false;
  }
  switch (previousState[spot.y][spot.x]) {
    case '.':
      return true;
    case '+':
      return false;
    case 'o':
      return false;
    case 'i':
      return false;
    case 'g':
      return true;
    default:
      return false;
  }
}
