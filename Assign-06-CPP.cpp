// Copyright (c) 2022 Nathan All rights reserved.
//
// Created by: Nathan
// Date: Dec 21, 2022
// This program finds the even numbers of a list it then displays it

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>

// function that finds the even numbers inside the list
std::list<int> evenList(std::list<int> numList) {
    // Create a new list to store the even integers
    std::list<int> evenNumList;
    // Iterate through the list of integers
    for (int counter : numList) {
        if (counter % 2 == 0) {
            evenNumList.push_back(counter);
        }
    }
    // return Return the list of even integers
    return evenNumList;
}

// function that finds the odd numbers inside the list
std::list<int> oddList(std::list<int> numList) {
    // Create a new list to store the odd integers
    std::list<int> oddNumList;
    // for each loop to determine all the odd numbers
    for (int counter : numList) {
        // if the number is odd then add it to a new list
        if (counter % 2 != 0) {
            oddNumList.push_back(counter);
        }
    }
    // return oddNumList
    return oddNumList;
}

// Function for finding the average of even numbers
float averageEven(std::list<int> evenListNum) {
    // set sum to 0
    float sum = 0;
    // set average to 0
    float average = 0;
    // for each loop to calculate the sum of all the even numbers
    for (int counter : evenListNum) {
        sum = sum + counter;
    }
    // sum divided by the length to find the average
    average = sum / evenListNum.size();
    // return average
    return average;
}

// Function for finding the average of odd numbers
float averageOdd(std::list<int> oddListNum) {
    // set sum to 0
    float sum = 0;
    // set average to 0
    float average = 0;
    // for each loop to calculate the sum of all the odd numbers
    for (int counter : oddListNum) {
        sum = sum + counter;
    }
    // sum divided by the length to find the average
    average = sum / oddListNum.size();
    // return the average
    return average;
}
int main() {
    // set userNumList, evenIntegers, oddIntegers to an empty list
    std::list<int> userNumList, evenIntegers, oddIntegers;
    // Declare userNumStr, evenOrOdd, averageQuestionEven,
    // averageQuestionOdd to strings
    std::string userNumStr, evenOrOdd, averageQuestionEven, averageQuestionOdd;
    // Declare average as a float
    float average;
    // declare userNumInt as a int
    int userNumInt;
    // do while loop so the user can enter multiple integers
    do {
        // Ask the user to enter a list of integers
        std::cout << "Enter a integer or type stop: ";
        std::cin >> userNumStr;
        // sets userNumStr to all uppercase
        std::transform(userNumStr.begin(), userNumStr.end(),
                       userNumStr.begin(), ::toupper);
        // if user_num_str is "STOP"
        if (userNumStr == "STOP") {
            // Asks the user if they want to see the
            // even integers, odd integers in the list
            std::cout << "Type e for even and type o for odd: ";
            std::cin >> evenOrOdd;
            // sets evenOrOdd to all uppercase
            std::transform(evenOrOdd.begin(), evenOrOdd.end(),
                           evenOrOdd.begin(), ::toupper);
            // if even_or_odd is "E"
            if (evenOrOdd == "E") {
                // call even_list(user_num_list)
                evenIntegers = evenList(userNumList);
                // Print the even integers
                std::cout << "The even integers are: ";
                for (int counter : evenIntegers) {
                    std::cout << counter << " ";
                }
                std::cout << std::endl;
                // Asks the user if they want to find
                // the average of the new list
                std::cout
                    << "Would you like to find the average of these numbers?"
                    << "(y or n): ";
                std::cin >> averageQuestionEven;
                // set averageQuestionEven to all uppercase
                std::transform(averageQuestionEven.begin(),
                               averageQuestionEven.end(),
                               averageQuestionEven.begin(), ::toupper);
                // if they answer with "Y"
                if (averageQuestionEven == "Y") {
                    // call average_even(even_integers)
                    average = averageEven(evenIntegers);
                    // print the average
                    std::cout << "The average of all the numbers is "
                              << std::setprecision(4) << average << "\n";
                } else if (averageQuestionOdd == "N") {
                    // breaks out of loop
                    break;
                } else {
                    // if they don't enter Y or N
                    std::cout << "You must enter 'Y' or 'N'\n";
                    // breaks out of loop
                    break;
                }
                // break out of the loop
                break;
                // elif even_or_odd is "O"
            } else if (evenOrOdd == "O") {
                // call odd_list(user_num_list)
                oddIntegers = oddList(userNumList);
                // Print the odd integers
                std::cout << "The odd integers are: ";
                for (int counter : oddIntegers) {
                    std::cout << counter << " ";
                }
                std::cout << std::endl;
                // Asks the user if they want to find
                // the average of the new list
                std::cout
                    << "Would you like to find the average of these numbers?"
                    << "(y or n): ";
                std::cin >> averageQuestionOdd;
                // set averageQuestionOdd to all uppercase
                std::transform(averageQuestionOdd.begin(),
                               averageQuestionOdd.end(),
                               averageQuestionOdd.begin(), ::toupper);
                // if they answer with "Y"
                if (averageQuestionOdd == "Y") {
                    // call average_even(odd_integers)
                    average = averageOdd(oddIntegers);
                    // print the average
                    std::cout << "The average of all the numbers is "
                              << std::setprecision(4) << average << "\n";
                    // if they answer with "N"
                } else if (averageQuestionOdd == "N") {
                    // breaks out of loop
                    break;
                } else {
                    // if they don't enter Y or N
                    std::cout << "You must enter 'Y' or 'N'\n";
                    // breaks out of loop
                    break;
                }
                // break out of the loop
                break;
            } else {
                // You must enter either E or O
                std::cout << "Enter either 'E' or 'O'\n";
                // break out of the loop
                break;
            }
            // checks if the user has a decimal in their number
        }
        if (userNumStr.find('.') != std::string::npos) {
            std::cout << "You must You must enter a integer or 'STOP'\n";
            // breaks out of the loop
            break;
        }
        // Try catch to catch any invalid inputs
        try {
            userNumInt = std::stoi(userNumStr);
            // add userNumInt to userNumList
            userNumList.push_back(userNumInt);
            // print that it was added
            std::cout
                << "Added the integer to the list \n";
        } catch (std::invalid_argument) {
            // If they entered a invalid input then display this
            std::cout
                << "You must enter a integer or 'STOP'."
                << std::endl;
            // break out of the loop
            break;
        }
        // while userNumStr does not equal "STOP"
    } while (userNumStr != "STOP");
}
