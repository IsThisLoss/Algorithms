//
// Created by Dima on 15.10.2017.
//

#pragma once

#include <vector>
#include <string>

std::vector<unsigned> getPrefixFunction(const std::string& string) {
    std::vector<unsigned> prefixFunction(string.size(), 0);
    unsigned k;
    for (unsigned i = 1; i < string.size(); i++) {
        k = prefixFunction[i-1];
        while (k > 0 && string[i] != string[k])
            k = prefixFunction[k-1];
        if (string[i] == string[k])
            k = k + 1;
        prefixFunction[i] = k;
    }
    return prefixFunction;
}

std::string::size_type KmpSearch(const std::string& pattern, const std::string& text) {
    std::string::size_type index = std::string::npos;
    std::vector<unsigned> prefixFunction = getPrefixFunction(pattern);
    unsigned k = 0;
    for (unsigned i = 0; i < text.size(); i++) {
        while (k > 0 && pattern[k] != text[i])
            k = prefixFunction[k-1];
        if (pattern[k] == text[i])
            k = k + 1;
        if (k == pattern.size()) {
            index = i - pattern.size() + 1;
            break;
        }
    }
    return index;
}
