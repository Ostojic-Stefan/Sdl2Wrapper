#pragma once

struct Vec2
{
    friend Vec2 operator+(const Vec2 &lhs, const Vec2 &rhs);
    friend Vec2 operator-(const Vec2 &lhs, const Vec2 &rhs);
    int x, y;
};
