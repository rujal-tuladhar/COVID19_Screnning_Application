//name- Rujal Tuladhar
//seneca id -154594188
//email- rtuladhar@myseneca.ca
//I have done this assignment on my own using only the codes provided to me by my professors.
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <cstring>
#include "utils.h"

using namespace std;
namespace sdds {
    void Menu::setText(const char* text)
    {
       
        
    }

    Menu::Menu(const char* MenuContent, int NoOfSelections)
    {
        m_noOfSel = NoOfSelections;
        m_text = new char[strlen(MenuContent) + 1];
        strcpy(m_text, MenuContent);

        m_text[strlen(MenuContent)] = '\0';
        

    }

    Menu::~Menu()
    {
        delete[] m_text;
    }

    Menu::Menu(const Menu& other)
    {
        m_noOfSel = other.m_noOfSel;
        m_text = new char[strlen(other.m_text) + 1];
        strcpy(m_text, other.m_text);
        m_text[strlen(other.m_text)] = '\0';

 
    }

    void Menu::display()const
    {
        cout << m_text << endl;
        cout << "0- Exit" << endl;
    }

    int& Menu::operator>>(int& Selection)
    {
        display();
        int value = getInt(0, m_noOfSel, "> ", "Invalid option ");
        Selection = value;

        return Selection;
    }
}