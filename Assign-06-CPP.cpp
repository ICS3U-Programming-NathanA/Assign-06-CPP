// Copyright (c) 2022 Nathan All rights reserved.
//
// Created by: Nathan
// Date: Dec 8, 2022
// This program calculates the surface area of a cylinder,
// the circumference and area of the circles on the top and bottom

#include <algorithm>
#include <iostream>
#include <list>
#include <string>

// Function to calculate the area of the circles
std::list<int> evenList(std::list<int> numList) {
    // Declare area as a float
    std::list<int> evenNumList;
    // Area of a circle formula
    for (int counter : numList) {
        if (counter % 2 == 0) {
            evenNumList.push_back(counter);
        }
    }
    // return area to main()
    return evenNumList;
}

// Function to calculate the area of the circles
std::list<int> oddList(std::list<int> numList) {
    // Declare area as a float
    std::list<int> oddNumList;
    // Area of a circle formula
    for (int counter : numList) {
        if (counter % 2 != 0) {
            oddNumList.push_back(counter);
        }
    }
    // return area to main()
    return oddNumList;
}

// Function to calculate the surface area of the cylinder
int averageEven(std::list<int> evenListNum) {
    // delcare surfaceArea as a float
    int sum = 0;
    int average = 0;
    // surfaceArea of a circle formula
    for (int counter : evenListNum) {
        sum = sum + counter;
    }
    // fghfgh
    average = sum / evenListNum.size();
    // fgddfg
    return average;
}

// Function to calculate the surface area of the cylinder
int averageOdd(std::list<int> oddListNum) {
    // delcare surfaceArea as a float
    int sum = 0;
    // sadasd
    int average = 0;
    // surfaceArea of a circle formula
    for (int counter : oddListNum) {
        sum = sum + counter;
    }
    // asdasd
    average = sum / sizeof(oddListNum);
    // asdsad
    return average;
}
int main() {
    // Declaring userRadius, userHeight, surfaceArea,
    // circumference, area to floats
    std::list<int> userNumList, evenIntegers, oddIntegers;
    // Declaring userRadiusStr, userHeightStr, playAgain, userUnits to strings
    std::string userNumStr, evenOrOdd, averageQuestionEven, averageQuestionOdd;

    int userNumInt, average;
    // Do while statement for the user to be able to restart the program
    do {
        // Gets userRadiusStr from the user
        std::cout << "Enter a integer or type stop: ";
        std::cin >> userNumStr;
        std::transform(userNumStr.begin(), userNumStr.end(),
                       userNumStr.begin(), ::toupper);
        // A try catch to to catch any invalid inputs
        if (userNumStr == "STOP") {
            std::cout << "Type e for even and type o for odd: ";
            std::cin >> evenOrOdd;
            std::transform(evenOrOdd.begin(), evenOrOdd.end(),
                           evenOrOdd.begin(), ::toupper);
            if (evenOrOdd == "E") {
                evenIntegers = evenList(userNumList);
                std::cout << "The even integers are: ";
                for (int num : evenIntegers) {
                    std::cout << num << " ";
                }
                std::cout << std::endl;
                std::cout << "Would you like to find the average of these numbers? (y or n): ";
                std::cin >> averageQuestionEven;
                std::transform(averageQuestionEven.begin(), averageQuestionEven.end(),
                               averageQuestionEven.begin(), ::toupper);
                if (averageQuestionEven == "Y") {
                    average = averageEven(evenIntegers);
                    std::cout << "The average of all the numbers is " << average << "\n";
                }
                break;
            } else if (evenOrOdd == "O") {
                oddIntegers = oddList(userNumList);
                std::cout << "The even integers are: ";
                for (int num : evenIntegers) {
                    std::cout << num << " ";
                }
                std::cout << std::endl;
                std::cout << "Would you like to find the average of these numbers? (y or n): ";
                std::cin >> averageQuestionOdd;
                std::transform(averageQuestionOdd.begin(), averageQuestionOdd.end(),
                               averageQuestionOdd.begin(), ::toupper);
                if (averageQuestionOdd == "Y") {
                    average = averageOdd(oddIntegers);
                    std::cout << "The average of all the numbers is " << average << "\n";
                }
                break;
            } else {
                std::cout << "Enter either 'E', 'O' \n";
                break;
            }
        }
        try {
            userNumInt = std::stod(userNumStr);
            userNumList.push_back(userNumInt);
            std::cout
                << "Added the integer to the list \n";

        } catch (std::invalid_argument) {
            std::cout
                << "You must enter a number for both inputs."
                << std::endl;
        }
    } while (userNumStr != "STOP");
}
