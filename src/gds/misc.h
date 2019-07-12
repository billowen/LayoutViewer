#ifndef GDS_MISC_H
#define GDS_MISC_H

namespace gds {
class Time
{
public:
    Time()
    {
        year = month = day = hour = minute = second = 0;
    }

    Time(short year, short month, short day, short hour, short minute, short second)
        :year(year), month(month), day(day), hour(hour), minute(minute), second(second)
    {

    }
    short year, month, day, hour, minute, second;
};

}

#endif // MISC_H
