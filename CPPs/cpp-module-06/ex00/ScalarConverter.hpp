#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <cmath>

class ScalarConverter
{
    private :
    	ScalarConverter();
        ~ScalarConverter();

    public :
        ScalarConverter &operator=(const ScalarConverter& sc);


        // Methods
        static void convert(std::string stRep);

        // exceptions
        class InvalidInputExc : public std::exception {
            public:
                virtual const char * what() const throw();
    	};
};

#endif