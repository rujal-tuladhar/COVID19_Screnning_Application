//name- Rujal Tuladhar
//seneca id -154594188
//email- rtuladhar@myseneca.ca
//I have done this assignment on my own using only the codes provided to me by my professors.
#include "utils.h"
#include "IOAble.h"
#include <cstring>
using namespace std;

namespace sdds 
{

	istream& operator>>(istream& istr, IOAble& obj)
	{
		return obj.read(istr);
	}

	ostream& operator<<(ostream& istr, const IOAble& obj)
	{
		return obj.write(istr);
	}
}