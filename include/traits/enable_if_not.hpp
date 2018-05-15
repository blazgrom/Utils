#pragma once
#include <type_traits>
namespace utilitybz{
    template<bool B,typename T=void>
    struct enable_if_not:public std::enable_if<!B,T>
    {};

    template<bool B,typename T=void>
    using enable_if_not_t=typename enable_if_not<B,T>::type;
}