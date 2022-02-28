#pragma once

namespace Xrange {

class XRangeIterator {
public:
    XRangeIterator(int _current, int _step);

    bool operator!=(const XRangeIterator& rhs) const;

    int operator*();

    XRangeIterator& operator++();
private:
    int current;
    int step;
};

class XRange {
public:
    XRange(int _start, int _stop, int _step);

    XRangeIterator begin();

    XRangeIterator end();
private:
    XRangeIterator start;
    XRangeIterator stop;
};

inline XRange xrange(int stop) {
    return XRange(0, stop, 1);
}

inline XRange xrange(int start, int stop) {
    return XRange(start, stop, 1);
}

inline XRange xrange(int start, int stop, int step) {
    return XRange(start, stop, step);
}

}
