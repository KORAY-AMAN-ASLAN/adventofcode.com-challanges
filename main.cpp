#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

// The purpose of this code is to extract calibration values from a file.
// Each line in the file is processed to find the first and last digit.
// These digits are then combined into a number.
// The sum of these numbers from all lines is then calculated.

// For details on the challenge, refer to: https://adventofcode.com/2023

// Function to extract the calibration value from a single line of text.
std::size_t extractCalibrationValue(const std::string &line) {
    char firstDigit = '\0', lastDigit = '\0';

    // Find the first digit
    for (const char &c : line) {
        if (isdigit(c)) {
            firstDigit = c;
            break;
        }
    }

    // Find the last digit using reverse iterator
    // For more information on reverse iterators:
    // https://cplusplus.com/reference/iterator/reverse_iterator/
    for (auto it = line.rbegin(); it != line.rend(); ++it) {
        if (isdigit(*it)) {
            lastDigit = *it;
            break;
        }
    }

    // Return 0 if either digit is not found
    if (firstDigit == '\0' || lastDigit == '\0') {
        return 0;
    }

    // Combine the digits and convert to number
    std::string valueStr = std::string(1, firstDigit) + lastDigit;
    return std::stoi(valueStr);
}

int main() {
    std::string fileName{"adventofcode.comChalllanges/file.txt"};
    std::ifstream file(fileName);

    // Check if the file is opened successfully
    if (!file.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }

    std::string line;
    std::size_t  totalValue = 0;

    // Read each line from the file and process
    while (getline(file, line)) {
        totalValue += extractCalibrationValue(line);
    }

    std::cout << "Total calibration value: " << totalValue << std::endl;

    // Close the file, good practise
    file.close();
    return 0;
}
