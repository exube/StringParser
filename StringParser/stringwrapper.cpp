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
