#pragma once 
#include <tuple>
#include <cstddef>
namespace utilitybz{
    template<typename T>
    struct member_fn_traits{};

    template <typename R, typename C, typename... Args>
        struct member_fn_traits<R (C::*)(Args...)> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };

        template <typename R, typename C, typename... Args>
        struct member_fn_traits<R (C::*)(Args...) const> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };

        template <typename R, typename C, typename... Args>
        struct member_fn_traits<R (C::*)(Args...) volatile> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };

        template <typename R, typename C, typename... Args>
        struct member_fn_traits<R (C::*)(Args...) const volatile> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };  

         template <typename R, typename C, typename... Args>
        struct member_fn_traits<R (C::*)(Args...) &> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };

        template <typename R, typename C, typename... Args>
        struct member_fn_traits<R (C::*)(Args...) const &> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };

        template <typename R, typename C, typename... Args>
        struct member_fn_traits<R (C::*)(Args...) volatile &> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };

        template <typename R, typename C, typename... Args>
        struct member_fn_traits<R (C::*)(Args...) const volatile &> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };     

         template <typename R, typename C, typename... Args>
        struct member_fn_traits<R (C::*)(Args...) &&> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };

        template <typename R, typename C, typename... Args>
        struct member_fn_traits<R (C::*)(Args...) const &&> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };

        template <typename R, typename C, typename... Args>
        struct member_fn_traits<R (C::*)(Args...) volatile &&> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };

        template <typename R, typename C, typename... Args>
        struct member_fn_traits<R (C::*)(Args...) const volatile &&> {
            using return_type = R;
            using args_types = std::tuple<Args...>;
            static constexpr size_t args_count = sizeof...(Args);
        };

        template <typename T>
        using member_fn_return_type_t = typename member_fn_traits<T>::return_type;

        template <typename T>
        using member_fn_args_types_t = typename member_fn_traits<T>::args_types;
        
        template<typename T>
        constexpr size_t member_fn_args_count_v=member_fn_traits<T>::args_count;
}