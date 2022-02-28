#pragma once

#include <vector>
#include <string>

namespace StringUtils {

std::vector<unsigned> getPrefixFunction(const std::string& string);

/*
 * @pattern - pattern to find
 * @text - text to find in
 * @return position in text where pattern begins
 * if not found return std::string::npos
 */
std::string::size_type KmpSearch(const std::string& pattern, const std::string& text);

}
