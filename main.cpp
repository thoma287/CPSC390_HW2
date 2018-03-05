/* NxN matrix no greater than 80x80
i = initial state
g = goal state
only options: 4 adjacent moves (i,j-1), (i-1,j), (i,j+1), (i+1,j)
avoid the + (obstacles)
 '.' is empty space
 use o for the the move it does take
 Strategies include:
  1. f(N) = Euclidean Distance from N to goal
      length of straight line between 2 options
      E((i,j),(i',j')) = sqrt[(i-i')^2+(j-j')^2]
  2. f(N) = Manhattan Distance
    length of shortest path obtainable by traversing only in the cardinal
    directions, ingoring any obstacles, M((i,j),(i',j'))=|i-i'|+|j-j'|
  3/4. f(N) = g(N)+h(N), where:
    -g(N) is the cost of the path found so far from the initial node to N
    -h(N) is: -the Euclidean distance from N to the goal (Strategy 3)
              -the Manhattan distance to the goal (Strategy 4)
Cost: for every move +1
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Robot.cpp"



using namespace std;

int main(int argc, char *argv[]) {
  if (argc < 2) {
      // Tell the user how to run the program
      cerr << "Usage: " << argv[0] << " <INPUT_MAP_FILE>" << endl;
      /* "Usage messages" are a conventional way of telling the user
       * how to run a program if they enter the command incorrectly.
       */
      return 1;
  } else {
    string line;
    string fileName(argv[1]);
    ifstream myfile (fileName);

    if (myfile.is_open())
    {
      try {
        if (getline (myfile,line)) {
          int mapSize = stoi(line);
          vector< vector < char > > mapData;
          for (int i = 0; i < mapSize; ++i) {
            if (getline (myfile,line)) {
              vector <char> temp;
              for(string::size_type j = 0; j < line.size(); ++j) {
                temp.push_back(line[j]);
              }
              mapData.push_back(temp);
            } else {
              throw 1;
            }
          }
          // do stuff with mapData
          Robot* roboCop = new Robot();
          roboCop->loadMap(mapData, mapSize);
          roboCop->run();
        }
      } catch (const exception& e) {
        cerr << "Invalid file format." << endl;
      }
      myfile.close();
    }

    else cout << "Unable to open file";

    return 0;
  }
}
