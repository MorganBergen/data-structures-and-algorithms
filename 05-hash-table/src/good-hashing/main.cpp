#include <iostream>
#include <string>
#include <vector>

unsigned int hash(const std::string &key, int tablesize) {
    unsigned int hashval = 0;
    for (char ch : key) {
        hashval = 37 * hashval + ch;
    }
    return(hashval % tablesize);
}

int main() {

    std::vector<std::string> keys = {"JON", "MARY", "MORGAN", "DAVID", "ALEX", "ANISHA", "MONA"};    
    std::vector<int> values = {0000, 1111, 2222, 3333, 4444, 5555, 6666};
    int tablesize = 7;

    std::cout << "HASH FUNCTION 1" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    for (int i = 0; i < 7; i++) {
        int location = hash(keys[i], tablesize);
        std::cout << std::endl;
        std::cout << "(" << keys[i] << ", " << values[i] << ")";
        std::cout << " hashes to cell location: " 
                  << location << std::endl;
        std::cout << "tablesize = " << tablesize << std::endl;
    } 

}

