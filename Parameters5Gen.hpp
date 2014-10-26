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

    uint32_t key;

public:
    void set_MAC_add(uint32_t m1, uint32_t m2, uint32_t m3, 
            uint32_t m4, uint32_t m5, uint32_t m6) {
        MAC_add1 = m1;
        MAC_add2 = m2;
        MAC_add3 = m3;
        MAC_add4 = m4;
        MAC_add5 = m5;
        MAC_add6 = m6;
    }

    void set_year(uint32_t yy) { year = yy; }
    void set_month(uint32_t mm) { month = mm; }
    void set_day(uint32_t dd) { day = dd; }

    void set_hour(uint32_t hh) { hour = hh; }
    void set_minute(uint32_t mi) { minute = mi; }
    void set_sec(uint32_t se) { sec = se; }


    void set_key(uint32_t key_) { key = key_; }
    void set_Timer0(uint32_t tt) { Timer0 = tt; }

    uint32_t get_MAC_add1() { return MAC_add1; }
    uint32_t get_MAC_add2() { return MAC_add2; }
    uint32_t get_MAC_add3() { return MAC_add3; }
    uint32_t get_MAC_add4() { return MAC_add4; }
    uint32_t get_MAC_add5() { return MAC_add5; }
    uint32_t get_MAC_add6() { return MAC_add6; }

    uint32_t get_year() { return year; }
    uint32_t get_month() { return month; }
    uint32_t get_day() { return day; }
    uint32_t get_hour() { return hour; }
    uint32_t get_minute() { return minute; }
    uint32_t get_sec() { return sec; }
    uint32_t get_week() {
        return  ((2000+year-(month<3)) + (2000+year-(month<3))/4 -
            (2000+year-(month<3))/100 + (2000+year-(month<3))/400 +
            (13*(month+(month<3)*12)+8)/5 + day) % 7;
    }

    uint32_t get_nazo1() { return nazo1; }
    uint32_t get_nazo2() { return nazo2; }
    uint32_t get_nazo3() { return nazo3; }
    uint32_t get_nazo4() { return nazo4; }
    uint32_t get_nazo5() { return nazo5; }

    uint32_t get_VCount() { return VCount; }
    uint32_t get_Timer0() { return Timer0; }
    uint32_t get_GxStat() { return GxStat; }
    uint32_t get_Frame() { return Frame; }
    uint32_t get_key() { return key; }


};
} // end RNGLib

#endif
