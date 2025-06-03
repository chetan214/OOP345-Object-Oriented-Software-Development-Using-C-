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
#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

#include <iostream>
#include <chrono>
#include <string>

namespace seneca
{
    class Event
    {
        std::string m_event_name;
        std::chrono::nanoseconds m_duration;

    public:
        Event();
        Event(const char *name, const std::chrono::nanoseconds &duration);

        friend std::ostream &operator<<(std::ostream &os, const Event &event);
    };

}

#endif // SENECA_EVENT_H