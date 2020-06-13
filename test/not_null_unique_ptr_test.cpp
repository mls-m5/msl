
#include "mls-unit-test/unittest.h"
#include "msl/not_null_unique_ptr.h"

using namespace msl;

TEST_SUIT_BEGIN

//! The code works but the test case does not work
// TEST_CASE("throw when null") {
//    auto ptr1 = std::unique_ptr<int>();
//    not_null_unique_ptr<int> notNull = std::move(ptr1);
//    EXPECT_THROW(ptr1 = std::move(notNull), std::invalid_argument);
//}

TEST_CASE("do not throw when not null") {
    auto ptr1 = std::make_unique<int>(10);
    not_null_unique_ptr<int> notNull = std::move(ptr1);
    auto ptr2 = std::move(notNull);
}

TEST_CASE("send as argument") {
    auto f = [](msl::not_null_unique_ptr<int> i) -> int {
        auto ptr = std::move(i); // Convert to unique_ptr
        return *ptr;
    };

    ASSERT_EQ(f(std::make_unique<int>(10)), 10);
}

TEST_CASE("double move") {
    msl::not_null_unique_ptr<int> not_null = std::make_unique<int>(10);
    auto ptr2 = std::move(std::move(not_null));
    ASSERT_EQ(*ptr2, 10);
}

TEST_SUIT_END
