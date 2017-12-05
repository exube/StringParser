// stringwrapper.cpp
// Contains the implementations of stringwrapper class functions.
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

#include "stringwrapper.h"

#define CTYPE(c) ((c == '"') ? 1 : ((c == '\'') ? 2 : ((c == '\\') ? -1 : 0)))

void stringwrapper::find_quote() {
    size_t quote_sz = this->quote.size();
    size_t data_sz = this->data.size();
    this->quote_loc.clear();
    size_t loc = this->data.find(this->quote);
    while (loc != std::string::npos && loc != data_sz - (quote_sz - 1)) {
        this->quote_loc.push_back(loc);
        loc = this->data.find(this->quote, loc + quote_sz);
    }

}

void stringwrapper::register_quotes() {
    // charmode < 0: escape; charmode > 0: quote; charmode = 0: regular
    int charmode = 0;
    for (size_t i = 0; i < this->data.size(); i++) {
        if (charmode == 0) charmode = CTYPE(this->data[i]);
    }
}

stringwrapper::stringwrapper(std::string& d, const std::string& q, const std::string& esc) : data(d), escape(esc), quote(q) {
    this->reset();
    this->find_quote();
}

size_t stringwrapper::rfind(std::string str, size_t pos) {
    return size_t();
}


size_t stringwrapper::find(std::string str, size_t pos) {

    return size_t();
}

void stringwrapper::reset() {
    this->last_found = this->data.end();
}

signed char convert_character(char c) { 
    switch(c) { 
        case 'n':
            return '\n';
        case 't':
            return '\t';
        case 'v':
            return '\v';
        case 'b':
            return '\b';
        case 'r':
            return '\r';
        case 'f':
            return '\f';
        case 'a':
            return '\a';
        case '\\': case '?': case '\'': case '"': case 0:
            return c;
        default:
            return c;

    }
}
signed char parse_escape_sequence(char c) {
    return c;
}

std::vector<std::string> stringwrapper::split_by_whitespace(const std::vector<std::string> &special_characters) const {
    enum { Q_NONE, Q_DOUBLE, Q_SINGLE, Q_BACK };
    const char* specials = "\"'\\";

    std::vector<std::string> result;

    for (size_t i = 0; i < this->data.size(); i++) {
        std::string cur_word;
        // Special characters: "'\ 
        
}
