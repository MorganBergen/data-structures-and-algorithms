#include <iostream>
#include "MyBST.h"

int main() {
    MyBST<int> myTree;
    myTree.insert(5);
    myTree.insert(3);
    myTree.insert(7);
    myTree.insert(1);
    myTree.insert(9);
    myTree.insert(4);

    // test findMin function
    std::cout << "the minimum value in the tree is: " << myTree.findMin() << std::endl;

    // Test findMax function
    std::cout << "the maximum value in the tree is: " << myTree.findMax() << std::endl;

    return 0;
}