//name- Rujal Tuladhar
//seneca id -154594188
//email- rtuladhar@myseneca.ca
//I have done this assignment on my own using only the codes provided to me by my professors.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
    bool debug = false;  // made global in utils.h

    int getTime(bool clean) {
        int mins = -1;
        if (debug) {
            Time t(0);
            cout << "Enter current time: ";
            do {
                cin.clear();
                cin >> t;   // needs extraction o perator overloaded for Time
                if (!cin) {
                    cout << "Invlid time, try agian (HH:MM): ";
                    cin.clear();
                }
                else {
                    mins = int(t);
                }
                cin.ignore(1000, '\n');
            } while (mins < 0);
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }

    int getInt(const char* prompt)
    {
        int number;
        bool badvalue;
        char value;
        if (prompt != nullptr)
            cout << prompt;


        do {
            badvalue = false;
            cin >> number;
            if (cin.fail()) {
                cout << "Bad integer value, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
                badvalue = true;
            }
            else {
                value = cin.get();
                if (value != '\n') {
                    cout << "Enter only an integer, try again: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    badvalue = true;
                }




            }
        } while (badvalue);
        return number;
    }

    int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
    {
        cout << prompt;
        int number;
        number = getInt();


        while (!(number >= min && number <= max))
        {


            cin.clear();
            if (errorMessage != nullptr)
                cout << errorMessage;

            if (showRangeAtError)
            {
                cout << "[" << min << " <= value <= " << max << "]: ";
            }

            number = getInt();

        }

        return number;



    }


    char* getcstr(const char* prompt, std::istream& istr, char delimiter)
    {
        if (prompt != nullptr)

            cout << prompt;
        string value;
        getline(istr, value);
        int size = value.length();
        char* new_str = new char[size + 1];
        strcpy(new_str, value.c_str());
        new_str[size] = '\0';



        return new_str;
    }
}