//name- Rujal Tuladhar
//seneca id -154594188
//email- rtuladhar@myseneca.ca
//I have done this assignment on my own using only the codes provided to me by my professors.
#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H
#include <iostream>
namespace sdds
{
    class IOAble
    
    {
    public:
        //the main base class
        virtual std::ostream& csvWrite(std::ostream&) const = 0;

        virtual std::istream& csvRead(std::istream&) = 0;
        virtual std::ostream& write(std::ostream&) const = 0;
        virtual std::istream& read(std::istream&) = 0;

        virtual ~IOAble() {};
    };


    std::ostream& operator<<(std::ostream& ostr, const IOAble& obj);
    std::istream& operator>>(std::istream& istr, IOAble& obj);
}
#endif