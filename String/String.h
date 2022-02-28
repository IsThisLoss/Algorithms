#pragma once

#include <cstddef>
#include <iostream>

namespace String {

class String final {
public:
    String();
    ~String();

    explicit String(const char* str);
    String(const String& str);
    String(const String& str, size_t pos, size_t count);
    String& operator=(const String& str);
    String(String&& str) noexcept;
    String& operator=(String&& str) noexcept;

    void clear();

    /**
     * @return true if string is empty
     */
    bool empty() const;

    /**
     * @return current size of the string
     */
    size_t size() const;

    /**
     * @return the number of chars that string is able to store
     */
    size_t capacity() const;

    void reserve(size_t size);

    /**
     * @brief add a char to the end of the string
     * @param ch is a char to add
     */
    void pushBack(char ch);

    /**
     * @brief resize string to given size
     *
     * @param size is a new size of string
     */
    void resize(size_t size);

    void shrinkToFit();

    /**
     * @param index
     * @return reference on char on given index
     */
    char& operator[](size_t index);
    const char& operator[](size_t index) const;

    /**
     * @param index
     * @return referenc on char on given index
     *
     * @throw std::out_of_range if index >= size
     */
    char& at(size_t index);
    const char& at(size_t index) const;

    /**
     * @return raw pointer to stored null-terminated string
     */
    const char* c_str() const;
    char* data();

    bool operator==(const String& that) const;
    bool operator!=(const String& that) const;
    bool operator<(const String& that) const;
    bool operator>(const String& that) const;
    String operator+(const String& str) const;

    friend void swap(String& left, String& right);
    friend std::ostream& operator<<(std::ostream& out, const String& string);

    typedef const char* const_iterator;
    typedef char* iterator;

    inline const_iterator begin() const {
        return c_str();
    }

    inline const_iterator end() const {
        return c_str() + size();
    }

    inline iterator begin() {
        return data();
    }

    inline iterator end() {
        return data() + size();
    }
private:
    // size of allocated buffer
    // if 0 than string in short mode
    size_t dataSize;
    struct NormalMode {
        char* data;
        size_t size;
    };
    constexpr static size_t shortModeSize = sizeof(NormalMode);
    union {
        NormalMode normalMode;
        char shortMode[shortModeSize]; // 16 bytes on x64 system
    } impl;

    void move(String&& str) noexcept;

    inline bool isNormalMode() const {
        return dataSize != 0;
    }

    /*** Short Mode interface ***/
    // if the string is in short mode, store size in the last byte of union
    inline void setShortModeSize(size_t size) {
        impl.shortMode[shortModeSize - 1] = static_cast<char>(size);
    }

    static inline bool fitInShortMode(size_t size) {
        return size <= shortModeSize - 2;
    }

    void shortModeCopy(const char *str, size_t strLen);

    /*** Normal Mode interface ***/
    void normalModeCopy(const char *str, size_t strLen);
};

}
