//name- Rujal Tuladhar
//seneca id -154594188
//email- rtuladhar@myseneca.ca
//I have done this assignment on my own using only the codes provided to me by my professors.
#include "Time.h"
#include "utils.h"
#include <string>
using namespace std;
namespace sdds
{

    Time& Time::setToNow()
    {
        m_min = getTime();
        return *this;
    }

    Time::Time(unsigned int min)
    {
        m_min = min;
    }


    std::ostream& Time::write(std::ostream& ostr) const
    {
        int hrs = m_min / 60;
        int mins = m_min % 60;

        if (hrs < 10)
            ostr << "0";

        ostr << hrs << ":";

        if (mins < 10)
            ostr << "0";
        ostr << mins;

        return ostr;
    }
    int Time::change(int hrs, int mins)

    {
        return hrs * 60 + mins;

    };

    std::istream& Time::read(std::istream& istr)
    {
        {int mins = 0;
        int hrs = 0;

        char value = ' ';
        istr >> hrs;
        istr >> value;

        if (value == ':' && hrs >= 0 && mins >= 0)
        {
            istr >> mins;
            if (mins >= 0)

            {
                m_min = change(hrs, mins);


            }

            else { istr.setstate(ios::failbit); }


        }

        else { istr.setstate(ios::failbit); }

        return istr;

        };
    }

    Time& Time::operator-= (const Time& D)
    {
        if (this->m_min > D.m_min) {
            this->m_min -= D.m_min;
        }
        else {
            this->m_min += 1440;
            this->m_min -= D.m_min;
        }
        return *this;
    }


    Time Time::operator-(const Time& D) const
    {
        bool result = true;
        Time temp;
        if (m_min > D.m_min)
        {
            temp.m_min = this->m_min - D.m_min;

        }
        else
        {
            int i = 1;

            while (result)
            {
                if ((m_min + (1440 * i) < D.m_min)) i++;

                else

                    result = false;
            }

            temp.m_min = (m_min + (1440 * i)) - D.m_min;

        }
        return temp;
    }


    Time Time::operator+(const Time& D)const
    {
        Time temp;
        temp.m_min = m_min + D.m_min;
        return temp;
    }

    Time& Time::operator+=(const Time& D)
    {
        this->m_min += D.m_min;
        return *this;
    }

    Time& Time::operator=(unsigned int val)
    {

        this->m_min = val;
        return *this;
    }

    Time Time::operator *(unsigned int val) const
    {
        Time temp;

        temp.m_min = m_min * val;
        return temp;
    }

    Time& Time::operator *= (unsigned int val)
    {
        this->m_min *= val;
        return *this;
    }

    Time& Time::operator /= (unsigned int val)
    {
        this->m_min /= val;
        return *this;
    }
    Time Time::operator /(unsigned int val)const
    {
        Time temp;

        temp.m_min = m_min / val;
        return temp;
    }

    Time::operator int()const
    {
        return m_min;
    }

    Time::operator unsigned int()const
    {
        return m_min;
    }

    std::ostream& operator<<(std::ostream& ostr, const Time& D)
    {

        return D.write(ostr);
    }

    std::istream& operator>>(std::istream& istr, Time& D)
    {

        return   D.read(istr);
    }
}