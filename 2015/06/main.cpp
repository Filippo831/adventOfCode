#include <cstdint>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::vector<std::vector<bool>> grid(1000, std::vector<bool>(1000, false));

struct coordinates_struct {
  int x_begin;
  int y_begin;
  int x_end;
  int y_end;
};

struct move_struct {
  int type;
  coordinates_struct coordinates;
};

std::vector<move_struct> moves;

coordinates_struct getCoordinates(std::string line);

void readFile();
std::int8_t getAction(std::string line);

int main() {
  readFile();
  return 0;
}

void readFile() {
  std::fstream file("./input.txt");
  if (file.is_open()) {

    std::string line;

    move_struct *data, d;
    data = &d;

    while (std::getline(file, line)) {
      data->type = getAction(line);
      data->coordinates = getCoordinates(line);
    }

    file.close();
  }
}

std::int8_t getAction(std::string line) {

  std::int8_t type;

  if (line.find("turn on") != std::string::npos) {
    type = 0;
  }

  if (line.find("turn off") != std::string::npos) {
    type = 1;
  }

  if (line.find("toggle") != std::string::npos) {
    type = 2;
  }

  return type;
};

coordinates_struct getCoordinates(std::string line) {
  coordinates_struct *coordinates, b;
  coordinates = &b;

  std::string number = "";

  int index = 0;
  bool before = false;

    std::cout<<line<<std::endl;
  for (auto i : line) {
    if (std::isdigit(i)) {
      if ((before == false) && (number == "")) {
        index += 1;
        std::cout << number << std::endl;
        //switch (index) {
        //case 1:
          //coordinates->x_begin = std::stoi(number);
          //break;
        //case 2:
          //coordinates->y_begin = std::stoi(number);
          //break;
        //case 3:
          //coordinates->x_end = std::stoi(number);
          //break;
        //case 4:
          //coordinates->y_end = std::stoi(number);
          //break;
        //}
        number = "";
      }
      before = true;
      number.append(std::to_string(i));

    } else {
      before = false;
    }
  }
  return *coordinates;
}
