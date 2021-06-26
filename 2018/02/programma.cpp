#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::ifstream myFile("./input.txt");

// partone variable
int doubleLetter = 0;
int tripleLetter = 0;

std::vector<std::string> readFile() {
  std::vector<std::string> functionLines;
  std::string ln;
  while (getline(myFile, ln)) {
    functionLines.push_back(ln);
  }
  myFile.close();
  return functionLines;
}

void partOne(std::vector<std::string> functionLines) {
  for (auto &line : functionLines) {
    std::map<char, int> letters;

    for (int i = 0; i < line.length(); ++i) {
      letters[line.at(i)] = letters[line.at(i)] + 1;
    }

    std::map<char, int>::iterator it = letters.begin();

    bool doubleChecker = true;
    bool tripleChecker = true;

    while (it != letters.end()) {
      if (doubleChecker) {
        if (it->second == 2) {
          doubleLetter++;
          doubleChecker = false;
        }
      }
      if (tripleChecker) {
        if (it->second == 3) {
          tripleLetter++;
          tripleChecker = false;
        }
      }
      it++;
    }
  }
  std::cout <<"doubleLetter: "<< doubleLetter << std::endl;
  std::cout <<"tripleLetter: "<< tripleLetter << std::endl;
  std::cout << "total: "<<doubleLetter*tripleLetter << std::endl;
}
void partTwo(std::vector<std::string> functionLines) {}

int main(int argc, char *argv[]) {
  std::vector<std::string> lines = readFile();
  partOne(lines);
  // partTwo();

  return 0;
}
