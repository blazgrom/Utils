#pragma once
namespace utilitybz{
    #define IS_CPP_17() __cplusplus==201703L 
 
    constexpr bool is_cpp_17(){
        return IS_CPP_17();
    }

    #define IS_CPP_14() __cplusplus==201402L

    constexpr bool is_cpp_14(){
        return IS_CPP_14();
    }

    #define IS_CPP_11() __cplusplus==201103L
    
    constexpr bool is_cpp_11(){
        return IS_CPP_11();
    }
}