#include "Xrange.h"

namespace Xrange {
    /*** Iterator ***/

    XRangeIterator::XRangeIterator(int _current, int _step)
            : current(_current)
            , step(_step)
    {}

    bool XRangeIterator::operator!=(const Xrange::XRangeIterator &rhs) const {
        return current != rhs.current;
    }

    int XRangeIterator::operator*() {
        return current;
    }

    XRangeIterator& XRangeIterator::operator++() {
        current += step;
        return *this;
    }

    /*** Range ***/

    XRange::XRange(int _start, int _stop, int _step)
            : start(_start, _step)
            , stop(_stop, _step)
    {}

    XRangeIterator XRange::begin() {
        return start;
    }

    XRangeIterator XRange::end() {
        return stop;
    }
}
