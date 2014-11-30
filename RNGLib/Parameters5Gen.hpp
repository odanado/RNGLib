/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */
#ifndef INCLUDED_PARAMETERS_5GEN_HPP
#define INCLUDED_PARAMETERS_5GEN_HPP
#include <cstdint>
#include "DateTime/DateTime.hpp"
#include "ConstantParameters5Gen.hpp"

namespace RNGLib {

template<typename Constant>
class Parameters5Gen {
private:
    u32 nazo1 = Constant::nazo1;
    u32 nazo2 = Constant::nazo2;
    u32 nazo3 = Constant::nazo3;
    u32 nazo4 = Constant::nazo4;
    u32 nazo5 = Constant::nazo5;

    u32 vcount = Constant::vcount;
    u32 gxstat = Constant::gxstat;
    u32 frame = Constant::frame;
    u32 timer0_min = Constant::timer0_min;
    u32 timer0_max = Constant::timer0_max;

    u32 timer0;
    u32 mac_add1;
    u32 mac_add2;
    u32 mac_add3;
    u32 mac_add4;
    u32 mac_add5;
    u32 mac_add6;
    u32 year;
    u32 month;
    u32 day;
    u32 hour;
    u32 minute;
    u32 sec;

    u32 key;

public:
    Parameters5Gen() : timer0(timer0_min), key(0x2fff) {}
    void set_mac_add(u32 m1, u32 m2, u32 m3, u32 m4, u32 m5, u32 m6) {
        mac_add1 = m1;
        mac_add2 = m2;
        mac_add3 = m3;
        mac_add4 = m4;
        mac_add5 = m5;
        mac_add6 = m6;
    }

    void set_year(u32 yy) { year = yy; }
    void set_month(u32 mm) { month = mm; }
    void set_day(u32 dd) { day = dd; }

    void set_hour(u32 hh) { hour = hh; }
    void set_minute(u32 mi) { minute = mi; }
    void set_sec(u32 se) { sec = se; }

    void set_datetime(const DateTime& dateTime) {
        year   = dateTime.get_year();
        month  = dateTime.get_month();
        day    = dateTime.get_day();
        hour   = dateTime.get_hour();
        minute = dateTime.get_minute();
        sec    = dateTime.get_sec();
    }


    void set_key(u32 key_) { key = key_; }
    void set_timer0(u32 tt) { timer0 = tt; }

    void set_vcount(u32 vcount_) { vcount = vcount_; }
    void set_gxstat(u32 gxstat_) { gxstat = gxstat_; }
    void set_frame(u32 frame_) { frame = frame_; }

    void set_nazo1(u32 nazo1_) { nazo1 = nazo1_; }
    void set_nazo2(u32 nazo2_) { nazo2 = nazo2_; }
    void set_nazo3(u32 nazo3_) { nazo3 = nazo3_; }
    void set_nazo4(u32 nazo4_) { nazo4 = nazo4_; }
    void set_nazo5(u32 nazo5_) { nazo5 = nazo5_; }

    void set_timer0_min(u32 timer0_min_) { timer0_min = timer0_min_; }
    void set_timer0_max(u32 timer0_max_) { timer0_max = timer0_max_; }


    u32 get_mac_add1() const { return mac_add1; }
    u32 get_mac_add2() const { return mac_add2; }
    u32 get_mac_add3() const { return mac_add3; }
    u32 get_mac_add4() const { return mac_add4; }
    u32 get_mac_add5() const { return mac_add5; }
    u32 get_mac_add6() const { return mac_add6; }

    u32 get_year() const { return year; }
    u32 get_month() const { return month; }
    u32 get_day() const { return day; }
    u32 get_hour() const { return hour; }
    u32 get_minute() const { return minute; }
    u32 get_sec() const { return sec; }
    u32 get_week() const {
        return  ((2000+year-(month<3)) + (2000+year-(month<3))/4 -
            (2000+year-(month<3))/100 + (2000+year-(month<3))/400 +
            (13*(month+(month<3)*12)+8)/5 + day) % 7;
    }

    u32 get_nazo1() const { return nazo1; }
    u32 get_nazo2() const { return nazo2; }
    u32 get_nazo3() const { return nazo3; }
    u32 get_nazo4() const { return nazo4; }
    u32 get_nazo5() const { return nazo5; }

    u32 get_vcount() const { return vcount; }
    u32 get_timer0() const { return timer0; }
    u32 get_gxstat() const { return gxstat; }
    u32 get_frame() const { return frame; }
    u32 get_key() const { return key; }

    u32 get_timer0_min() const { return timer0_min; }
    u32 get_timer0_max() const { return timer0_max; }


};

 
} // end RNGLib

#endif
