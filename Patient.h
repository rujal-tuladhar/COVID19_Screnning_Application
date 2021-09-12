//Name: Rujal Tuladhar
//Seneca Id: 154594188
//I have done this milestone 3 on my own using only the code that is provided in the assignment notes.
#ifndef _SDDS_PATIENT_H
#define _SDDS_PATIENT_H


#include"IOAble.h"
#include"Ticket.h"

using namespace std;
namespace sdds

{
	class Patient :public IOAble
	{

		char* m_name = nullptr;
		int o_number = 0;
		
		bool m_io;

	public:
		Ticket p_ticket = 0;

		Patient(int ticket_no = 0, bool io = false);
		Patient(const Patient&) = delete;
		Patient& operator =(const Patient&) = delete;

		virtual ~Patient();

		virtual char type() const = 0;
		const bool fileIO() const;
		void fileIO(bool value);
		bool operator == (const char type) const;

		bool operator == (const Patient& anotherPatient)const;

		void setArrivalTime();
		operator Time() const;
		int number() const;

		ostream& csvWrite(ostream& ostr) const;
		istream& csvRead(istream& istr);

		ostream& write(ostream& ostr) const;
		istream& read(istream& istr);











	};


}

#endif // !_SDDS_PATIENT_H