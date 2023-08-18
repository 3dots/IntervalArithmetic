#pragma once
#include <iostream>
#include <vector>
#include "interval/interval.hpp"

using namespace boost::numeric;
using namespace interval_lib;

class Succession
{
private:

	const int POINTS_NO = 300;

    const int M1 = 1000;
    const int N1 = 500;

    std::vector<double> linspace(double start, double end, int numPoints) {
        std::vector<double> result;
        double step = (end - start) / (numPoints - 1);

        for (int i = 0; i < numPoints; ++i) {
            double value = start + step * i;
            result.push_back(value);
        }

        return result;
    }

    interval<double> dist(double p, int m, int n) {
        if (p <= 0 || p >= 1) return 0;

        interval<double> pI = p;
        interval<double> p1mp = interval<double>(1) - pI;

        if (n > m) {
            int tempInt = m;
            m = n;
            n = tempInt;
            
            interval<double> tempI = pI;
            pI = p1mp;
            p1mp = pI;
        }

        interval<double> factor = interval<double>(1);
        for (int n1 = 1; n1 <= n; n1++) {
            interval<double> num = interval<double>(m + n1) * pI * p1mp;
            interval<double> denom = interval<double>(n1);
            factor *= num / denom;
        }
        
        factor *= interval<double>(m + n + 1) * pow(pI, m - n);
        
        return factor;
    }

    interval<double> dist1(double p) {
        return dist(p, M1, N1);
    }

public:
    void run() {

        std::vector<double> values = linspace(0.0, 1.0, POINTS_NO);

        for (double el : values) {
            std::cout << el << " " << dist1(el) << "\n";
        }
    }
};

