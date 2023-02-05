#include <fstream>
#include <vector>
#include <sstream> 

// A class to handle the reading of scv files
class CSVFileManager {

	public:

        // Returns a vector of strings of all the lines in the csv file passed in
        std::vector<std::vector<std::string> > parseCSV(const char * filename)
        {
            std::ifstream data(filename);
            std::string line;
            std::vector<std::vector<std::string> > parsedCsv;
            // loops through the lines
            while (std::getline(data, line))
            {
                // Gets the line 
                std::stringstream lineStream(line);
                // Gets each cell
                std::string cell;
                // Creates a vector for the row
                std::vector<std::string> parsedRow;
                while (std::getline(lineStream, cell, ','))
                {
                    parsedRow.push_back(cell);
                }
                // Pushes the row to the vector
                parsedCsv.push_back(parsedRow);
            }
            return parsedCsv;
        };
};

	

