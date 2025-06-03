/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #1
Full Name  : Chetan Arora
Student ID#: 100976240
Email      : carora18@myseneca.ca
Date	   : 02 Feb 2025
 
Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include "timeMonitor.h"

#include <iostream>
#include <chrono>

#include "event.h"

using namespace std;

namespace seneca
{
    void TimeMonitor::startEvent(const char *name)
    {
        m_name = name;
        m_startTime = chrono::steady_clock::now();
    }

    Event TimeMonitor::stopEvent()
    {
        m_endTime = chrono::steady_clock::now();
        chrono::nanoseconds duration = chrono::duration_cast<chrono::nanoseconds>(m_endTime - m_startTime);

        return Event(m_name.c_str(), duration);
    }

};