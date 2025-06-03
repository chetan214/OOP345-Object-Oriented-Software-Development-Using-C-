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

#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H

#include "mediaItem.h"  
#include "settings.h" 
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
namespace seneca {

// Represents a Movie, inheriting from MediaItem
class Movie : public MediaItem {
    // Private constructor to ensure controlled creation
    Movie(const std::string& title, const std::string& summary, unsigned short year)
        : MediaItem(title, summary, year) {}

public:
    // Display the movie details
    void display(std::ostream& out) const override;

    // Create a Movie object from a CSV-formatted string
    static Movie* createItem(const std::string& strMovie);
};
}

#endif // SENECA_MOVIE_H
