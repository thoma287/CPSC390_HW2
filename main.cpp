#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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
              vector<char> temp;
              for(string::size_type j = 0; j < line.size(); ++j) {
                temp.push_back(line[j]);
              }
              mapData.push_back(temp);
            } else {
              throw 1;
            }
          }
          cout << "Map loaded successfully!" << endl;
          for (int i = 0; i < mapSize; ++i) {
            for (int j = 0; j < mapSize; ++j) {
              cout << mapData[i][j];
            }
            cout << endl;
          }
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
