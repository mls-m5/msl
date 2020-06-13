#ifndef MSL_STRINGS_H
#define MSL_STRINGS_H

#include <string>

namespace msl {

//! Checksi if the beginning of a string (stack) matches another string (needle)
//! this will be replaced by std::string::starts_with in c++20
//! https://en.cppreference.com/w/cpp/string/basic_string/starts_with
bool starts_with(const std::string &stack, const std::string &needle) {
    return stack.rfind(needle, 0) != std::string::npos;
}

//! Checksi if the end of a string (stack) matches another string (needle)
//! this will be replaced by std::string::ends_with in c++20
//! https://en.cppreference.com/w/cpp/string/basic_string/ends_with
bool ends_with(const std::string &stack, const std::string &needle) {
    return stack.find(needle, stack.size() - needle.size()) !=
           std::string::npos;
}

} // namespace msl

#endif // MSL_STRINGS_H
