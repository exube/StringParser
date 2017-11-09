#include "stringwrapper.h"

#include <iostream>
#include <string>


int main(int argc, char** argv) {
    char abc[128];
    std::cin.getline(abc, 127);
    std::string test(abc);

    stringwrapper wrap(test, "\"\"\"");

    return 0;
    
}