#include <iostream>

// reads two ints from keyboard
void getNumbers(int& input1, int& input2);

// interchange the values of variable1 and variable2
void swapValues(int& variable1, int&variable2);

// shows the values of variable1 and variable2 in that order
void showResults(int output1, int output2);

int main() {

    int zeronum = 0;
    int firstnum = 0;
    int secondnum = 0;
    int thirdnum = 0;

    std::cout << &zeronum << std::endl;
    std::cout << &firstnum << std::endl;
    std::cout << &secondnum << std::endl;
    std::cout << &thirdnum << std::endl;


    getNumbers(firstnum, secondnum);
    swapValues(firstnum, secondnum);
    showResults(firstnum, secondnum);

    return(0);
}

void getNumbers(int& input1, int& input2) {
    
    std::cout << "enter 2 integers: ";
    std::cin >> input1 >> input2;
    return;

}

void swapValues(int& variable1, int& variable2) {

    int temp = variable1;     
    variable1 = variable2;
    variable2 = temp;
    return;

}

void showResults(int output1, int output2) {
    std::cout << "in reverse order the numbers are: " << output1 << " " << output2 << std::endl;
    return;
}









