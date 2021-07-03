#include <cstdint>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

std::string readFile() {
  std::ifstream myFile("./input.txt");
  std::string line;
  std::string ln;
  while (getline(myFile, ln)) {
    line = ln;
  }
  myFile.close();

  return line;
}

void partOne(std::string line) {
  bool whileValidation = true;
  while (whileValidation) {
    int iteration = 0;
    for (int index = 0; index < line.length(); ++index) {
      if ((line[index] == line[index + 1] + 32) ||
          (line[index] == line[index + 1] - 32)) {
        line.erase(index, 2);
        iteration++;
      }
    }
    if (iteration == 0) {
      whileValidation = false;
    }
  }
  std::cout << line.length() << std::endl;
}

void partTwo(std::string tempLine) {
  int best = 100000;
  char letter = 65;
  for (int letterIndex = 0; letterIndex < 25; ++letterIndex) {
    std::string line = tempLine;
    for (int index = 0; index < line.length(); ++index) {
      if ((line[index] == letter + letterIndex) ||
          (line[index] == letter + letterIndex + 32)) {
        if ((line[index] == line[index + 1] + 32) ||
            (line[index] == line[index + 1] - 32)) {
          line.erase(index, 2);
        }
      }
    }

    bool whileValidation = true;
    while (whileValidation) {
      int iteration = 0;
      for (int index = 0; index < line.length(); ++index) {
        if ((line[index] == line[index + 1] + 32) ||
            (line[index] == line[index + 1] - 32)) {
          line.erase(index, 2);
          iteration++;
        }
      }
      if (iteration == 0) {
        whileValidation = false;
      }
    }
    best = line.length() < best ? line.length() : best;
  }
  std::cout << best << std::endl;
}

int main() {
  std::string line = readFile();
  partOne(line);
  partTwo(line);
}
