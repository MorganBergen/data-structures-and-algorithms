#include <iostream>

void printint() {
    std::cout << "from printint: " << std::endl;
    return;
}

void increment(int* num){
    *num = *num + 1;
    return;
}

int main(){
    int b = 10;
    int& a = b;
    a = 5;

    increment(a);

    std::cout << a << std::endl;

    return(0);
}
