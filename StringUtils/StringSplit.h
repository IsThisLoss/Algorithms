#ifndef SPLIT_STRINGSPLIT_H
#define SPLIT_STRINGSPLIT_H

#include <list>
#include <cstring>
#include <memory>
#include <limits>
#include <vector>

namespace StringSplit {
    constexpr size_t npos = std::numeric_limits<size_t>::max();

    /**
     * @brief split a string on substrings by separator
     * @tparam CharType is a type of characters in string
     * @param string is the pointer to string to split
     * @param sep is a separator
     * @param strLen is the string length, if strLen isn't specified, iterate 'till '\0' faced
     * @return list of unique_ptr's to CharType null-terminated strings
     */
    template <typename CharType>
    std::list<std::unique_ptr<CharType[]>> split(const CharType* string, char sep, size_t strLen = npos) {
        std::list<std::unique_ptr<CharType[]>> list;
        size_t i, size, b = 0;
        bool end = false;
        for (i = 0; !end ; i++) {
            end = (i == strLen || string[i] == '\0');
            if (end || string[i] == sep) {
                size = i - b;
                auto buf = std::make_unique<CharType[]>(size + 1);
                memcpy(buf.get(), string + b, size);
                buf[size] = '\0';
                list.push_back(std::move(buf));
                b = i + 1;
            }
        }
        return list;
    }

    template <typename CharType>
    std::vector<std::unique_ptr<CharType[]>> splitToVector(const CharType* string, char sep, size_t strLen = npos) {
        std::vector<std::unique_ptr<CharType[]>> vector;
        size_t i, size, b = 0;
        bool end = false;
        for (i = 0; !end ; i++) {
            end = (i == strLen || string[i] == '\0');
            if (end || string[i] == sep) {
                size = i - b;
                auto buf = std::make_unique<CharType[]>(size + 1);
                memcpy(buf.get(), string + b, size);
                buf[size] = '\0';
                vector.push_back(std::move(buf));
                b = i + 1;
            }
        }
        return vector;
    }


    /**
     * @brief split a string on substrings by separator
     * @tparam StringType is a type of string class
     * @param string is string to split
     * @param sep is a separator
     * @return list of StringType strings
     */
    template <class StringType>
    std::list<StringType> split(const StringType& string, char sep) {
        std::list<StringType> list;
        size_t i, size, b = 0;
        bool end = false;
        for (i = 0; !end; i++) {
            end = (i == string.size());
            if (end || string[i] == sep) {
                size = i - b;
                if (size == 0) {
                    list.emplace_back();
                } else {
                    list.emplace_back(string, b, size);
                }
                b = i + 1;
            }
        }
        return list;
    }

    template <class StringType>
    std::list<StringType> splitToVector(const StringType& string, char sep) {
        std::vector<StringType> vector;
        size_t i, size, b = 0;
        bool end = false;
        for (i = 0; !end; i++) {
            end = (i == string.size());
            if (end || string[i] == sep) {
                size = i - b;
                if (size == 0) {
                    vector.emplace_back();
                } else {
                    vector.emplace_back(string, b, size);
                }
                b = i + 1;
            }
        }
        return vector;
    }

}

#endif //SPLIT_STRINGSPLIT_H
