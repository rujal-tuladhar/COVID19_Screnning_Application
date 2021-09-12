//Name: Rujal TUladhar
//Student id:154594188
//Seneca email: rtuladhar@myseneca.ca
//I have done this milestone 4 on my own by using the guidenece and instruction  provided by my proffersor 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "PreTriage.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "utils.h"
#include<string>
#include<cstring>
using namespace std;
namespace sdds
{

    PreTriage::PreTriage(const char* dataFilename) :

        m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
        m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2) 
    {
        m_averCovidWait = 15;
        m_averTriageWait = 5;
        m_dataFilename = new char[strlen(dataFilename) + 1]();
        strcpy(m_dataFilename, dataFilename);

       
        load();
    }


    PreTriage::~PreTriage() {
       
        ofstream m_file(m_dataFilename);

        cout << "Saving Average Wait Times," << endl<< "   COVID Test: " << m_averCovidWait << endl << "   Triage: " << m_averTriageWait << endl<< "Saving m_lineup..." << endl;
       
        m_file << m_averCovidWait << ',' << m_averTriageWait << endl;
        if (m_file.is_open()) 
        {
            for (int i = 0; i < m_lineupSize; i++) {
                m_lineup[i]->csvWrite(m_file);
                cout << i + 1 << "- ";
                m_lineup[i]->csvWrite(cout);
                m_file << endl;
                    cout<< endl;
            }
        }
        m_file.close();

        for (int i = 0; i < maxNoOfPatients; i++) 
        {
            delete m_lineup[i];
        }

        delete[] m_dataFilename;
        cout << "done!" << endl;
    }


    const Time PreTriage::getWaitTime(const Patient& p) const
    {
        int count = 0;
        for (int i = 0; i < m_lineupSize; i++)
        {
            if (m_lineup[i]->type() == p.type())
            {
                count++;
            }
        }
        return Time(p) *= count;

    }


    void  PreTriage::setAverageWaitTime(const Patient& p)
    {

        Time CT = getTime();
        int PTN = p.number();

        if (p.type() == 'T') {
            m_averTriageWait = (((CT - p).operator int() + (m_averTriageWait.operator int() * (PTN - 1))) / PTN);
        }
        else if (p.type() == 'C') {
            m_averCovidWait = (((CT - p).operator int() + (m_averCovidWait.operator int() * (PTN - 1))) /PTN);
        }

        
    }

    void PreTriage::removePatientFromLineup(int index)
    {
        removeDynamicElement(m_lineup, index, m_lineupSize);

    }


    int PreTriage::indexOfFirstInLine(char type) const
    {
        for (int i = 0; i < m_lineupSize; i++)
        {
            if (m_lineup[i]->type() == type)
                return i;

        }
        return -1;

    }



    void PreTriage::load() {

        cout << "Loading data..." << endl;
        ifstream m_file(m_dataFilename);
        bool value = false;

        Patient* new_Ptnt = nullptr;
        char p_type = '\0';

        m_file >> m_averCovidWait;
        m_file.get();
        m_file >> m_averTriageWait;
        m_file.get();

        if (m_file.is_open()) 
        {
            while (!m_file.eof() && !value) {
                p_type = m_file.get();

                if (p_type == 'C') {
                    new_Ptnt = new CovidPatient();
                    m_file.get();
                }
                else if (p_type == 'T') {
                    new_Ptnt = new TriagePatient();
                    m_file.get();
                }
                else {
                    new_Ptnt = nullptr;
                    m_file.get();
                }

                if (new_Ptnt != nullptr) {
                    new_Ptnt->fileIO(true);
                    new_Ptnt->csvRead(m_file);
                    new_Ptnt->fileIO(false);

                    m_lineup[m_lineupSize] = new_Ptnt;
                    m_lineupSize++;

                    if (m_lineupSize == 100) {
                        value = true;
                        if (!m_file.eof())
                        {
                            cout << "Warning: number of records exceeded 100"<<endl;
                        }
                    }
                }
            }
        }
        if (!m_lineupSize ) {
            cout << "No data or bad data file!" << endl << endl;
        }
        else {
            cout << m_lineupSize << " Records imported..." << endl << endl;
        }

        m_file.close();
    }


    void PreTriage::reg()
    {
        int choose = -1;
      
        if (m_lineupSize == maxNoOfPatients)
        {
            cout << "Line up full!" << endl;
            return;
        }
        else 
        {
            m_pMenu >> choose;
            switch (choose)
            {
            case 1:

                m_lineup[m_lineupSize] = new CovidPatient();
                m_lineup[m_lineupSize]->setArrivalTime();
                m_lineup[m_lineupSize]->fileIO(false);
                cout << "Please enter patient information: " << endl;
                m_lineup[m_lineupSize]->read(cin);

                cout << endl << "******************************************" << endl;
                m_lineup[m_lineupSize]->write(cout);
                cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]);

                cout << endl << "******************************************" << endl << endl;
                m_lineupSize++;
              
                break;

            case 2:

                m_lineup[m_lineupSize] = new TriagePatient();
                m_lineup[m_lineupSize]->setArrivalTime();
                m_lineup[m_lineupSize]->fileIO(false);
                cout << "Please enter patient information: " << endl;;
                m_lineup[m_lineupSize]->read(cin);

                cout << endl << "******************************************" << endl;
                m_lineup[m_lineupSize]->write(cout);
                cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;

                cout << "******************************************" << endl << endl;;
                m_lineupSize++;
               
                
                break;

            default:

                break;
            }
        }


    }



    void PreTriage::admit()
    {
        int choose = -1;
        int firstidx = 1;
        char selector;
        
        m_pMenu >> choose;
        switch (choose) 
        
        {
        case 1:
            selector = 'C';
         
                firstidx = indexOfFirstInLine(selector);
                cout << endl << "******************************************" << endl;
                m_lineup[firstidx]->fileIO(false);
                cout << "Calling for ";
                cout << *m_lineup[indexOfFirstInLine(selector)];
                cout << "******************************************" << endl << endl;

                setAverageWaitTime(*m_lineup[firstidx]);
                removePatientFromLineup(firstidx);
            
           
            break;
        case 2:

            selector = 'T';
                firstidx = indexOfFirstInLine(selector);
                cout << endl << "******************************************" << endl; 
                m_lineup[firstidx]->fileIO(false);
                cout << "Calling for ";
                cout << *m_lineup[indexOfFirstInLine(selector)];
                cout << "******************************************" << endl << endl;
                setAverageWaitTime(*m_lineup[firstidx]);

                removePatientFromLineup(firstidx);
            
          
            break;
       
        default:
           
            break;
        }
    }



    void PreTriage::run(void)
    {
        int selection;
        while (m_appMenu >> selection)
        {
            switch (selection)
            {
            case 1:
                reg();
                break;
            case 2:
                admit();
                break;
            default:
                break;
            }
        }
    }
}