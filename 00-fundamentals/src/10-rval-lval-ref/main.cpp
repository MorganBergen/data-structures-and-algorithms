/*
 * @file    main.cpp
 * @author  morgan bergen
 * @date    jan 27 2023
 * @brief   lvalue and rvalue references
 */

#include <iostream>
#include <string>

void printstring_byval(const std::string s) {
    std::cout << "from printstring_byval: " << s << std::endl;
    return;
}

void printstring_byref(const std::string& s) {
    std::cout << "from printstring_byref: " << s << std::endl;
    return;
}

void printstring_byrref(const std::string&& s) {
    std::cout << "from printstring_byrref: " << s << std::endl;
    return;
}

void increment(int &num) {
    num++;
    return;
}

int main() {


    std::string greet = "hello world";

    // printstring_byval(greet);
    printstring_byref(std::move(greet));

/*
    // rvalue reference
    for(size_t i = 0; i < 10000000; ++i) {
        std::string&& str = "hello world";
        std::string st = std::move(str);
        std::cout << "st " << st << std::endl;
        std::cout << "str " << str << std::endl;
    }
*/
/*
    // lvalue reference
    for (size_t i = 0; i < 10000000; ++i) {
        std::string str = "hello world";
        std::string st = str;
        std::cout << st << std::endl;
        std::cout << str << std::endl;
    }
*/
    return(0);
}

/*
 * > make
 * > /usr/bin/time ./a >foo.txt
 */


/*
 * rvalue reference
 * ❯ /usr/bin/time -al ./a >foo.txt
       38.40 real         6.73 user        31.21 sys
             1130496  maximum resident set size
                   0  average shared memory size
                   0  average unshared data size
                   0  average unshared stack size
                 174  page reclaims
                   1  page faults
                   0  swaps
                   0  block input operations
                   0  block output operations
                   0  messages sent
                   0  messages received
                   0  signals received
                 222  voluntary context switches
                2888  involuntary context switches
        477096210412  instructions retired
        121315919462  cycles elapsed
             1016576  peak memory footprint
 */

/*
 * lvalue reference
 * ❯ /usr/bin/time -al ./a >foo.txt
       40.99 real         5.74 user        34.87 sys
             1130496  maximum resident set size
                   0  average shared memory size
                   0  average unshared data size
                   0  average unshared stack size
                 174  page reclaims
                   1  page faults
                   0  swaps
                   0  block input operations
                   0  block output operations
                   0  messages sent
                   0  messages received
                   0  signals received
                 226  voluntary context switches
                2283  involuntary context switches
        525412392452  instructions retired
        130227280716  cycles elapsed
             1016576  peak memory footprint
 */
