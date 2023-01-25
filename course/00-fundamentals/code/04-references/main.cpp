#include <iostream>
#include <string>
#include <vector>

void lvalue();
void rvalue();
void reference();

int main() {


    lvalue();

    return 0;
}



void lvalue() {

    std::string str = "hell";
    // right_str is another name for str
    // essentially a copy of str
    std::string & right_str = str;

    std::cout << "str is " << str << std::endl;
    std::cout << "right_str " << right_str << std::endl;


    // you can append to the string via +=
    // // changes str to hello
    right_str += "o";

    // a boolean conditional of name conditional will be true 
    // if an donly if the memory address of str and right_str are the same
    bool conditional = (&str == &right_str);

    std::cout << "&str is " << &str << std::endl;
    std::cout << "&right_str is " << &right_str << std::endl;

    /*
     * in the case for right_str and str, their memory addresses are the same
     * so the conditional will be true
     */

    /*
     * the & operator is the address of operator
     * it returns the memory address of the variable'
     * it is used to compare the memory address of two variables
     * to see if they are the same
     */

    // main.cpp:53:12: error: binding reference of type 'char' to value of type 'const char' drops 'const' qualifier
    // const char c = 'c';
    // char & right_c = c;

    // main.cpp:52:19: error: non-const lvalue reference to type 'std::string' cannot bind to a value of unrelated type
    // thuis is illegal becayuse "hello" is not a modifiable value
    // std::string & bad1 = "hello";
    // cannot work because str + "" is a lvalue and not a modifiable value
    // std::string & bad2 = str + "";
    // std::string & sub_string = str.substr(0, 4);

}

/*
void references() {

    // std stands for standard library 
    // :: is the scope resolution operator
    // vector is a class
    // <std::string> is the data type of the vector
    // array(3) states that the vector will have 3 elements
    std::vector<std::string> array(3);

    const int x = 2;

    int y;

    int z = x + y;

    std::string string_foo = "foo";

    std::vector<std::string> *ptr = &array;

    array[x] = "last element";
    array[1] = "middle element";
    array[0] = "first element";

    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << std::endl;
    }

    std::cout << string_foo.substr(0, 3) << std::endl;

     // array            lvalue
     // &x               lvalue
     // x                
     // y
     // z
     // string_foo
     // *ptr
}

*/
