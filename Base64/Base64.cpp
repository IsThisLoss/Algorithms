//
// Created by Dima on 24.11.2017.
//

#include "Base64.h"

#include <cmath>
#include <stdexcept>

namespace Base64 {
    namespace {
        const char* map = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

        void threeToString(const uint8_t *three, std::string &str) {
            str.push_back(map[(three[0] & 0xfc) >> 2]);
            str.push_back(map[(three[0] & 0x03) << 4 | (three[1] & 0xf0) >> 4]);
            str.push_back(map[(three[1] & 0x0f) << 2 | (three[2] & 0xc0) >> 6]);
            str.push_back(map[three[2] & 0x3f]);
        }

        uint8_t remap(char ch) {
            if ('A' <= ch && ch <= 'Z')
                return static_cast<uint8_t>(ch - 'A');
            if ('a' <= ch && ch <= 'z')
                return static_cast<uint8_t>(ch - 71); // in ASCII 'a' is 97 to map it to 26 we need to subtract 71
            if ('0' <= ch && ch <= '9')
                return static_cast<uint8_t>(ch + 4); // same, '0' is 48, to map to 52 we add 4
            if (ch == '+')
                return 62;
            if (ch == '/')
                return 63;

            throw std::runtime_error("Base64: Invalid char");
        }

        void fourToVector(const uint8_t *four, std::vector<uint8_t> &vector) {
            vector.push_back(static_cast<uint8_t>(four[0] << 2 | ((four[1] & 0x30) >> 4)));
            vector.push_back(static_cast<uint8_t>((four[1] & 0x0f) << 4 | (four[2] & 0x3c) >> 2));
            vector.push_back(static_cast<uint8_t>((four[2] & 0x03) << 6 | (four[3] & 0x3f)));
        }
    }

    std::string encode(const std::vector<uint8_t> &raw) {
        std::string out;
        out.reserve(static_cast<size_t>(ceil(raw.size() / 3.0) * 4));
        uint8_t three[3];

        size_t i = 0, j = 0;

        for (i = 0; i < raw.size(); i++) {
            three[j++] = raw[i];
            if (j == 3) {
                j = 0;
                threeToString(three, out);
            }
        }

        if (j) {
            for (i = j; i < 3; i++) {
                three[i] = '\0';
            }
            size_t s = out.size();
            threeToString(three, out);
            for (i = j; i < 3; i++) {
                out[s + i + 1] = '='; // place the same number of '=' as we've placed '\0'
            }
        }
        return out;
    }

    std::vector<uint8_t> decode(const std::string &input) {
        const size_t decodedSize = decodedLength(input);

        std::vector<uint8_t> out;
        out.reserve(decodedSize);

        uint8_t four[4];
        size_t i = 0, j = 0;

        for (i = 0; i < input.size(); i++) {
            if (input[i] == '=')
                break;

            four[j++] = remap(input[i]);
            if (j == 4) {
                j = 0;
                fourToVector(four, out);
            }
        }

        if (j) {
            for (i = j; i < 4; i++) {
                four[i] = 0;
            }

            std::vector<uint8_t> tmp;
            tmp.reserve(3);
            fourToVector(four, tmp);
            for (i = 0; i < j - 1; i++) {
                out.push_back(tmp[i]);
            }
        }
        return out;
    }

    size_t decodedLength(const std::string &input) {
        if (input.length() % 4) {
            throw std::runtime_error("Base64: Invalid base64-string size");
        }

        size_t count = 0;
        for (auto i = input.rbegin(); i != input.rend() && *i == '='; i++) {
            count++;
        }

        return (input.length() / 4 * 3) - count;
    }
}
