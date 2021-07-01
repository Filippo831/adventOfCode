#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::ifstream myFile("./input.txt");

struct information {
  int myMinutes;

  // 0 = begin shift
  // 1 = falls asleep
  // 2 = wakes up
  int action;

  int guardNumber;
};


// vector with all information divided by month and day
std::vector<std::vector<std::vector<information > > > daysVector (10, std::vector<std::vector<information> >(32, std::vector<information> (10)));
//std::vector<std::vector<std::vector<std::string> > > daysVector (10, std::vector<std::vector<std::string> >(32, std::vector<std::string> (10)));

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
  for (auto line : lines) {
    int myMonth= std::stoi(line.substr(6,2));
    int myDay = std::stoi(line.substr(9,2));
    information data;

    if (line.find("wakes") < 1000) {
      data.action = 2;
    };
    if (line.find("falls") < 1000) {
      data.action = 1;
    };
    if (line.find("shift") < 1000) {
      int space = line.find(" ", 26);
      int guardNumber = std::stoi(line.substr(26, space-26));

      data.action = 0;
      data.guardNumber = guardNumber;
    };

    daysVector[myMonth][myDay].push_back(data);
  }
}

void partTwo(std::vector<std::string> lines) {}

int main(int argc, char *argv[]) {
  std::vector<std::string> lines = readFile();
  partOne(lines);
  partTwo(lines);

  return 0;
}
