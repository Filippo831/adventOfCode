#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::ifstream myFile("./input.txt");

std::vector<std::vector<int> > myMap(1000, std::vector<int>(1000,0));

std::vector<std::string> readFile() {
  std::vector<std::string> lines;
  std::string ln;
  while (getline(myFile, ln)) {
    lines.push_back(ln);
  }
  myFile.close();

  return lines;
}

void partOne(std::vector<std::string> lines) {
  int overClaimed = 0;
  for (auto line : lines) {
    int start = line.find('@');
    int comma = line.find(',');
    int points = line.find(':');
    int times = line.find('x');

    int xPadding = std::stoi(line.substr(start + 1, comma - (start + 1)));
    int yPadding = std::stoi(line.substr(comma + 1, points - comma));

    int xDimension = std::stoi(line.substr(points + 2, times - points));
    int yDimension = std::stoi(line.substr(times + 1, line.length() - points));

    for (int x = 0; x < xDimension; ++x) {
      for (int y = 0; y < yDimension; ++y) {
        myMap[xPadding + x][yPadding + y] =
            myMap[xPadding + x][yPadding + y] + 1;
      }
    }
  }
  for (auto x : myMap) {
    for (auto y : x) {
      if (y > 1) {
        overClaimed++;
      }
    }
  }
  std::cout << overClaimed << std::endl;
}
void partTwo(std::vector<std::string> lines) {
  for (auto line : lines) {
    bool intact = true;

    int start = line.find('@');
    int comma = line.find(',');
    int points = line.find(':');
    int times = line.find('x');

    int xPadding = std::stoi(line.substr(start + 1, comma - (start + 1)));
    int yPadding = std::stoi(line.substr(comma + 1, points - comma));

    int xDimension = std::stoi(line.substr(points + 2, times - points));
    int yDimension = std::stoi(line.substr(times + 1, line.length() - points));

    for (int x = 0; x < xDimension; ++x) {
      for (int y = 0; y < yDimension; ++y) {
        if (myMap[xPadding + x][yPadding + y] != 1) {
          intact = false;
        }
      }
    }
    if (intact) {
      std::cout << line << std::endl;
    }
  }
}

int main(int argc, char *argv[]) {
  std::vector<std::string> lines = readFile();
  partOne(lines);
  partTwo(lines);

  return 0;
}
