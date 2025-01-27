#include "ScalarConverter.hpp"

static bool isValid(std::string const & str) {
    if (str.empty())
        return false;

    // Check for special values
    if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" ||
        str == "-inf" || str == "-inff" || str == "inf" || str == "inff")
        return true;

    // Check for single character (char)
    if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
        return true;

    // Check for numeric literals (int, float, double)
    size_t i = 0;
    bool hasDecimal = false;
    bool hasFloatSuffix = false;

    // Optional sign
    if (str[i] == '+' || str[i] == '-')
        i++;

    // Digits before decimal point
    while (i < str.length() && std::isdigit(str[i]))
        i++;

    // Optional decimal point and digits after
    if (i < str.length() && str[i] == '.') {
        hasDecimal = true;
        i++;
        while (i < str.length() && std::isdigit(str[i]))
            i++;
    }

    // Optional float suffix
    if (i < str.length() && str[i] == 'f') {
        hasFloatSuffix = true;
        i++;
    }

    // If we've processed the entire string, it's valid
    return (i == str.length());
}


void ScalarConverter::convert(std::string const & str) {
    if (!isValid(str)) {
        std::cout << "Error: Invalid input format. Expected a char, int, float, or double literal." << std::endl;
        return;
    }

    if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0])) {
        std::cout << "char: '" << str[0] << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(str[0]) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
        return;
    }

    if (str == "nan" || str == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }

    if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
        return;
    }

    if (str == "-inf" || str == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }

    // Handle numeric conversions
    try {
        int i = std::stoi(str);
        std::cout << "char: ";
        if (i >= 32 && i <= 126)
            std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
        std::cout << "int: " << i << std::endl;
    } catch (std::exception & e) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }

    try {
        float f = std::stof(str);
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    } catch (std::exception & e) {
        std::cout << "float: impossible" << std::endl;
    }

    try {
        double d = std::stod(str);
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    } catch (std::exception & e) {
        std::cout << "double: impossible" << std::endl;
    }
}   