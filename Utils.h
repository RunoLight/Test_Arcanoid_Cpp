#pragma once
#include <utility>

#define POINT std::pair<float, float>

inline bool isIntersect(const POINT pos1, const POINT size1, const POINT pos2, const POINT size2)
{
    const auto leftBottom1 = POINT(pos1.first - size1.first / 2, pos1.second - size1.second / 2);
    const auto rightUp1 = POINT(pos1.first + size1.first / 2, pos1.second + size1.second / 2);

    const auto leftBottom2 = POINT(pos2.first - size1.first / 2, pos2.second - size2.second / 2);
    const auto rightUp2 = POINT(pos2.first + size2.first / 2, pos2.second + size2.second / 2);

    if (leftBottom1.first >= leftBottom2.first && leftBottom1.first <= rightUp2.first ||
        rightUp1.first >= leftBottom2.first && rightUp1.first <= rightUp2.first )
    {
        if (leftBottom1.second >= leftBottom2.second && leftBottom1.second <= rightUp2.second ||
            rightUp1.second >= leftBottom2.second && rightUp1.second <= rightUp2.second)
        {
            return true;
        }
    }

    return false;
}