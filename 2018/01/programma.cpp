#include "fstream"
#include "iostream"
#include "map"
#include "string"
#include "vector"
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <utility>

std::ifstream myFile("./input.txt");
std::vector<std::string> lines;
std::map<int, bool> frequences;
int total;
std::vector<int>::iterator found;
int iteration = 0;

std::vector<std::string> readFile() {
  std::vector<std::string> functionLines;
  std::string ln;
  while (getline(myFile, ln)) {
    functionLines.push_back(ln);
  }
  myFile.close();
  return functionLines;
}

void partOne() {
  for (std::string &a : lines) {
    if (a[0] == '+') {
      total = total + std::stoi(a.substr(1, a.length() - 1));
    } else {
      total = total - std::stoi(a.substr(1, a.length() - 1));
    }
    // std::cout << a << std::endl;
  }
  std::cout << total << std::endl;
}

void partTwo() {
  bool whileControl = true;
  while (whileControl) {
    for (std::string &a : lines) {
      iteration++;
      if (a[0] == '+') {
        total = total + std::stoi(a.substr(1, a.length() - 1));
      } else {
        total = total - std::stoi(a.substr(1, a.length() - 1));
      }
      if (frequences[total] == true) {
        std::cout << total << std::endl;
        whileControl = false;
      }
      frequences.insert(std::pair<int, bool>(total, true));
    }
  }
}

int main(int argc, char *argv[]) {
  lines = readFile();
  // partOne();
  partTwo();

  return 0;
}
