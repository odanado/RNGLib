/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */

#ifndef INCLUDED_DATE_TIME_HPP
#define INCLUDED_DATE_TIME_HPP

#include <cstdint>

namespace RNGLib {

class DateTimeIterator;
class DateTimeRange;
class DateTime {
    friend DateTimeIterator;
    friend DateTimeRange;
private:
    uint32_t year;
    uint32_t month;
    uint32_t day;
    uint32_t hour;
    uint32_t minute;
    uint32_t sec;
public:

    void set_year(uint32_t year_) { year = year_; }
    void set_month(uint32_t month_) { month = month_; }
    void set_day(uint32_t day_) { day = day_; }
    void set_hour(uint32_t hour_) { hour = hour_; }
    void set_minute(uint32_t minute_) { minute = minute_; }
    void set_sec(uint32_t sec_) { sec = sec_; }

    uint32_t get_year() const { return year; }
    uint32_t get_month() const { return month; }
    uint32_t get_day() const { return day; }
    uint32_t get_hour() const { return hour; }
    uint32_t get_minute() const { return minute; }
    uint32_t get_sec() const { return sec; }


};

} // end RNGLib
#endif
