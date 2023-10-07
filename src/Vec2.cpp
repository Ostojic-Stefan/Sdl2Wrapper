#include "Vec2.hpp"

Vec2 operator+(const Vec2 &lhs, const Vec2 &rhs)
{
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}

Vec2 operator-(const Vec2 &lhs, const Vec2 &rhs)
{
    return {lhs.x - rhs.x, lhs.y - rhs.y};
}
