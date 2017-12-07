# stringwrapper: A simple quote- and escape-sensitive substring finder.

Usage:

    #include <vector>
    #include <string>
    #include "stringwrapper.h"
    
    .....

    std::string a;
    // populate a

    stringwrapper my_wrapper(a);

    std::vector<std::string> special_delimiters;
    // Push special delimiters to this vector in order of decreasing matching precedence


    std::vector<std::string> tokens = 
        my_wrapper.split_by_whitespace(special_delimiters);



View test program (test.cpp) for an example.

Real documentation coming later...
