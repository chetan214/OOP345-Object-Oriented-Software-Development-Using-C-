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
#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H

#include <string>

namespace seneca
{
    class Settings
    {
    public:
        bool m_show_all;
        bool m_verbose;
        // Possible values are seconds, milliseconds, microseconds, nanoseconds (default nanoseconds).
        std::string m_time_units = "nanoseconds";
    };

    extern Settings g_settings;
}

#endif // SENECA_SETTINGS_H