#ifndef CALLABLE_TRAITS_HPP
#define CALLABLE_TRAITS_HPP
#include <functional>
#include "has_operator_call.hpp"
namespace Utils
{
template <typename T>
struct callable_traits_impl  // Intermediary for typenamees and lambdas
{
  private:
    template <typename R,
              typename C = T,
              typename... Args>
    static constexpr auto get_operator_call(R (C::*op)(Args...))
    {
        return op;
    }
  public:
    using return_type = typename callable_traits_impl<decltype(
        get_operator_call(&T::operator()))>::return_type;
    using args = typename callable_traits_impl<decltype(
        get_operator_call(&T::operator()))>::args;
    static const size_t args_count =
        callable_traits_impl<decltype(get_operator_call(&T::operator()))>::args_count;
};

template <typename R, typename... Args>
struct callable_traits_impl<std::function<R(Args...)>> {
    using return_type = R;
    using args = std::tuple<Args...>;
    static const size_t args_count = sizeof...(Args);
};
template <typename R, typename... Args>
struct callable_traits_impl<R (*)(Args...)> {
    using return_type = R;
    using args = std::tuple<Args...>;
    static const size_t args_count = sizeof...(Args);
};
template <typename R, typename C, typename... Args>
struct callable_traits_impl<R (C::*)(Args...) const volatile> {
    using return_type = R;
    using args = std::tuple<Args...>;
    static const size_t args_count = sizeof...(Args);
};
template <typename R, typename C, typename... Args>
struct callable_traits_impl<R (C::*)(Args...) const> {
    using return_type = R;
    using args = std::tuple<Args...>;
    static const size_t args_count = sizeof...(Args);
};
template <typename R, typename C, typename... Args>
struct callable_traits_impl<R (C::*)(Args...) volatile> {
    using return_type = R;
    using args = std::tuple<Args...>;
    static const size_t args_count = sizeof...(Args);
};
template <typename R, typename C, typename... Args>
struct callable_traits_impl<R (C::*)(Args...)> {
    using return_type = R;
    using args = std::tuple<Args...>;
    static const size_t args_count = sizeof...(Args);
};
template <typename T>
struct callable_traits {
    using return_type = typename callable_traits_impl<T>::return_type;
    using args = typename callable_traits_impl<T>::args;
    static const size_t args_count = callable_traits_impl<T>::args_count;
};
template <typename T>
using callable_return_type = typename callable_traits<T>::return_type;
template <typename T>
using callable_arg_types = typename callable_traits<T>::args;
}
#endif  // !CALLABLE_TRAITS_HPP