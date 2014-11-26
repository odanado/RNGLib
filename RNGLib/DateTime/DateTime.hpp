/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */

#ifndef INCLUDED_DATE_TIME_HPP
#define INCLUDED_DATE_TIME_HPP

#include "../Config.hpp"


namespace RNGLib {

class DateTimeIterator;
class DateTimeRange;
class DateTime {
    friend DateTimeIterator;
    friend DateTimeRange;
private:
    u32 year;
    u32 month;
    u32 day;
    u32 hour;
    u32 minute;
    u32 sec;
public:

    void set_year(u32 year_) { year = year_; }
    void set_month(u32 month_) { month = month_; }
    void set_day(u32 day_) { day = day_; }
    void set_hour(u32 hour_) { hour = hour_; }
    void set_minute(u32 minute_) { minute = minute_; }
    void set_sec(u32 sec_) { sec = sec_; }

    u32 get_year() const { return year; }
    u32 get_month() const { return month; }
    u32 get_day() const { return day; }
    u32 get_hour() const { return hour; }
    u32 get_minute() const { return minute; }
    u32 get_sec() const { return sec; }


};

} // end RNGLib
#endif
