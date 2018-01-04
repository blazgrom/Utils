#ifndef HAS_OPERATOR_CALL_HPP
#define HAS_OPERATOR_CALL_HPP
#include <type_traits>
#include "void_t.hpp"
namespace Utils
{
   
    template<typename T,
    typename=void>
    struct has_operator_call : std::false_type{} ;
    template<typename T>
    struct has_operator_call<T,void_t<decltype(&T::operator())>> : std::true_type
    {};
}
#endif