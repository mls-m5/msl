#include "mls-unit-test/unittest.h"

#include "msl/strings.h"

using namespace msl;

TEST_SUIT_BEGIN

TEST_CASE("starts_with") {
    std::string test = "hello there";

    ASSERT_EQ(starts_with(test, "hello"), true);
    ASSERT_EQ(starts_with(test, "there"), false);

    // Check for crashes
    starts_with("short", "longer string");
}

TEST_CASE("ends_with") {
    std::string test = "hello there";

    ASSERT_EQ(ends_with(test, "hello"), false);
    ASSERT_EQ(ends_with(test, "there"), true);

    // Check for crashes
    ends_with("short", "longer string");
}

TEST_CASE("replace") {
    std::string test = "hello there";
    ASSERT_EQ(replace(test, "hello", "there"), "there there");
}

TEST_CASE("replace_all") {
    std::string test = "hello there hello";
    ASSERT_EQ(replace_all(test, "hello", "there"), "there there there");
}

TEST_SUIT_END
