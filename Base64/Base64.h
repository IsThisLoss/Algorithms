//
// Created by Dima on 24.11.2017.
//

#pragma once

#include <string>
#include <vector>

namespace Base64 {

    /**
     * @brief encode given data to base64
     * @param raw is a vector of bytes to encode
     * @return std::string with encoded data
     */
    std::string encode(const std::vector<uint8_t>& raw);

    /**
     * @brief decode base64-string to raw byte sequence
     * @param input is a base64-string with encoded data
     * @return vector of bytes with decoded messages
     * @throw std::runtime_error when input is empty or input.size() isn't multiple of 4
     */
    std::vector<uint8_t> decode(const std::string& input);

    /**
     * @brief calculate size of decoded message
     * @param input is a base64-string
     * @return the minimal number of bytes to place decoded message
     * @throw std::runtime_error when input is empty or input.size() isn't multiple of 4
     */
    size_t decodedLength(const std::string& input);
};
