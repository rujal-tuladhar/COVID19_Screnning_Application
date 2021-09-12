//Name: Rujal TUladhar
//Student id:154594188
//Seneca email: rtuladhar@myseneca.ca
//I have done this milestone 4 on my own by using the guidenece and instruction  provided by my proffersor 
#define _CRT_SECURE_NO_WARNINGS
#include "TriagePatient.h"
#include<cstring>
#include<string>
#include "utils.h"

namespace sdds
{
	int nextTriageTicket = 1;

	TriagePatient::TriagePatient() :Patient(nextTriageTicket)
	{
		symptoms = nullptr;
		nextTriageTicket++;


	}

	char TriagePatient::type()const
	{
		return 'T';
	}

	ostream& TriagePatient::csvWrite(ostream& ostr)const
	{
		Patient::csvWrite(ostr) << "," << symptoms;
		nextTriageTicket = Patient::number() + 1;
		return ostr;
	}
	istream& TriagePatient::csvRead(istream& istr)
	{
		char value;
		string final;

		Patient::csvRead(istr);
		if (symptoms)
		{
			delete[] symptoms;
		}
		istr >> value;
		getline(istr, final, '\n');
		symptoms = new char[strlen(final.c_str()) + 1];
		strcpy(symptoms, final.c_str());
		nextTriageTicket = Patient::number() + 1;

		return istr;

	}
	ostream& TriagePatient::write(ostream& ostr)const
	{
		if (Patient::fileIO())
		{
			TriagePatient::csvWrite(ostr);

		}
		else
		{
			ostr << "TRIAGE" << endl;
			Patient::write(ostr) << endl;
			ostr << "Symptoms: " << symptoms << endl;
		}
		return ostr;
	}
	istream& TriagePatient::read(istream& istr)
	{
		char* value;
		if (Patient::fileIO())

		{
			csvRead(istr);
		}

		else
		{
			if (symptoms)
			{
				delete[] symptoms;
			}

			Patient::read(istr);
			value = getcstr("Symptoms: ", istr);
			symptoms = new char[strlen(value) + 1];
			strcpy(symptoms, value);

			delete[] value;
		}

		return istr;
	}
	TriagePatient::~TriagePatient()
	{


		delete[] symptoms;
		symptoms = nullptr;

	}

}