//Name: Rujal TUladhar
//Student id:154594188
//Seneca email: rtuladhar@myseneca.ca
//I have done this milestone 4 on my own by using the guidenece and instruction  provided by my proffersor 
#ifndef _SDDS_COVID_PATIENT_H
#define _SDDS_CPVID_PATIENT_H
#include"Patient.h"


namespace sdds
{
	class CovidPatient:public Patient
	{
	public:

		CovidPatient();

		virtual char type()const;

		istream& csvRead(istream& istr);

		ostream& write(ostream& ostr) const;
		istream& read(istream& istr);


	};





}

#endif // !_SDDS_COVID_PATIENT_H
