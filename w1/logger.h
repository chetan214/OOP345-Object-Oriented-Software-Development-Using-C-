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
#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H

#include <iostream>
#include "event.h"

namespace seneca
{
    class Logger
    {
        Event *m_events;
        int m_capacity;
        int m_size;

    public:
        Logger();
        ~Logger();

        Logger(Logger &&other) noexcept;
        Logger &operator=(Logger &&other) noexcept;

        void addEvent(const Event &event);

        friend std::ostream &operator<<(std::ostream &os, const Logger &logger);
    };

}

#endif // SENECA_LOGGER_H