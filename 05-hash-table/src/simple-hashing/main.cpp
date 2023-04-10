#include <iostream>
#include <string>
#include <vector>

int hashSimple0 (const std::string &key, int tablesize);
int hashSimple(const std::string &key, int tablesize);

int main() {

    std::vector<std::string> keys = {"JON", "MARY", "MORGAN", "DAVID", "ALEX", "ANISHA", "MONA"};    
    std::vector<int> values = {0000, 1111, 2222, 3333, 4444, 5555, 6666};
    int tablesize = 7;

    std::cout << "HASH FUNCTION 1" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;
    for (int i = 0; i < 7; i++) {
        int location = hashSimple0(keys[i], tablesize);
        std::cout << std::endl;
        std::cout << "(" << keys[i] << ", " << values[i] << ")";
        std::cout << " hashes to cell location: " 
                  << location << std::endl;
        std::cout << "tablesize = " << tablesize << std::endl;
    } 
    
    std::cout << "HASH FUNCTION 2" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;

    for (int i = 0; i < 7; i++) {
        std::cout << hashSimple(keys[i], 7);
        int location = hashSimple(keys[i], 7);
        std::cout << std::endl;
        std::cout << "(" << keys[i] << ", " << values[i] << ")";
        std::cout << " hashes to cell location: " 
                  << location << std::endl;
        std::cout << "tablesize = " << tablesize << std::endl;
    }

    return(0);
}

int hashSimple0(const std::string &key, int tablesize) {
    int hashvalue = 0;
    for (char ch : key) {
        hashvalue += ch;
    }
    return (hashvalue % tablesize);
}

int hashSimple(const std::string &key, int tablesize) {
        return((key[0] + 27 * key[1] + 729 * key[2]) % tablesize );
}


