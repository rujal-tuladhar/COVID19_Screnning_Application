//Name: Rujal TUladhar
//Student id:154594188
//Seneca email: rtuladhar@myseneca.ca
//I have done this milestone 4 on my own by using the guidenece and instruction  provided by my proffersor 
#ifndef _SDDS_TRIAGE_PATIENT_H
#include"Patient.h"

namespace sdds
{

	class TriagePatient :public Patient
	{
		char* symptoms;
	public:
		TriagePatient();

		virtual char type()const;

		ostream& csvWrite(ostream& ostr)const;
		istream& csvRead(istream& istr);
		ostream& write(ostream& ostr)const;
		istream& read(istream& istr);
		~TriagePatient();

	};

}


#endif // !_SDDS_TRIAGE_PATIENT_H

