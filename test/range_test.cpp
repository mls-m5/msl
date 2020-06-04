#include "mls-unit-test/unittest.h"
#include "msl/range.h"

using namespace msl;

TEST_SUIT_BEGIN

TEST_CASE("single range") {
    int sum = 0;

    for (auto i : range(10)) {
        sum += i;
    }

    ASSERT_EQ(sum, 45);
}

TEST_CASE("double value range") {
    int sum = 0;

    for (auto i : range(2, 10)) {
        sum += i;
    }

    ASSERT_EQ(sum, 44);
}

TEST_SUIT_END
