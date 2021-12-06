#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>

using byte = unsigned char;

std::string file_path = "./input_test.txt";

std::vector<byte> byteArray;

int readBytes(char &vector) {
    int value = 0;
    int index;
    while(vector + sizeof(unsigned char) != 0) {
        value += vector + sizeof(unsigned char) * 2^index;
    }
    return value;
}

void readFile() {
    std::fstream file(file_path);
    if (file.is_open()) {
        std::string data;
        int value;
        while (std::getline(file, data)) {
            value = readBytes(data);
            //byteArray.push_back(data.c_str());
        }
        file.close();
    }
}

int main() {
    readFile();
}
