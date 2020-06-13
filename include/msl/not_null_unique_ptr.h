#ifndef NOT_NULL_UNIQUE_PTR_H
#define NOT_NULL_UNIQUE_PTR_H

#include <memory>

namespace msl {

//! not_null_unique_ptr is a class to use as function argument fur a function
//! with a pointer sink. The not_null_unique_ptr is not used derictly but boved
//! to a std::unique_ptr. When using std::move the class is converted to a
//! unique_ptr. That means that is possible to use
//! ``` c++
//! void a_function(std::not_null_unique_ptr<int> a_not_null_unique_ptr) {
//!     auto ptr = std::move(a_not_null_unique_ptr); // ptr is now unique_ptr
//!     cout << *ptr << endl;
//! }
//! ```
template <class T>
class not_null_unique_ptr {
    std::unique_ptr<T> _ptr;

    void assertNotNull() {
        if (_ptr == nullptr) {
            throw std::invalid_argument("pointer is null when it shouldnt");
        }
    }

public:
    not_null_unique_ptr(std::unique_ptr<T> &&ptr) : _ptr(std::move(ptr)) {}

    not_null_unique_ptr() = default;
    not_null_unique_ptr(const not_null_unique_ptr &) = delete;
    not_null_unique_ptr(not_null_unique_ptr &&) = default;
    not_null_unique_ptr &operator=(const not_null_unique_ptr &) = delete;
    not_null_unique_ptr &operator=(not_null_unique_ptr &&) = default;

    operator std::unique_ptr<T> &&() {
        assertNotNull();
        return std::move(_ptr);
    }
};

} // namespace msl

namespace std {

template <typename T>
constexpr typename std::remove_reference<std::unique_ptr<T>>::type &&move(
    msl::not_null_unique_ptr<T> &value) noexcept {
    return static_cast<
        typename std::remove_reference<std::unique_ptr<T>>::type &&>(value);
}

} // namespace std

#endif // NOT_NULL_UNIQUE_PTR_H
