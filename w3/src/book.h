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

#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include "mediaItem.h"
#include "settings.h" // Global settings
#include <string>
#include <iomanip>
#include <sstream>

namespace seneca {

// The book class that inherits from MediaItem
class Book : public MediaItem {
private:
    std::string m_author;
    std::string m_country; // Country of publication
    double m_price;

    // Constructors to initialize a book object
    Book(const std::string& title, const std::string& summary, unsigned short year, 
         const std::string& author, const std::string& country, double price)
        : MediaItem(title, summary, year), m_author(author), m_country(country), m_price(price) {}

public:
    // Displays the book details 
    void display(std::ostream& out) const override;

    // Creates a book object from a CSV string
    static Book* createItem(const std::string& strBook);
};

} 

#endif // SENECA_BOOK_H
