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
