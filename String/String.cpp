#include "String.h"

#include <cstring>
#include <stdexcept>
#include <iostream>
#include <cassert>


String::String() : dataSize(0) {
    impl.shortMode[0] = '\0';
    setShortModeSize(0);
}

String::~String() {
    clear();
}

String::String(const char* str) {
    size_t strLen = strlen(str);
    if (fitInShortMode(strLen)) {
        shortModeCopy(str, strLen);
    } else {
        dataSize = 0;
        normalModeCopy(str, strLen);
    }
}

String::String(const String& str) {
    auto strLen = str.size();
    if (str.isNormalMode()) {
        dataSize = 0;
        normalModeCopy(str.impl.normalMode.data, strLen);
    } else {
        shortModeCopy(str.impl.shortMode, strLen);
    }
}

String::String(const String& str, size_t pos, size_t count) {
    if (pos > str.size()) {
        throw std::out_of_range("String: wrong pos");
    }

    if (count > str.size()) {
        count = str.size() - pos;
    }

    if (fitInShortMode(count)) {
        shortModeCopy(str.c_str() + pos, count);
    } else {
        dataSize = 0;
        normalModeCopy(str.impl.normalMode.data + pos, count);
    }
}

String& String::operator=(const String& str) {
    if (this == &str) { // avoid self assignment
        return *this;
    }

    auto strLen = str.size();
    clear();
    if (str.isNormalMode()) {
        normalModeCopy(str.impl.normalMode.data, strLen);
    } else {
        shortModeCopy(str.impl.shortMode, strLen);
    }
    return *this;
}

void String::reserve(size_t nsize) { // nsize is the max string size with current dataSize
    if (nsize < capacity())
        return;

    auto buf = new char[nsize + 1]; // for '\0'
    auto usedSpace = size() + 1; // to copy '\0' with chars
    if (isNormalMode()) {
        memcpy(buf, impl.normalMode.data, usedSpace);
        delete [] impl.normalMode.data;
    } else {
        memcpy(buf, impl.shortMode, usedSpace);
    }

    impl.normalMode.data = buf;
    impl.normalMode.size = usedSpace - 1;
    dataSize = nsize + 1;
}

void String::normalModeCopy(const char* str, size_t strLen) {
    reserve(strLen);
    memcpy(impl.normalMode.data, str, strLen); // copy without '\0'
    impl.normalMode.size = strLen;
    impl.normalMode.data[strLen] = '\0';
}

void String::shortModeCopy(const char* str, size_t strLen) {
    dataSize = 0; // turn string into shortMode
    memcpy(impl.shortMode, str, strLen); // copy only chars
    impl.shortMode[strLen] = '\0';
    setShortModeSize(strLen);
}

String::String(String&& str) noexcept {
    move(std::move(str));
}

String& String::operator=(String&& str) noexcept {
    assert(this != &str);
    // actually I don't know how to avoid self assignment with move
    // Is self assignment even possible?
    clear();
    move(std::move(str));
    return  *this;
}

void String::move(String&& str) noexcept {
    memcpy(impl.shortMode, str.impl.shortMode, shortModeSize);
    dataSize = str.dataSize;

    str.dataSize = 0;
    str.setShortModeSize(0);
}

void String::clear() {
    if (isNormalMode()) {
        delete [] impl.normalMode.data;
        impl.normalMode.size = 0;
        dataSize = 0;
    }

    impl.shortMode[0] = '\0';
    setShortModeSize(0);
}

size_t String::size() const {
    if (isNormalMode()) {
        return impl.normalMode.size;
    }
    // for short mode store current size in last byte
    return static_cast<size_t>(impl.shortMode[shortModeSize - 1]);
}

size_t String::capacity() const {
    if (isNormalMode()) {
        return dataSize - 1;
    }
    return shortModeSize - 2;
}

void String::pushBack(char ch) {
    auto currentSize = size();
    auto currentCapacity = capacity();

    if (currentSize + 1 > currentCapacity) {
        reserve(2 * currentCapacity); // by two times
    }

    if (isNormalMode()) {
        impl.normalMode.data[currentSize++] = ch;
        impl.normalMode.data[currentSize] = '\0';
        impl.normalMode.size = currentSize;
    } else {
        impl.shortMode[currentSize++] = ch;
        impl.shortMode[currentSize] = '\0';
        setShortModeSize(currentSize);
    }
}

void String::resize(size_t size) {
    auto thisSize = this->size();
    if (size > thisSize) { // increase string size
        reserve(size);
        for (size_t i = thisSize; i <= size; i++) {
            impl.normalMode.data[i] = '\0';
        }
        impl.normalMode.size = size;
    } else { // decrease size
        if (isNormalMode()) {
            if (fitInShortMode(size)) {
                auto buf = impl.normalMode.data;
                shortModeCopy(buf, size);
                delete [] buf;
            } else {
                impl.normalMode.data[size] = '\0';
                impl.normalMode.size = size;
            }
        } else {
            impl.shortMode[size] = '\0';
            setShortModeSize(size);
        }
    }
}

void String::shrinkToFit() {
    if (isNormalMode()) {
        auto bufSize = size() + 1;
        auto buf = new char[bufSize];
        memcpy(buf, impl.normalMode.data, bufSize);
        delete [] impl.normalMode.data;

        impl.normalMode.data = buf;
        impl.normalMode.size = bufSize - 1;
        dataSize = bufSize;
    }
}

char& String::operator[](size_t index) {
    if (isNormalMode()) {
        return impl.normalMode.data[index];
    }
    return impl.shortMode[index];
}

const char& String::operator[](size_t index) const {
    if (isNormalMode()) {
        return impl.normalMode.data[index];
    }
    return impl.shortMode[index];
}

char& String::at(size_t index) {
    if (index < size()) {
        return operator[](index);
    }
    throw std::out_of_range("String: index < size");
}

const char& String::at(size_t index) const {
    if (index < size()) {
        return operator[](index);
    }
    throw std::out_of_range("String: index < size");
}

const char* String::c_str() const {
    if (isNormalMode()) {
        return impl.normalMode.data;
    }
    return impl.shortMode;
}

char* String::data() {
    if (isNormalMode()) {
        return impl.normalMode.data;
    }
    return impl.shortMode;
}

bool String::operator==(const String& that) const {
    return strcmp(this->c_str(), that.c_str()) == 0;
}

bool String::operator!=(const String& that) const {
    return strcmp(this->c_str(), that.c_str()) != 0;
}

bool String::operator<(const String& that) const {
    return strcmp(this->c_str(), that.c_str()) < 0;
}

bool String::operator>(const String& that) const {
    return strcmp(this->c_str(), that.c_str()) > 0;
}

String String::operator+(const String& str) const {
    String res;
    auto thisSize = size();
    auto strSize = str.size();
    if (thisSize + strSize > shortModeSize - 2) {
        res.reserve(thisSize + strSize);
        memcpy(res.impl.normalMode.data, c_str(), thisSize);
        memcpy(res.impl.normalMode.data + thisSize, str.c_str(), strSize + 1);
        res.impl.normalMode.size = thisSize + strSize;
    } else {
        memcpy(res.impl.normalMode.data, impl.shortMode, thisSize);
        memcpy(res.impl.normalMode.data + thisSize, str.impl.shortMode, strSize + 1);
        res.setShortModeSize(thisSize + strSize);
    }
    return res;
}

void swap(String& left, String& right) {
    std::swap(left.impl, right.impl);
    std::swap(left.dataSize, right.dataSize);
}

std::ostream& operator<<(std::ostream& out, const String& string) {
    out << string.c_str();
    return out;
}
