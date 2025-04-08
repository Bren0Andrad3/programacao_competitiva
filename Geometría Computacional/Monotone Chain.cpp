#ifndef CONVEX_HULL_HPP
#define CONVEX_HULL_HPP

#include <vector>
#include <algorithm>

namespace geometry {

    struct Point {
        int x, y;

        bool operator<(const Point& p) const {
            return x < p.x || (x == p.x && y < p.y);
        }
    };

    inline int cross(const Point& A, const Point& B, const Point& C) {
        return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
    }

    inline std::vector<Point> convexHull(std::vector<Point> points) {
        int n = points.size();
        if (n <= 1) return points;

        std::sort(points.begin(), points.end());

        std::vector<Point> lower, upper;

        for (const Point& p : points) {
            while (lower.size() >= 2 && cross(lower[lower.size()-2], lower[lower.size()-1], p) <= 0)
                lower.pop_back();
            lower.push_back(p);
        }

        for (int i = n - 1; i >= 0; --i) {
            Point p = points[i];
            while (upper.size() >= 2 && cross(upper[upper.size()-2], upper[upper.size()-1], p) <= 0)
                upper.pop_back();
            upper.push_back(p);
        }

        lower.pop_back();
        upper.pop_back();

        lower.insert(lower.end(), upper.begin(), upper.end());
        return lower;
    }

}

#endif
