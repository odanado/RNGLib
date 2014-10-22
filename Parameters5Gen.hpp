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

    uint32_t MAC_add1;
    uint32_t MAC_add2;
    uint32_t MAC_add3;
    uint32_t MAC_add4;
    uint32_t MAC_add5;
    uint32_t MAC_add6;
    uint32_t year;
    uint32_t month;
    uint32_t day;
    uint32_t hour;
    uint32_t minute;
    uint32_t sec;
    uint32_t week;

    uint32_t key;

public:
    inline void set_MAC_add(uint32_t m1, uint32_t m2, uint32_t m3, 
            uint32_t m4, uint32_t m5, uint32_t m6) {
        MAC_add1 = m1;
        MAC_add2 = m2;
        MAC_add3 = m3;
        MAC_add4 = m4;
        MAC_add5 = m5;
        MAC_add6 = m6;
    }

    inline void set_year(uint32_t yy) { year = yy; }
    inline void set_month(uint32_t mm) { month = mm; }
    inline void set_day(uint32_t dd) { day = dd; }

    inline void set_hour(uint32_t hh) { hour = hh; }
    inline void set_minute(uint32_t mi) { minute = mi; }
    inline void set_sec(uint32_t se) { sec = se; }

    inline void update_week() {
        // TODO 過去に書いたコードをコピペする

    }

    inline void set_key(uint32_t key_) { key = key_; }


};
} // end RNGLib

#endif
