// stringwrapper.h
// Definitions for the stringwrapper class.

/************************************************************************************
* MIT License                                                                      *
*                                                                                  *
* Copyright(c) 2017 Daniel Ma                                                      *
*                                                                                  *
* Permission is hereby granted, free of charge, to any person obtaining a copy     *
* of this software and associated documentation files(the "Software"), to deal     *
* in the Software without restriction, including without limitation the rights     *
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell        *
* copies of the Software, and to permit persons to whom the Software is            *
* furnished to do so, subject to the following conditions :                        *
*                                                                                  *
* The above copyright notice and this permission notice shall be included in all   *
* copies or substantial portions of the Software.                                  *
*                                                                                  *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR       *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,         *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE       *
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER           *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,    *
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE    *
* SOFTWARE.                                                                        *
************************************************************************************/



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

    void register_quotes();

    public:
    stringwrapper(std::string& data, const std::string& quote = "\"'", const std::string& escape = "\\");

    // Find the first occurrence of str starting from the end of the string (or at pos)
    // and searches backwards. Returns a position from the start of the string.
    // Does not search inside quote strings indicated in the constructor.  
    size_t rfind(std::string str, size_t pos = std::string::npos);

    // Find the first occurrence of str starting from the beginning of the string, or from pos
    // searches forward.  Returns a position from the start of the string.
    size_t find(std::string str, size_t pos = 0);

    void reset();

    // Split our string by whitespace, but putting the special strings in their own element.
    // Also parses by escapes and quotes.

    // special_characters contains extra delimiters in decreasing priority.
    std::vector<std::string> split_by_whitespace(const std::vector<std::string> &special_characters) const;



};

