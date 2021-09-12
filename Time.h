//name- Rujal Tuladhar
//seneca id -154594188
//email- rtuladhar@myseneca.ca
//I have done this assignment on my own using only the codes provided to me by my professors.
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <iostream>
namespace sdds {
    class Time {
        unsigned int m_min;
    public:
        Time& setToNow();
        Time(unsigned int min = 0);
        std::ostream& write(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
        int change(int hrs, int mins);
        Time& operator-=(const Time& D);
        Time operator-(const Time& D)const;
        Time& operator+=(const Time& D);
        Time operator+(const Time& D)const;

        Time& operator=(unsigned int val);
        Time& operator *= (unsigned int val);
        Time& operator /= (unsigned int val);
        Time operator *(unsigned int val)const;
        Time operator /(unsigned int val)const;

        operator unsigned int()const;
        operator int()const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Time& D);
    std::istream& operator>>(std::istream& istr, Time& D);
}

#endif // !SDDS_TIME_H

