/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */

#ifndef INCLUDED_DATE_TIME_RANGE_HPP
#define INCLUDED_DATE_TIME_RANGE_HPP

#include "../Config.hpp"

#include "DateTime.hpp"
#include "DateTimeIterator.hpp"

namespace RNGLib {
class DateTimeRange {
public:
    typedef DateTimeIterator iterator;
private:
    DateTime beginDateTime;
    DateTime endDateTime;
public:

    void set_year(u32 begin_, u32 end_) {
        beginDateTime.year = begin_;
        endDateTime.year = end_;
    }

    void set_month(u32 begin_, u32 end_) {
        beginDateTime.month = begin_;
        endDateTime.month = end_;
    }

    void set_day(u32 begin_, u32 end_) {
        beginDateTime.day = begin_;
        endDateTime.day = end_;
    }

    void set_hour(u32 begin_, u32 end_) {
        beginDateTime.hour = begin_;
        endDateTime.hour = end_;
    }

    void set_minute(u32 begin_, u32 end_) {
        beginDateTime.minute = begin_;
        endDateTime.minute = end_;
    }

    void set_sec(u32 begin_, u32 end_) {
        beginDateTime.sec = begin_;
        endDateTime.sec = end_;
    }

    void set_begin(DateTime dateTime_) {
        beginDateTime = dateTime_;
    }

    void set_end(DateTime dateTime_) {
        endDateTime = dateTime_;
    }

    iterator begin() {
        return iterator(beginDateTime, beginDateTime, endDateTime);
    }

    iterator end() {
        return iterator(endDateTime, beginDateTime, endDateTime);
    }
};
} // end RNGLib
#endif
