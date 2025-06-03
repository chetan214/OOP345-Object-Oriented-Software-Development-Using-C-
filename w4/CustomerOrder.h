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

#ifndef SENECA_CUSTOMERORDER_H
#define SENECA_CUSTOMERORDER_H

#include <string> 
#include <iostream> 
#include "Station.h"

namespace seneca {

    // Customer order struct 
    struct Item {
        std::string m_itemName{};  // Name of the item
        size_t m_serialNumber{0};   // Serial num of item
        bool m_isFilled{false};    // Check to see if item is filled

        // Constructor to initialize the item
        Item(const std::string& src) : m_itemName(src) {}
    };

    class CustomerOrder {

        std::string m_name{};           // Customer's name
        std::string m_product{};        // Name of the product
        size_t m_cntItem{};             // Count of items in the customer order
        Item** m_lstItem = nullptr;   // Dynamic array of pointers for items
        static size_t m_widthField;

        public: 
            // Constructors - Destructs
            CustomerOrder() = default;
            CustomerOrder(const std::string& record);
            CustomerOrder& operator=(const CustomerOrder&) = delete;
            CustomerOrder(const CustomerOrder&);
            CustomerOrder(CustomerOrder&& src) noexcept;
            CustomerOrder& operator=(CustomerOrder&& src) noexcept;
            ~CustomerOrder();

            // For queries
            bool isOrderFilled() const; // Check to see if the order is filled or no
            bool isItemFilled(const std::string& itemName) const; // Check to see if a specific item is filled

            // Modifiers
            void fillItem(Station& station, std::ostream& os); // Fills item in current station
            void display(std::ostream& os) const; // Display order
    };
}

#endif // SENECA_CUSTOMERORDER_H