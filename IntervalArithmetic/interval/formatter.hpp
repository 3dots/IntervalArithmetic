


#ifndef BOOST_NUMERIC_INTERVAL_HPP_FORMATTER
#define BOOST_NUMERIC_INTERVAL_HPP_FORMATTER

#include <ostream>
#include "boost/numeric/interval.hpp"

namespace boost {
namespace numeric {

    template<class T, class Policies> inline
    std::ostream& operator<<(std::ostream& os, const interval<T, Policies>& x) {
        os << "Median: " << median(x) << " "
            << "Error: " << (width(x) / 2) << " "
            << "Lower: " << x.lower() << " "
            << "Upper: " << x.upper();
        return os;
    }

} // namespace numeric
} // namespace boost

#endif // BOOST_NUMERIC_INTERVAL_HPP_FORMATTER