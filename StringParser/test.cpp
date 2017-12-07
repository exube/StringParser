#include "stringwrapper.h"

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv) {
    char abc[256];
    std::cin.getline(abc, 255);
    abc[255] = 0;
    std::string test(abc);

    stringwrapper wrap(test);

    std::vector<std::string> special_strings;
    special_strings.push_back("||");
    special_strings.push_back("&&");
    special_strings.push_back(";");
    special_strings.push_back("(");
    special_strings.push_back(")");

    
    auto vec = wrap.split_by_whitespace(special_strings);

    for (auto i : vec) std::cout << i << std::endl;

    return 0;
    
}