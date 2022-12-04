#pragma once

#include <string>

namespace Math {

std::string infixToPostfix(const std::string& data);

int evalPostfix(const std::string& data);

int eval(const std::string& data);

}
