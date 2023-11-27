#include <iostream>
#include <fstream>
#include <string>


void writeInFile(){
    std::string text;
    std::cout << "Enter text: ";
    std::getline(std::cin, text);

    std::ofstream myFile("input.txt", std::ios::out);

    
    if (!myFile.is_open()) {
        return; 
    }

    myFile << text; 
    myFile.close(); 

    if (myFile.eof()) {
        std::cout << "File written successfully." << std::endl;
    } 
}

void copyToAnotherFile(){
     std::string text;
     std::cout << "the text you typed in the input file is now copied to the output file..." << std::endl;
     std::ifstream inputFile("input.txt", std::ios::in);
     
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the input file." << std::endl;
        return;
    }

   std::ofstream myFile("output.txt", std::ios::out);

    if (!myFile.is_open()) {
        std::cerr << "Error opening the input file." << std::endl;
        return;
    }

    while (std::getline(inputFile, text)) {
        myFile << text << std::endl; 
    }

    inputFile.close();
    myFile.close();

    std::cout << "File copied successfully." << std::endl;
}

int main() {
    writeInFile();
    copyToAnotherFile();
    return 0; 
}


