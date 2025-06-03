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
#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H

#include <chrono>
#include <string>

#include "event.h"

namespace seneca
{

    class TimeMonitor
    {

        std::chrono::steady_clock::time_point m_startTime;
        std::chrono::steady_clock::time_point m_endTime;
        std::string m_name;

    public:
        void startEvent(const char *name);

        Event stopEvent();
    };

}

#endif // SENECA_TIMEMONITOR_H