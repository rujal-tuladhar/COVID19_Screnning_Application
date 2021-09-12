//Name- Rujal Tuladhar
//SenecaId - 154594188 
//email - rtuladhar@myseneca.ca
// I have done this assignment on my own by using only the code provided by my proffesors
//Melestone -5



#ifndef SDDS_PRETRIAGE_H
#define SDDS_PRETRIAGE_H
#include "Patient.h"
#include "Time.h"
#include "Menu.h"

namespace sdds {
    const int maxNoOfPatients = 100;
    class PreTriage {
        Time m_averCovidWait, m_averTriageWait;
        Patient* m_lineup[maxNoOfPatients]{};
        char* m_dataFilename = nullptr;
        int m_lineupSize = 0;
        Menu m_appMenu, m_pMenu;
        void reg();
        void admit();
        const Time getWaitTime(const Patient& p)const;
        void setAverageWaitTime(const Patient& p);
        void removePatientFromLineup(int index);
        int indexOfFirstInLine(char type) const;
        void load();
    public:
        PreTriage(const char* dataFilename);
        ~PreTriage();
        void run(void);
    };
}
#endif //SDDS_PRETRIAGE_H