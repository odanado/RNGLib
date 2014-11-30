/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */

#ifndef INCLUDED_PARAMETERS_5GEN_BASE_HPP
#define INCLUDED_PARAMETERS_5GEN_BASE_HPP
#include "Config.hpp"

namespace RNGLib {
template<u32 nazo1_, u32 nazo2_, u32 nazo3_, u32 nazo4_, u32 nazo5_, u32 vcount_, u32 gxstat_, u32 frame_, u32 timer0_min_, u32 timer0_max_>
class ConstantParameters5Gen {
public:
    RNGLIB_STATIC_CONSTEXPR_OR_CONST u32 nazo1 = nazo1_;
    RNGLIB_STATIC_CONSTEXPR_OR_CONST u32 nazo2 = nazo2_;
    RNGLIB_STATIC_CONSTEXPR_OR_CONST u32 nazo3 = nazo3_;
    RNGLIB_STATIC_CONSTEXPR_OR_CONST u32 nazo4 = nazo4_;
    RNGLIB_STATIC_CONSTEXPR_OR_CONST u32 nazo5 = nazo5_;

    RNGLIB_STATIC_CONSTEXPR_OR_CONST u32 vcount = vcount_;
    RNGLIB_STATIC_CONSTEXPR_OR_CONST u32 gxstat = gxstat_;
    RNGLIB_STATIC_CONSTEXPR_OR_CONST u32 frame = frame_;
    RNGLIB_STATIC_CONSTEXPR_OR_CONST u32 timer0_min = timer0_min_;
    RNGLIB_STATIC_CONSTEXPR_OR_CONST u32 timer0_max = timer0_max_;
};
} // end RNGLib

#endif
