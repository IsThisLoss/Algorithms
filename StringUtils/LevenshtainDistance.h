#pragma once

#include <string>

namespace StringUtils {

/*
 * @lhs - first string
 * @rhs - second string
 * @return Levenshtain distance between lhs and rhs
 */
std::string::size_type levenshtainDistance(const std::string& lhs, const std::string& rhs);

}
