/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */
#ifndef INCLUDED_PARAMETERS_5GEN_HPP
#define INCLUDED_PARAMETERS_5GEN_HPP
#include <cstdint>

namespace RNGLib {
template<uint32_t nazo1_, uint32_t nazo2_, uint32_t nazo3_, uint32_t nazo4_, uint32_t nazo5_,
         uint32_t vcount_, uint32_t gxstat_, uint32_t frame_, uint32_t timer0_min_, uint32_t timer0_max_>
class Parameters5Gen {
public:
#ifdef _MSC_VER
    static const uint32_t nazo1 = nazo1_;
    static const uint32_t nazo2 = nazo2_;
    static const uint32_t nazo3 = nazo3_;
    static const uint32_t nazo4 = nazo4_;
    static const uint32_t nazo5 = nazo5_;

    static const uint32_t vcount = vcount_;
    static const uint32_t gxstat = gxstat_;
    static const uint32_t frame  = frame_;
    static const uint32_t timer0_min = timer0_min_;
    static const uint32_t timer0_max = timer0_max_;
#else
    static constexpr uint32_t nazo1 = nazo1_;
    static constexpr uint32_t nazo2 = nazo2_;
    static constexpr uint32_t nazo3 = nazo3_;
    static constexpr uint32_t nazo4 = nazo4_;
    static constexpr uint32_t nazo5 = nazo5_;

    static constexpr uint32_t vcount = vcount_;
    static constexpr uint32_t gxstat = gxstat_;
    static constexpr uint32_t frame  = frame_;
    static constexpr uint32_t timer0_min = timer0_min_;
    static constexpr uint32_t timer0_max = timer0_max_;
#endif
private:
    uint32_t timer0;
    uint32_t mac_add1;
    uint32_t mac_add2;
    uint32_t mac_add3;
    uint32_t mac_add4;
    uint32_t mac_add5;
    uint32_t mac_add6;
    uint32_t year;
    uint32_t month;
    uint32_t day;
    uint32_t hour;
    uint32_t minute;
    uint32_t sec;

    uint32_t key;

public:
    Parameters5Gen() : timer0(timer0_min), key(0x2fff) {}
    void set_mac_add(uint32_t m1, uint32_t m2, uint32_t m3, 
            uint32_t m4, uint32_t m5, uint32_t m6) {
        mac_add1 = m1;
        mac_add2 = m2;
        mac_add3 = m3;
        mac_add4 = m4;
        mac_add5 = m5;
        mac_add6 = m6;
    }

    void set_year(uint32_t yy) { year = yy; }
    void set_month(uint32_t mm) { month = mm; }
    void set_day(uint32_t dd) { day = dd; }

    void set_hour(uint32_t hh) { hour = hh; }
    void set_minute(uint32_t mi) { minute = mi; }
    void set_sec(uint32_t se) { sec = se; }


    void set_key(uint32_t key_) { key = key_; }
    void set_timer0(uint32_t tt) { timer0 = tt; }

    uint32_t get_mac_add1() const { return mac_add1; }
    uint32_t get_mac_add2() const { return mac_add2; }
    uint32_t get_mac_add3() const { return mac_add3; }
    uint32_t get_mac_add4() const { return mac_add4; }
    uint32_t get_mac_add5() const { return mac_add5; }
    uint32_t get_mac_add6() const { return mac_add6; }

    uint32_t get_year() const { return year; }
    uint32_t get_month() const { return month; }
    uint32_t get_day() const { return day; }
    uint32_t get_hour() const { return hour; }
    uint32_t get_minute() const { return minute; }
    uint32_t get_sec() const { return sec; }
    uint32_t get_week() const {
        return  ((2000+year-(month<3)) + (2000+year-(month<3))/4 -
            (2000+year-(month<3))/100 + (2000+year-(month<3))/400 +
            (13*(month+(month<3)*12)+8)/5 + day) % 7;
    }

    uint32_t get_nazo1() const { return nazo1; }
    uint32_t get_nazo2() const { return nazo2; }
    uint32_t get_nazo3() const { return nazo3; }
    uint32_t get_nazo4() const { return nazo4; }
    uint32_t get_nazo5() const { return nazo5; }

    uint32_t get_vcount() const { return vcount; }
    uint32_t get_timer0() const { return timer0; }
    uint32_t get_gxstat() const { return gxstat; }
    uint32_t get_frame() const { return frame; }
    uint32_t get_key() const { return key; }

    uint32_t get_timer0_min() const { return timer0_min; }
    uint32_t get_timer0_max() const { return timer0_max; }


};
typedef Parameters5Gen<0x2215f10, 0x221600c, 0x221600c, 0x2216058, 0x2216058, 0x60, 0x6000000, 6, 0xc79, 0xc7a> ParametersB1Ja;
typedef Parameters5Gen<0x2215f30, 0x221602c, 0x221602c, 0x2216078, 0x2216078, 0x60, 0x6000000, 6, 0xc68, 0xc69> ParametersW1Ja;

 
} // end RNGLib

#endif
