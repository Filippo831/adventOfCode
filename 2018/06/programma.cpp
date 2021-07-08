#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct positionTemplate {
  int distance;
  int point;
};

std::vector<std::vector<positionTemplate> >
    myMap(10000, std::vector<positionTemplate>(10000));

std::ifstream myFile("input.txt");

std::vector<std::string> readFile() {
  std::vector<std::string> lines;
  std::string ln;
  while (getline(myFile, ln)) {
    lines.push_back(ln);
  }
  myFile.close();

  return lines;
}

// get the index position
void fillMap(int index, int x, int y) {
  // pass every cell on the map
  int colsIndex = 0;
  for (auto cols : myMap) {
    colsIndex++;
    int rowsIndex;
    for (auto rows : cols) {
      // create a variable with distance and index
      positionTemplate fillMapNewPosition;
      // calculate the distance from the current index
      int tempDistance = abs(x - colsIndex) + abs(y - rowsIndex);
      // if the distance is less than the previous one change distance
      if (index != 0) {
        if (tempDistance < myMap[colsIndex][rowsIndex].distance) {
          fillMapNewPosition.distance = tempDistance;
        }
      }
      //if the index is 0 assign all the distances
      if (index == 0) { 
        fillMapNewPosition.distance = tempDistance;
      }
      fillMapNewPosition.point = index;
      rowsIndex++;
    }
  }
}

void calculateIndexes() {
  std::map<int, int> indexPositions;
  for (auto cols : myMap) {
    for (auto rows : cols) {
      indexPositions[rows.point] += 1;
    }
  }
  for ( auto a : indexPositions ) {
    std::cout << a.first<< " : "<< a.second << std::endl;
  }
}

void partOne(std::vector<std::string> lines) {
  int index = 0;
  for (auto line : lines) {
    positionTemplate newPosition;
    int comma = line.find(',');
    // get x and y positions from each line
    int x = std::stoi(line.substr(0, comma));
    int y = std::stoi(line.substr(comma + 1, line.length()));
    // std::cout << x << " : " << y << std::endl;
    // set the number of the point
    newPosition.point = index;
    newPosition.distance = 0;
    // insert the new position on the map
    myMap[x][y] = newPosition;
    fillMap(index, x, y);
    index++;
  }
  calculateIndexes();
}
void partTwo(std::vector<std::string> lines) {}

int main(int argc, char *argv[]) {
  std::vector<std::string> lines = readFile();
  partOne(lines);
  partTwo(lines);

  return 0;
}
