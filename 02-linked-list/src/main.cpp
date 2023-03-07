#include <iostream>
#include <string>

#include "LinkedList.h"

int main() {
    
    LinkedList<int> first;

    int x = 10;

    std::cout << x << std::endl;
    std::cout << x++ << std::endl;
    std::cout << x << std::endl;
    
    x = 10;

    std::cout << x << std::endl;
    std::cout << ++x << std::endl;
    std::cout << x << std::endl;
    
    /*
     * test push front function
     * green.push_front(data);
     *
     * test empty
     * green.empty();
     *
     * test size
     * green.size();
     *
     * test front
     * green.front();
     *
     * test back
     * green.back();
     *
     * test the construction functyion
     * LinkedList<std::string> second = LinkedList<std::string>(LinkedList<std::string>(first));
     */

    return(0); 
}
