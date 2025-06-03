/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4
Full Name  : Chetan Arora
Student ID#: 100976240
Email      : carora18@myseneca.ca
Date	   : 06 Apr 2025
 
Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_LINEMANAGER_H
#define SENECA_LINEMANAGER_H

#include "Workstation.h"
#include <vector>

namespace seneca {

// LineManager class orchestrates the entire assembly line
class LineManager {
    std::vector<Workstation*> m_activeLine{}; // Active stations in the assembly line
    size_t m_cntCustomerOrder{0};           // Total number of customer orders
    Workstation* m_firstStation{nullptr};   // Starting station of the assembly line

public:
    LineManager(const std::string& file, const std::vector<Workstation*>& stations);

    // Reorders stations to reflect the proper sequence
    void reorderStations();

    // Runs one iteration of the assembly line
    bool run(std::ostream& os);

    // Displays all stations in the assembly line
    void display(std::ostream& os) const;
};
}

#endif
