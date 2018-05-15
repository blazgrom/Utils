#pragma once
#include <functional>
#include "member_fn_traits.hpp"
namespace utilitybz
{
    namespace detail{
        template <typename T>
        struct callable_traits_impl
        {
            using return_type = member_fn_return_type_t<decltype(&T::operator())>;
            using args_types = member_fn_args_types_t<decltype(&T::operator())>;
            static constexpr size_t args_count =member_fn_args_count_v<decltype(&T::operator())>;
        };   
        
        template <typename R, typename... Args>
        struct callable_traits_impl<std::function<R(Args...)>> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };

        template <typename R, typename... Args>
        struct callable_traits_impl<R (*)(Args...)> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };
    }

    template <typename T>
    struct callable_traits {
        using return_type = typename detail::callable_traits_impl<T>::return_type;
        using args_types = typename detail::callable_traits_impl<T>::args_types;
        static const size_t args_count = detail::callable_traits_impl<T>::args_count;
    };

    template <typename T>
    using callable_return_type_t = typename callable_traits<T>::return_type;
    template <typename T>
    using callable_args_types_t = typename callable_traits<T>::args_types;
    template<typename T>
    constexpr size_t callable_args_count_v=callable_traits<T>::args_count;
}