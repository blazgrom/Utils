#pragma once
namespace utilitybz
{
    #if __cplusplus==201703L
    #include <type_traits>
    using std::void_t;
    #else
    template<typename...>
    using void_t=void;
    #endif
}