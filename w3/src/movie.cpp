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

#include "movie.h"
namespace seneca {

// Display the movie details in a formatted way
void Movie::display(std::ostream& out) const {
    if (g_settings.m_tableView) { // Table view formatting
        out << "M | ";
        out << std::left << std::setfill('.');
        out << std::setw(50) << this->getTitle() << " | "; // Display title
        out << std::right << std::setfill(' ');
        out << std::setw(9) << this->getYear() << " | ";   // Display year
        out << std::left;

        // Handle summary width based on global settings
        if (g_settings.m_maxSummaryWidth > -1) {
            if (static_cast<short>(this->getSummary().size()) <= g_settings.m_maxSummaryWidth) {
                out << this->getSummary(); // Full summary if within limit
            } else {
                out << this->getSummary().substr(0, g_settings.m_maxSummaryWidth - 3) << "..."; // Truncated summary
            }
        } else {
            out << this->getSummary(); // Full summary if no limit
        }
        out << std::endl;
    } else { // Detailed view formatting
        size_t pos = 0;
        out << this->getTitle() << " [" << this->getYear() << "]\n"; // Title and year
        out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << "" << '\n';

        // Print the summary in chunks based on max width
        while (pos < this->getSummary().size()) {
            out << "    " << this->getSummary().substr(pos, g_settings.m_maxSummaryWidth) << '\n';
            pos += g_settings.m_maxSummaryWidth;
        }
        out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << "" << std::setfill(' ') << '\n';
    }
}

// Create a Movie object from a CSV-formatted string
Movie* Movie::createItem(const std::string& strMovie) {
    if (strMovie.empty() || strMovie[0] == '#') {
        throw "Not a valid movie."; // Invalid input
    }

    std::istringstream stream(strMovie);
    std::string title, yearStr, summary;

    // Parse the CSV fields
    std::getline(stream, title, ',');
    std::getline(stream, yearStr, ',');
    std::getline(stream, summary);

    // Trim leading and trailing whitespace
    trim(title);
    trim(yearStr);
    trim(summary);

    // Convert year string to an unsigned short
    unsigned short year = std::stoi(yearStr);

    // Create and return a new Movie object
    return new Movie(title, summary, year);
}

} // namespace end
