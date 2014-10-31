/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */


#ifndef INCLUDED_LCG_HPP
#define INCLUDED_LCG_HPP
#include <cstdint>
#include <type_traits>
#include "Config.hpp"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4307)
#endif

namespace RNGLib {
template<typename UIntType_, UIntType_ mul_, UIntType_ add_, UIntType_ mask_>
class LCG {
public:
    typedef UIntType_ UIntType;
private:
    RNGLIB_STATIC_CONSTEXPR UIntType calc_pow(UIntType a, UIntType n, UIntType mask) {
        return n == 0 ? 1 :
            (n & 1 ? a : 1) * calc_pow((a*a)&mask, n >> 1, mask);
    }
    RNGLIB_STATIC_CONSTEXPR UIntType calc_inverse(UIntType mul, UIntType mask) {
        return calc_pow(mul, mask >> 1, mask);
    }

    RNGLIB_STATIC_CONSTEXPR UIntType skip_lcg_impl(UIntType s, UIntType n, UIntType a, UIntType b) {
        return n == 0 ? 
            s :
            n & 1 ? 
                skip_lcg_impl(a * s + b ,n >> 1, a * a, a * b + b) :
                skip_lcg_impl(s , n >> 1, a * a, a * b + b);
    }

    /*
     * 参考
     * http://d.hatena.ne.jp/oupo/20121122/1353554591
     */
    RNGLIB_STATIC_CONSTEXPR UIntType calc_index_impl(UIntType s, UIntType n) {
        return n == sizeof(UIntType) * 8 ?
            0 :
            (s >> n) & 1 ?
                (calc_index_impl(next_n(s, 1ULL << n), n + 1) * 2 - 1) & (mask >> n) :
                calc_index_impl(s, n + 1) * 2;
    }
    

    template<class T, class A, class B, class C>
    struct calc_pow_tmp;

    template<class T,T A, T MASK, T N>
    struct calc_pow_tmp <
        T,
        std::integral_constant<T, A>, 
        std::integral_constant<T, MASK>,
        std::integral_constant<T,N> >  {
            RNGLIB_STATIC_CONSTEXPR_OR_CONST T value = (N & 1 ? A : 1) * 
                calc_pow_tmp<
                    T,
                    std::integral_constant<T, (A * A) & MASK>, 
                    std::integral_constant<T, MASK>, 
                    std::integral_constant<T, (N >> 1)> 
                >::value;
    };

    template<class T, T A, T MASK> 
    struct calc_pow_tmp<
        T,
        std::integral_constant<T, A>,
        std::integral_constant<T, MASK>,
        std::integral_constant<T,0> > {
            RNGLIB_STATIC_CONSTEXPR_OR_CONST T value = 1;
    };

    template<class T, T A, T MASK>
    struct calc_inverse_tmp {
        RNGLIB_STATIC_CONSTEXPR_OR_CONST T value = 
#       ifdef _MSC_VER
            calc_pow_tmp<T, 
            std::integral_constant<T, A>,
            std::integral_constant<T, MASK>,
            std::integral_constant<T, (MASK >> 1) > >::value;
#       else
            calc_inverse(mul_, mask_);
#       endif

    };


public:
    RNGLIB_CONSTEXPR LCG() { }
    RNGLIB_STATIC_CONSTEXPR_OR_CONST UIntType mul = mul_;
    RNGLIB_STATIC_CONSTEXPR_OR_CONST UIntType add = add_;

    RNGLIB_STATIC_CONSTEXPR_OR_CONST UIntType mask = mask_;

    RNGLIB_STATIC_CONSTEXPR_OR_CONST UIntType div = calc_inverse_tmp<UIntType, mul, mask>::value;
    RNGLIB_STATIC_CONSTEXPR_OR_CONST UIntType sub = ~(div * add) + 1;

    RNGLIB_STATIC_CONSTEXPR UIntType next(UIntType s) {
        return ((s * mul) + add) & mask;
    }
    RNGLIB_STATIC_CONSTEXPR UIntType prev(UIntType s) {
        return ((s * div) + sub) & mask;
    }
    
    RNGLIB_STATIC_CONSTEXPR UIntType next_n(UIntType s, UIntType n) {
        return skip_lcg_impl(s,n,mul,add);
    }

    RNGLIB_STATIC_CONSTEXPR UIntType prev_n(UIntType s, UIntType n) {
        return skip_lcg_impl(s,n,div,sub);
    }

    RNGLIB_STATIC_CONSTEXPR UIntType calc_index(UIntType s) {
        return calc_index_impl(s, 0);
    } 

};
typedef LCG<uint64_t, 0x5D588B656C078965, 0x269EC3, 0xFFFFFFFFFFFFFFFF> LCG5Gen;
typedef LCG<uint32_t, 0x41C64E6D, 0x6073, 0xFFFFFFFF> LCG4Gen;
typedef LCG<uint32_t, 0x41C64E6D, 0x6073, 0xFFFFFFFF> LCG3Gen;

typedef LCG<uint64_t, 0x5D583D6D6C078979, 0x26A693, 0xFFFFFFFFFFFFFFFF> LCG5GenDaily;

} // end RNGLib


#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif
