#pragma once

#include <string_view>
#include <iostream>

namespace util
{
    inline void panic(std::string_view msg)
    {
        std::cerr << msg << std::endl;
        exit(1);
    }

} // namespace util
