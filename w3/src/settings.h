/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3
Full Name  : Chetan Arora
Student ID#: 100976240
Email      : carora18@myseneca.ca
Date	   : 14 Feb 2025
 
Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H
namespace seneca {

struct Settings {
    short m_maxSummaryWidth = 80; // Maximum width for displaying summaries
    bool m_tableView = false;     // Whether to display items in a table format
};

// Declaration of a global settings object
extern Settings g_settings;
}

#endif // SENECA_SETTINGS_H
