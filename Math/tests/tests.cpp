#include <gtest/gtest.h>

#include "Eval.h"

namespace Math {

namespace {

struct TestCase {
  std::string name;
  std::string input;
  std::string expected;
};

class InfixToPostfixTest : public ::testing::TestWithParam<TestCase> {};
class EvalPostfixTest : public ::testing::TestWithParam<TestCase> {};
class EvalTest : public ::testing::TestWithParam<TestCase> {};

}

TEST_P(InfixToPostfixTest, infixToPostfix) {
  auto param = GetParam();
  const auto result = infixToPostfix(param.input);
  ASSERT_EQ(result, param.expected);
}

INSTANTIATE_TEST_SUITE_P(
      /**/,
      InfixToPostfixTest,
      ::testing::Values(
        TestCase{
          .name = "empty",
          .input = "",
          .expected = "",
        },
        TestCase{
          .name = "simple_add",
          .input = "1 + 2",
          .expected = "1 2 +",
        },
        TestCase{
          .name = "simple_multiply",
          .input = "1 * 2",
          .expected = "1 2 *",
        },
        TestCase{
          .name = "order_1",
          .input = "1 + 2 * 3",
          .expected = "1 2 3 * +",
        },
        TestCase{
          .name = "order_2",
          .input = "1 * 2 + 3",
          .expected = "1 2 * 3 +",
        },
        TestCase{
          .name = "complex",
          .input = "(1+(4+5+2)-3)+(6+8)",
          .expected = "1 4 5 + 2 + + 3 - 6 8 + +",
        }
      ),
      [](const auto& info) {return info.param.name;}
);

TEST_P(EvalPostfixTest, evalPostfix) {
  auto param = GetParam();
  const int result = evalPostfix(param.input);
  ASSERT_EQ(std::to_string(result), param.expected);
}

INSTANTIATE_TEST_SUITE_P(
      /**/,
      EvalPostfixTest,
      ::testing::Values(
        TestCase{
          .name = "empty",
          .input = "",
          .expected = "0",
        },
        TestCase{
          .name = "simple_add",
          .input = "1 2 +",
          .expected = "3",
        },
        TestCase{
          .name = "simple_multiply",
          .input = "1 2 *",
          .expected = "2",
        },
        TestCase{
          .name = "order_1",
          .input = "1 2 3 * +",
          .expected = "7",
        },
        TestCase{
          .name = "order_2",
          .input = "1 2 * 3 +",
          .expected = "5",
        }
      ),
      [](const auto& info) {return info.param.name;}
);

TEST_P(EvalTest, eval) {
  auto param = GetParam();
  const int result = eval(param.input);
  ASSERT_EQ(std::to_string(result), param.expected);
}

INSTANTIATE_TEST_SUITE_P(
      /**/,
      EvalTest,
      ::testing::Values(
        TestCase{
          .name = "empty",
          .input = "",
          .expected = "0",
        },
        TestCase{
          .name = "simple_add",
          .input = "1 + 2",
          .expected = "3",
        },
        TestCase{
          .name = "simple_multiply",
          .input = "1 * 2",
          .expected = "2",
        },
        TestCase{
          .name = "order_1",
          .input = "1 + 2 * 3",
          .expected = "7",
        },
        TestCase{
          .name = "order_2",
          .input = "1 * 2 + 3",
          .expected = "5",
        },
        TestCase{
          .name = "complex",
          .input = "(1+(4+5+2)-3)+(6+8)",
          .expected = "23",
        }
      ),
      [](const auto& info) {return info.param.name;}
);

}
