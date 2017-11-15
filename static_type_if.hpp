#ifndef STATIC_TYPE_IF_HPP
#define STATIC_TYPE_IF_HPP
#include <tuple>
namespace Utils
{

    template<template<typename...>
            typename... Metafunction>
    struct metafunction_list
    {
    };
    template<typename Type,
        typename Conditions,
        typename Result,
        typename Default=void>
    struct static_type_if
    {
    };
    template<typename Type,
        template<typename...>
        typename CurrentCondition,
        template<typename...>
        typename... RemainingConditions,
        typename CurrentResult,
        typename... RemainingResults,
        typename Default>
    struct static_type_if<Type,metafunction_list<CurrentCondition,RemainingConditions...>,std::tuple<CurrentResult,RemainingResults...>,Default>
    {
    using type=typename std::conditional<CurrentCondition<Type>::value,CurrentResult,typename static_type_if<Type,metafunction_list<RemainingConditions...>,std::tuple<RemainingResults...>,Default>::type>::type;
    };
    template<typename Type,
            template<typename ...>
            typename Condition,
            typename Result,
            typename Default
            >
    struct static_type_if<Type,metafunction_list<Condition>,std::tuple<Result>,Default>
    {
    using type=typename std::conditional<Condition<Type>::value,Result,Default>::type;
    };
}
#endif