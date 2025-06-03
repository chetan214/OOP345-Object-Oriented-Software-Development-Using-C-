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

#ifndef SENECA_WORKSTATION_H
#define SENECA_WORKSTATION_H

#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace seneca {

// Global queues for order processing
extern std::deque<CustomerOrder> g_pending;     // Orders waiting to be processed
extern std::deque<CustomerOrder> g_completed;   // Fully completed orders
extern std::deque<CustomerOrder> g_incomplete;  // Partially completed orders

// Workstation class manages the processing of customer orders
class Workstation : public Station {
    std::deque<CustomerOrder> m_orders{};       // Queue of orders at this workstation
    Workstation* m_pNextStation{nullptr};       // Pointer to the next station in the assembly line

public:
    Workstation(const std::string& data);       // Constructor initializes from a string

    // Deleted copy/move constructors and assignment operators
    Workstation(const Workstation&) = delete;
    Workstation& operator=(const Workstation&) = delete;
    Workstation(Workstation&&) = delete;
    Workstation& operator=(Workstation&&) = delete;

    // Fills the order at the front of the queue, if any
    void fill(std::ostream& os);

    // Attempts to move the front order to the next station
    bool attemptToMoveOrder();

    // Sets the next station in the assembly line
    void setNextStation(Workstation* station = nullptr);

    // Gets the pointer to the next station
    Workstation* getNextStation() const;

    // Displays the current workstation and its next station
    void display(std::ostream& os) const;

    // Adds a new customer order to the workstation queue
    Workstation& operator+=(CustomerOrder&& newOrder);
};

} 

#endif // SENECA_WORKSTATION_H
