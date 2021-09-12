//Name: Rujal TUladhar
//Student id:154594188
//Seneca email: rtuladhar@myseneca.ca
//I have done this milestone 4 on my own by using the guidenece and instruction  provided by my proffersor 
#include "CovidPatient.h"


namespace sdds
{
	int nextCovidTicket = 1;

	CovidPatient::CovidPatient() : Patient(nextCovidTicket) 
	{
		nextCovidTicket++;
	}


    char CovidPatient::type()const
	{
		return'C';
	}

	istream& CovidPatient::csvRead(istream& istr)
	{

		Patient::csvRead(istr);
		nextCovidTicket = Patient::number() + 1;

		istr.ignore();
		return istr;

	}

	ostream& CovidPatient::write(ostream& ostr) const
	{
		if (Patient::fileIO())
		{
			Patient::csvWrite(ostr);
		}
		else {
			ostr << "COVID TEST" << endl;
			Patient::write(ostr) << endl;
		}
		return ostr;
	}

	

	istream& CovidPatient::read (istream& istr)
	{
		
		if (Patient::fileIO() == true)
		{
			csvRead(istr);
		}
		
		else
		{

			Patient::read(istr);
		}

		return istr;

	}



}