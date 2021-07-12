#include <gtest/gtest.h>
#include "Base64.h"

namespace {
    std::vector<uint8_t> strToBytes(const char* str) {
        return std::vector<uint8_t>(str, str + strlen(str));
    }
}

TEST(Base64, encode) {
    std::vector<uint8_t> input(strToBytes("Hello World"));
    auto result = Base64::encode(input);
    ASSERT_EQ(result, "SGVsbG8gV29ybGQ=");
}

TEST(Base64, decode) {
    auto result = Base64::decode("SGVsbG8gV29ybGQ=");
    ASSERT_EQ(result, strToBytes("Hello World"));
}

TEST(Base64, decodedLength) {
    const size_t result = Base64::decodedLength("SGVsbG8gV29ybGQ=");
    ASSERT_EQ(result, strToBytes("Hello World").size());
}
