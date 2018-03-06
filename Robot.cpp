#include "Distance.cpp"
#include <queue>

using namespace std;
typedef priority_queue<Point, vector<Point>, Distance> SuperQueue;

class Robot {
  char** mapData;
  int mapSize;
  Point initial;
  Point goal;
  int finalNodes;

public:
  Robot();
  ~Robot();

  void run();
  void loadMap(char** inputMap, int inputSize);
  char** makeMapCopy(char** map, int size);
  SuperQueue recursiveBFS(char** previousState, SuperQueue pathTree);
  bool checkSpot(char** previousState, Point spot);
};

Robot::Robot() {

}

Robot::~Robot() {
  delete this->mapData;
}

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
    //cerr << "A" << endl;
    SuperQueue pathTree (Distance(this->goal, i));
    //cerr << "B" << endl;
    pathTree.push(initial);
    //cerr << "C" << endl;
    SuperQueue finalPath = this->recursiveBFS(this->makeMapCopy(this->mapData, this->mapSize), pathTree);
    if (finalPath.empty()) {
      cout << "This map is invalid. There is no path from i to g." << endl;
      return;
    } else {
      cout << "Path for mode " << to_string(i) << endl;
      Point pt = finalPath.top();
      Point* current = pt.parent;
      int finalCost = finalPath.top().cost;
      char** temp = this->makeMapCopy(this->mapData, this->mapSize);
      while (true) {
        if (!current->parent) {
          break;
        }
        temp[current->y][current->x] = 'o';
        current = current->parent;
      }
      for (int k = 0; k < mapSize; ++k) {
        for (int j = 0; j < mapSize; ++j) {
          cout << temp[k][j];
        }
        cout << endl;
      }
      cout << "Steps Taken: " << to_string(finalCost) << endl << "Number of nodes: " << finalPath.size() << endl << endl;
    }
  }
}

void Robot::loadMap(char** inputMap, int inputSize){
  this->mapSize = inputSize;
  this->mapData = this->makeMapCopy(inputMap, inputSize);
  for (int i = 0; i < inputSize; ++i) {
    for (int j = 0; j < inputSize; ++j) {
      if(inputMap[i][j] == 'i'){
        this->initial = Point(j, i, 0, NULL);
      }
      if(inputMap[i][j] == 'g'){
        this->goal = Point(j, i, 0, NULL);
      }
    }
  }
}

char** Robot::makeMapCopy(char** map, int size) {
  //cerr << "D" << endl;
  char** output = new char* [size];
  for (int i = 0; i < size; ++i) {
    output[i] = new char [size];
    for (int j = 0; j < size; ++j) {
      output[i][j] = map[i][j];
    }
  }
  //cerr << "E" << endl;
  return output;
}

SuperQueue Robot::recursiveBFS(char** previousState, SuperQueue pathTree) {
  Point current = pathTree.top();
  if (previousState[current.y][current.x] == 'g') {
    int nodes = 2;
    for (int k = 0; k < this->mapSize; ++k) {
      for (int j = 0; j < this->mapSize; ++j) {
        if (previousState[k][j] == 'o') {
          ++nodes;
        }
      }
    }
    this->finalNodes = nodes;
    return pathTree;
  }
  if (pathTree.empty()) {
    return pathTree;
  } else {
    pathTree.pop();
  }

  previousState[current.y][current.x] = 'o';

  if (current.x > 0 && previousState[current.y][current.x-1] == 'g') {
    pathTree.push(Point(current.x-1, current.y, current.cost+1, &current));
    return this->recursiveBFS(previousState, pathTree);
  } else if (current.x < this->mapSize-1 && previousState[current.y][current.x+1] == 'g') {
    pathTree.push(Point(current.x+1, current.y, current.cost+1, &current));
    return this->recursiveBFS(previousState, pathTree);
  } else if (current.y > 0 && previousState[current.y-1][current.x] == 'g') {
    pathTree.push(Point(current.x, current.y-1, current.cost+1, &current));
    return this->recursiveBFS(previousState, pathTree);
  } else if (current.y < this->mapSize-1 && previousState[current.y+1][current.x] == 'g') {
    pathTree.push(Point(current.x, current.y+1, current.cost+1, &current));
    return this->recursiveBFS(previousState, pathTree);
  }

  bool hasN = false;


  if (this->checkSpot(previousState, Point(current.x-1, current.y, current.cost+1, &current))) {
    pathTree.push(Point(current.x-1, current.y, current.cost+1, &current));
    if (previousState[current.y][current.x-1] == 'g') {

    }
    hasN = true;
  }
  if (this->checkSpot(previousState, Point(current.x+1, current.y, current.cost+1, &current))) {
    pathTree.push(Point(current.x+1, current.y, current.cost+1, &current));
    if (previousState[current.y][current.x+1] == 'g') {

    }
    hasN = true;
  }
  if (this->checkSpot(previousState, Point(current.x, current.y-1, current.cost+1, &current))) {
    pathTree.push(Point(current.x, current.y-1, current.cost+1, &current));
    if (previousState[current.y-1][current.x] == 'g') {

    }
    hasN = true;
  }
  if (this->checkSpot(previousState, Point(current.x, current.y+1, current.cost+1, &current))) {
    pathTree.push(Point(current.x, current.y+1, current.cost+1, &current));
    if (previousState[current.y+1][current.x] == 'g') {

    }
    hasN = true;
  }
  if (!hasN) {
    previousState[current.y][current.x] = 'x';
  }
  //cerr << "I" << endl;
  return this->recursiveBFS(previousState, pathTree);
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
    case 'x':
      return false;
    case 'g':
      return true;
    default:
      return false;
  }
}
