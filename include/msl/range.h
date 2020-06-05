#ifndef RANGE_H
#define RANGE_H

#include <cstddef>

namespace msl {

//! Waiting for std::views::ita...
class range {
public:
    typedef size_t T;
    struct iterator {
        T value;

        constexpr iterator(T value = 0) : value(value) {}
        constexpr iterator(const iterator &) = default;
        constexpr iterator(iterator &&) = default;
        constexpr iterator &operator=(const iterator &) = default;
        constexpr iterator &operator=(iterator &&) = default;

        constexpr iterator &operator++() {
            ++value;
            return *this;
        }

        constexpr bool operator!=(const iterator &other) {
            return value != other.value;
        }

        constexpr bool operator<(const iterator &other) {
            return value < other.value;
        }

        constexpr T operator*() {
            return value;
        }
    };

    //! Count from 0 to one before the specified range
    //! usage example:
    //! range(10)
    constexpr range(iterator range) : _begin(0), _end(range) {}

    //! usage example:
    //! range(1, 10)
    constexpr range(iterator begin, iterator end) : _begin(begin), _end(end) {}

    constexpr auto begin() const {
        return _begin;
    }

    constexpr auto end() const {
        return _end;
    }

private:
    iterator _begin;
    iterator _end;
};

} // namespace msl

#endif // RANGE_H
