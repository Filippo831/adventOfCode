#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string.h>
#include <vector>

// struct definitions

struct pearson {
  std::string me;
  bool gain;
  int value;
  std::string you;
};

// variables definition
std::vector<std::string> lines;

std::vector<std::map<int, int>> friendship (11, std::map<int,int>(0,0));

std::vector<std::string> invited_person = {
    "Alice", "Bob", "Carol", "David", "Eric", "Frank", "George", "Mallory"};

// functions definition
void readLines(std::vector<std::string> &lines_vector);

void getInformation(pearson &information, std::string line);

int main() { readLines(lines); }

void readLines(std::vector<std::string> &lines_vector) {
  std::ifstream file;
  file.open("./input.txt");
  if (file.is_open()) {
    std::string l;
    while (getline(file, l)) {
      lines_vector.push_back(l);
    }
  }

  pearson information;

  for (auto line : lines) {
    getInformation(information, line);
        
  }
}

void getInformation(pearson &information,std::string line) {

  bool gain;
  int gain_value;
  // get my name
  std::string my_name = line.substr(0, line.find("would") - 1);

  // get other pearson name
  std::string you_name = line.substr(line.find(" to ") + 4);
  you_name = you_name.substr(0, you_name.length() - 1);

  if (line.find("gain") != std::string::npos) {
    gain = true;
  } else {
    gain = false;
  }

  std::string value = (line.substr(line.find("happines") - 3, 3));

  value.erase(std::remove(value.begin(), value.end(), ' '), value.end());

  gain_value = std::stoi(value);

  information.gain = gain;
  information.value = gain_value;
  information.me = my_name;
  information.you = you_name;
};
