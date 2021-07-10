#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::map<std::string, std::vector<std::string> > positions;
std::string finalSequence;
// std::vector<std::vector<std::string> > sequence (100,
// std::vector<std::string> (100));

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

std::string recursiveFunction(std::string currentLetter, std::string sequence) {
  if (currentLetter == "Y") {
    return sequence;
  }
  sequence = sequence + currentLetter;
  for(auto next : positions.at(currentLetter)){
    std::cout << next << std::endl;
    recursiveFunction(next, sequence);
  }
  return sequence;
}

void partOne(std::vector<std::string> lines) {
  int index = 0;
  for (auto line : lines) {
    std::string currentLetter = line.substr(5, 1);
    std::string beforeLetter = line.substr(36, 1);
    positions[currentLetter].push_back(beforeLetter);
    index++;
  }
  std::string sequence  =recursiveFunction("C", "");
  std::cout << sequence << std::endl;
}
void partTwo(std::vector<std::string> lines) {}

int main(int argc, char *argv[]) {
  std::vector<std::string> lines = readFile();
  partOne(lines);
  partTwo(lines);

  return 0;
}
