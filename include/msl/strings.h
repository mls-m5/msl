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

//! Replace the first occurence of a string (needle) to another (replacement) in
//! a bigger string (stack)
//! @returns the string with replaced values
//!
//! If you do not wish to copy a large string, use std::move with the first
//! argument:
//! str = replace(std::move(str), "hello", "there");
std::string replace(std::string stack,
                    const std::string &needle,
                    const std::string &replacement) {
    auto f = stack.find(needle);
    if (f != std::string::npos) {
        stack.replace(stack.begin() + static_cast<ptrdiff_t>(f),
                      stack.begin() + static_cast<ptrdiff_t>(f + needle.size()),
                      replacement);
    }
    return stack;
}

std::string replace_all(std::string stack,
                        const std::string &needle,
                        const std::string &replacement) {
    size_t f = std::string::npos;
    while ((f = stack.find(needle)) != std::string::npos) {
        stack.replace(stack.begin() + static_cast<ptrdiff_t>(f),
                      stack.begin() + static_cast<ptrdiff_t>(f + needle.size()),
                      replacement);
    }
    return stack;
}

} // namespace msl

#endif // MSL_STRINGS_H
