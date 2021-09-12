//Name: Rujal Tuladhar
//Seneca Id: 154594188
//I have done this milestone 3 on my own using only the code that is provided in the assignment notes.
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include<string>
#include "Patient.h"
#include "utils.h"
namespace sdds
{

	Patient::Patient(int ticket_no, bool io)
	{
		p_ticket = ticket_no;
		m_io = io;
	}

	Patient::~Patient()
	{
		delete[] m_name;


	}


	const bool Patient::fileIO() const
	{
		return m_io;
	}
	void Patient::fileIO(bool value)
	{
		m_io = value;
	}
	bool Patient::operator == (const char type) const
	{
		return this->type() == type;
	}

	bool Patient::operator == (const Patient& anotherPatient)const
	{
		return this->type() == anotherPatient.type();
	}

	void Patient::setArrivalTime()
	{
		p_ticket.resetTime();

	}

	Patient::operator Time() const
	{
		return (Time)p_ticket;
	}

	int Patient::number() const
	{
		return p_ticket.number();
	}

	ostream& Patient::csvWrite(ostream& ostr) const
	{
		ostr << this->type() << ',' << m_name << ',' << o_number << ',';

		p_ticket.csvWrite(ostr);
		return ostr;
	}


	istream& Patient::csvRead(istream& istr)
	{
		string number;
		char value;
		getline(istr, number, ',');
		if (m_name) {
			delete[] m_name;
			m_name = nullptr;
		}
		m_name = new char[strlen(number.c_str()) + 1];
		strcpy(m_name, number.c_str());
		istr >> o_number >> value;

		p_ticket.csvRead(istr);

		return istr;


	}

	ostream& Patient::write(ostream& ostr)const
	{

		ostr << "Ticket No: " << p_ticket.number() << ", Issued at: " << Time(*this) << endl;

		if (strlen(m_name) > 25)
		{
			for (int i = 0; i < 25; i++)
				ostr << m_name[i];

		}

		else
			ostr << m_name;
		ostr << ", OHIP: " << o_number;
		return ostr;

	}

	istream& Patient::read(istream& istr)
	{
		char* name = getcstr("Name: ", istr);
		if (m_name)
		{
			delete[] m_name;
			m_name = nullptr;
		}

		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);

		delete[] name;
		//using the utils function getInt

		o_number = getInt(100000000, 999999999, "OHIP: ", "Invalid OHIP Number, ");

		return istr;
	}





}