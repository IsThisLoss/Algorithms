#include "Eval.h"

#include <stack>
#include <stdexcept>
#include <vector>

namespace Math {

namespace {

bool isOperator(char ch) {
  return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int getPriority(char ch) {
  switch (ch) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '(':
    case ')':
      return -1;
  }
  throw std::runtime_error{"Unknow operator: " + std::to_string(ch)};
}

int apply(int lhs, int rhs, char op) {
  switch (op) {
    case '+':
      return lhs + rhs;
    case '-':
      return lhs - rhs;
    case '*':
      return lhs * rhs;
    case '/':
      return lhs / rhs;
  };
  throw std::runtime_error{"Unknow operator: " + std::to_string(op)};
}

}

std::string infixToPostfix(const std::string& data) {
  std::vector<std::string> tokens;
  std::stack<char> stack;
  for (size_t i = 0; i < data.size(); i++) {
    if (data[i] == ' ') {
      continue;
    }
    if (data[i] == '(') {
      stack.push(data[i]);
      continue;
    }
    if (data[i] == ')') {
      while (!stack.empty() && stack.top() != '(') {
        tokens.push_back(std::string{stack.top()});
        stack.pop();
      }
      if (!stack.empty() && stack.top() == '(') {
        stack.pop();
      }
      continue;
    }
    if (isOperator(data[i])) {
      while (!stack.empty() && getPriority(stack.top()) >= getPriority(data[i])) {
        tokens.push_back(std::string{stack.top()});
        stack.pop();
      }
      stack.push(data[i]);
      continue;
    }
    std::string token;
    while (i < data.size() && std::isdigit(data[i])) {
      token.push_back(data[i++]);
    }
    i--;
    tokens.push_back(token);
  }
  while (!stack.empty()) {
    tokens.push_back(std::string{stack.top()});
    stack.pop();
  }

  std::string result;
  bool is_first = true;
  for (const auto& token : tokens) {
    if (!is_first) {
      result.push_back(' ');
    }
    result.append(token);
    is_first = false;
  }

  return result;
}

int evalPostfix(const std::string& data) {
  std::stack<int> tokens;
  for (size_t i = 0; i < data.size(); i++) {
    if (data[i] == ' ') {
      continue;
    }
    if (isOperator(data[i])) {
      int rhs = tokens.top();
      tokens.pop();
      int lhs = 0;
      if (!tokens.empty()) {
        lhs = tokens.top();
        tokens.pop();
      }
      tokens.push(apply(lhs, rhs, data[i]));
      continue;
    }
    std::string token;
    while (i < data.size() && std::isdigit(data[i])) {
      token.push_back(data[i++]);
    }
    i--;
    tokens.push(std::stoi(token));
  }
  if (tokens.empty()) {
    return 0;
  }
  return tokens.top();
}

int eval(const std::string& data) {
  return evalPostfix(infixToPostfix(data));
}

}
