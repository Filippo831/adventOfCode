#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>

using byte = unsigned char;

std::string file_path = "./input_test.txt";

std::vector<std::string> lines;

int readBytes(std::string input) {
    int value = 0;
    int index = 0;
    while(index < input.length()) {
        value += std::stoi(input.substr(index, 1)) * pow(2 ,input.length() - index -1 );
        std::cout<<value<<" : ";
        index++;
    }
    return value;
}

std::string getGreater(std::vector<std::string> input, int index) {
    int sum = 0;
    int arrayLenght = input.size();
    for (auto line : lines) {
        sum += std::stoi(line.substr(index, 1));
    }
    if (sum < arrayLenght/2) {
        return "0";
    }
    return "1";
}

void readFile() {
    std::fstream file(file_path);
    if (file.is_open()) {
        std::string data;
        int value;
        while (std::getline(file, data)) {
            lines.push_back(data);
        }
        file.close();
    }


}

void part1() {
    std::string bytes = "";
    for (int a = 0; a < lines.at(0).length(); a++) {
        bytes.append(getGreater(lines, a));
    }

    std::cout<<bytes<<std::endl;
    int value = readBytes(bytes);

    int neg_value = pow(2, lines.at(0).length()) - value - 1;
    std::cout<<value<<"  "<<neg_value<<std::endl;

    std::cout<<value*neg_value;
}

void part2(std::vector<std::string> input) {
    std::vector<std::string> input_copy = input;
    std::string value;
    for (int a = 0; a < input_copy.at(0).length(); a++) {
        value = getGreater(input, a);
        for (auto line : input_copy) {
            if (line.substr(a, 1) == value) { 
                input_copy.erase(input_copy.begin() + a);
            }
        }
    }


}

int main() {
    readFile();
    //part1();
    part2(lines);
}
