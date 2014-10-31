/*
 * Copyright (c) 2014 odan
 * License: MIT License
 */

#ifndef INCLUDED_DATE_TIME_ITERATOR_HPP
#define INCLUDED_DATE_TIME_ITERATOR_HPP
#include "DateTime.hpp"

namespace RNGLib {

class DateTimeIterator {
private:
    DateTime dateTime;
    DateTime beginDateTime;
    DateTime endDateTime;
public:
    DateTimeIterator(DateTime dateTime_, DateTime beginDateTime_, DateTime endDateTime_) :
        dateTime(dateTime_), beginDateTime(beginDateTime_), endDateTime(endDateTime_) { }

    bool operator!=(const DateTimeIterator& it) {
        if(dateTime.sec != it.dateTime.sec) return true;
        if(dateTime.minute != it.dateTime.minute) return true;
        if(dateTime.hour != it.dateTime.hour) return true;
        if(dateTime.day != it.dateTime.day) return true;
        if(dateTime.month != it.dateTime.month) return true;
        if(dateTime.year != it.dateTime.year) return true;
        return false;
    }
    const DateTime& operator*() {
        return dateTime;
    }

    DateTimeIterator& operator++() {
        if(dateTime.sec < endDateTime.sec) {
            ++dateTime.sec;
            return *this;
        }
        dateTime.sec = beginDateTime.sec;

        if(dateTime.minute < endDateTime.minute) {
            ++dateTime.minute;
            return *this;
        }
        dateTime.minute = beginDateTime.minute;

        if(dateTime.hour < endDateTime.hour) {
            ++dateTime.hour;
            return *this;
        }
        dateTime.hour = beginDateTime.hour;

        if(dateTime.day < endDateTime.day) {
            ++dateTime.day;
            return *this;
        }
        dateTime.day = beginDateTime.day;

        if(dateTime.month < endDateTime.month) {
            ++dateTime.month;
            return *this;
        }
        dateTime.month = beginDateTime.month;

        if(dateTime.year < endDateTime.year) {
            dateTime.year++;
            return *this;
        }

        return *this;
    }

};
} // end RNGLib
#endif
