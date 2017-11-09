#pragma once

#include <string>
#include <vector>
#include <utility>
class stringwrapper {
    private:
    const std::string& data;
    
    std::string escape;
    std::string quote;

    std::string::const_iterator last_found;

    std::vector<size_t> quote_loc;

    // Find the quotes and store their locations
    void find_quote();

    public:
    stringwrapper(std::string& data, const std::string& quote = "\"", const std::string& escape = "\\");

    size_t rfind(std::string str, size_t pos = std::string::npos);
    size_t find(std::string str, size_t pos = 0);

    void reset();



};

