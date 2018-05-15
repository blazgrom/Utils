#pragma once
#include <type_traits>
#include "../core/void_t.hpp"
namespace utilitybz
{
    template<typename T,
    typename=void>
    struct has_call_operator : std::false_type{} ;
    
    template<typename T>
    struct has_call_operator<T,void_t<decltype(&T::operator())>> : std::true_type{};
}