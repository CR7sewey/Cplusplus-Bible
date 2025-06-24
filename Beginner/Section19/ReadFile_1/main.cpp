// Section 19
// Read File 1
// Test for file open and simple read of 3 data items
// open in input mode or binary std::ios::in | std::ios::binary for fstream (both i/o)
// for ifstream, it is default
#include <iostream>
#include <fstream>

int main() {
    std::ifstream in_file;
    std::string line;
    int num;
    double total;
    
    std::string path = "./test.txt";
    in_file.open(path); // path, std::ios::binary
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    in_file >> line >> num >> total; // similar to cin >> 
    // getline(in_file, line) to read the file one line at a time
    // in_file.get() - read a character
    std::cout << line << std::endl;
    std::cout << num << std::endl;
    std::cout << total << std::endl;
    in_file.close();
    return 0;
}

