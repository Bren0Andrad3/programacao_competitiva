#ifndef CLOSEST_PAIR_HPP
#define CLOSEST_PAIR_HPP

#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

namespace geometry {

    struct Point {
        double x, y;

        bool operator<(const Point& p) const {
            return x < p.x || (x == p.x && y < p.y);
        }
    };

    inline double dist(const Point& a, const Point& b) {
        return std::hypot(a.x - b.x, a.y - b.y);
    }

    double closestUtil(std::vector<Point>& Px, std::vector<Point>& Py) {
        int n = Px.size();
        if (n <= 3) {
            double minD = std::numeric_limits<double>::infinity();
            for (int i = 0; i < n; ++i)
                for (int j = i + 1; j < n; ++j)
                    minD = std::min(minD, dist(Px[i], Px[j]));
            return minD;
        }

        int mid = n / 2;
        Point midPoint = Px[mid];

        std::vector<Point> Pyl, Pyr;
        for (const auto& p : Py) {
            if (p.x <= midPoint.x)
                Pyl.push_back(p);
            else
                Pyr.push_back(p);
        }

        std::vector<Point> L(Px.begin(), Px.begin() + mid);
        std::vector<Point> R(Px.begin() + mid, Px.end());

        double dl = closestUtil(L, Pyl);
        double dr = closestUtil(R, Pyr);
        double d = std::min(dl, dr);

        std::vector<Point> strip;
        for (const auto& p : Py)
            if (std::abs(p.x - midPoint.x) < d)
                strip.push_back(p);

        double minStrip = d;
        int m = strip.size();
        for (int i = 0; i < m; ++i)
            for (int j = i + 1; j < m && (strip[j].y - strip[i].y) < minStrip; ++j)
                minStrip = std::min(minStrip, dist(strip[i], strip[j]));

        return std::min(d, minStrip);
    }

    inline double closestPair(std::vector<Point> points) {
        std::vector<Point> Px = points;
        std::vector<Point> Py = points;

        std::sort(Px.begin(), Px.end(), [](const Point& a, const Point& b) {
            return a.x < b.x;
        });

        std::sort(Py.begin(), Py.end(), [](const Point& a, const Point& b) {
            return a.y < b.y;
        });

        return closestUtil(Px, Py);
    }

}

#endif // CLOSEST_PAIR_HPP
