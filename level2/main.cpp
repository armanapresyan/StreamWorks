#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

void  manipulation(const std::vector<std::string>& info){

     std::cout << std::setw(15) << std::left << "Name"
              << std::setw(10) << std::left << "Age" << std::endl;
    for(int i = 0; i < info.size(); ++i){
        if (info[i] == "Name" && i + 1 < info.size()) {
            std::cout << std::setw(15) << std::left << info[i + 1];
        }
        if (info[i] == "age" && i + 1 < info.size()) {
            std::cout << std::setw(10) << std::left << info[i + 1]<< std::endl;
        }
    }
}

void parseFile() {
    std::ifstream file("text.txt");
    std::vector<std::string> info;

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    std::string line;
    std::string word; 

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        while (iss >> word) {
            info.push_back(word);
        }
    }

    file.close();
    
     manipulation(info);
}



int main() {
    parseFile();
    return 0;
}
