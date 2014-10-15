/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */
#ifndef INCLUDED_PARAMETERS_5GEN_HPP
#define INCLUDED_PARAMETERS_5GEN_HPP
#include <cstdint>

namespace RNGLib {
template<uint32_t nazo1_, uint32_t nazo2_, uint32_t nazo3_, uint32_t nazo4_, uint32_t nazo5_,
         uint32_t VCount_, uint32_t Timer0_, uint32_t GxStat_, uint32_t Frame_>
class Parameters5Gen {
private:
    uint32_t nazo1 = nazo1_;
    uint32_t nazo2 = nazo2_;
    uint32_t nazo3 = nazo3_;
    uint32_t nazo4 = nazo4_;
    uint32_t nazo5 = nazo5_;

    uint32_t VCount = VCount_;
    uint32_t Timer0 = Timer0_;
    uint32_t GxStat = GxStat_;
    uint32_t Frame  = Frame_;


};
} // end RNGLib

#endif
