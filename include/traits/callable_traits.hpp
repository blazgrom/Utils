#pragma once
#include <functional>
namespace utilitybz
{
    namespace detail{
        template <typename T>
        struct callable_traits_impl
        {
            using return_type = typename callable_traits_impl<decltype(&T::operator())>::return_type;
            using args_types = typename callable_traits_impl<decltype(&T::operator())>::args;
            static constexpr size_t args_count =callable_traits_impl<decltype(&T::operator())>::args_count;
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

        template <typename R, typename C, typename... Args>
        struct callable_traits_impl<R (C::*)(Args...)> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };

        template <typename R, typename C, typename... Args>
        struct callable_traits_impl<R (C::*)(Args...) const> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };

        template <typename R, typename C, typename... Args>
        struct callable_traits_impl<R (C::*)(Args...) volatile> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };

        template <typename R, typename C, typename... Args>
        struct callable_traits_impl<R (C::*)(Args...) const volatile> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };  

         template <typename R, typename C, typename... Args>
        struct callable_traits_impl<R (C::*)(Args...) &> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };

        template <typename R, typename C, typename... Args>
        struct callable_traits_impl<R (C::*)(Args...) const &> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };

        template <typename R, typename C, typename... Args>
        struct callable_traits_impl<R (C::*)(Args...) volatile &> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };

        template <typename R, typename C, typename... Args>
        struct callable_traits_impl<R (C::*)(Args...) const volatile &> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };     

         template <typename R, typename C, typename... Args>
        struct callable_traits_impl<R (C::*)(Args...) &&> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };

        template <typename R, typename C, typename... Args>
        struct callable_traits_impl<R (C::*)(Args...) const &&> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };

        template <typename R, typename C, typename... Args>
        struct callable_traits_impl<R (C::*)(Args...) volatile &&> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };

        template <typename R, typename C, typename... Args>
        struct callable_traits_impl<R (C::*)(Args...) const volatile &&> {
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
    using callable_return_type = typename callable_traits<T>::return_type;
    template <typename T>
    using callable_args_types = typename callable_traits<T>::args_types;
    template<typename T>
    constexpr size_t callable_args_count=callable_traits<T>::args_count;
}