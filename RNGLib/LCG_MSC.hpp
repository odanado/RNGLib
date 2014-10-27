/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */


#ifndef INCLUDED_LCG_MSC_HPP
#define INCLUDED_LCG_MSC_HPP
#include <cstdint>

namespace RNGLib {
template<typename UIntType_, UIntType_ mul_, UIntType_ add_, UIntType_ mask_>
class LCG {
public:
    typedef UIntType_ UIntType;
private:


    UIntType mul;
    UIntType add;

    UIntType mask;

    UIntType div;
    UIntType sub;


    inline UIntType calc_pow(UIntType a, UIntType n, UIntType mask) const {
        return n == 0 ? 1 :
            (n & 1 ? a : 1) * calc_pow((a*a)&mask, n >> 1, mask);
    }
    inline UIntType calc_inverse(UIntType mul, UIntType mask) const {
        return calc_pow(mul, mask >> 1, mask);
    }

    UIntType skip_lcg_impl(UIntType s, UIntType n,
            UIntType a, UIntType b) const {
        return n == 0 ? s :
            n & 1 ? skip_lcg_impl(a*s+b,n>>1,a*a,a*b+b) :
            skip_lcg_impl(s,n>>1,a*a,a*b+b);

    }

    /*
     * ŽQl
     * http://d.hatena.ne.jp/oupo/20121122/1353554591
     */
    UIntType calc_index_impl(UIntType s, UIntType n) const {
        return n == sizeof(UIntType) * 8 ?
            0 :
            (s >> n) & 1 ?
                (calc_index_impl(next_n(s, 1ULL << n), n + 1)
                    * 2 - 1) & (mask >> n) :
                calc_index_impl(s, n + 1) * 2;
    }

public:
    LCG() :
        mul(mul_), add(add_), mask(mask_), div(calc_inverse(mul_, mask_)), sub(~(div * add) + 1) {}


    inline UIntType next(UIntType s) const {
        return ((s * mul) + add) & mask;
    }
    inline UIntType prev(UIntType s) const {
        return ((s * div) + sub) & mask;
    }
    
    UIntType next_n(UIntType s, UIntType n) const {
        return skip_lcg_impl(s,n,mul,add);
    }

    UIntType prev_n(UIntType s, UIntType n) const {
        return skip_lcg_impl(s,n,div,sub);
    }

    UIntType calc_index(UIntType s) const {
        return calc_index_impl(s, 0);
    } 

    inline UIntType get_mul() const { return mul; }
    inline UIntType get_add() const { return add; }
    inline UIntType get_mask() const { return mask; }
    inline UIntType get_div() const { return div; }
    inline UIntType get_sub() const { return sub; }

};
typedef LCG<uint64_t, 0x5D588B656C078965, 0x269EC3, 0xFFFFFFFFFFFFFFFF> LCG5Gen;
typedef LCG<uint32_t, 0x41C64E6D, 0x6073, 0xFFFFFFFF> LCG4Gen;
typedef LCG<uint32_t, 0x41C64E6D, 0x6073, 0xFFFFFFFF> LCG3Gen;

typedef LCG<uint64_t, 0x5D583D6D6C078979, 0x26A693, 0xFFFFFFFFFFFFFFFF> LCG5GenDaily;

} // end RNGLib

#endif
