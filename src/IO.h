//
// Created by bugra on 15/11/2020.
//

#ifndef ASSIGNMENT1_IO_H
#define ASSIGNMENT1_IO_H

#include <fstream>

void writeToFile(std::string fileName, std::string data, bool addLineBreak);

Stack fileToStack (std::string fileName);

static void displayTableau(Stack  tableau[7], std::string fileName) {
    std::ofstream out;
    out.open(fileName, std::ios_base::app);

    int maxHeight = 0;

    //Finding the maximum height to set a vertical bound on next for loop
    for (int i = 0; i < 7; i++) {
        if (tableau[i].top > maxHeight) {
            maxHeight = tableau[i].top;
        }
    }

    for (int i = 0; i <= maxHeight; i++) { // Vertical looping
        for (int j = 0; j < 7; j++) { // Horizontal looping
            if (i <= tableau[j].top) {
                out << tableau[j].data[i].getName() << "   ";
            } else {
                out << "      ";
            }
        }
        out << std::endl;
    }
    out << std::endl;

    out.close();
}

static void displayUpper(Stack waste, Stack foundation[4], Stack stock, int wasteOpen, std::string fileName) {
    std::ofstream out;
    out.open(fileName, std::ios_base::app);

    out << std::endl;

    if (!stock.isEmpty()) {
        out << "@@@" << " ";
    } else {
        out << "___" << " ";
    }

    for (int i = 0; i < wasteOpen; i++) {
        out << waste.data[(waste.top - wasteOpen + 1) + i].getName() << " ";
    }
    for (int k = 0; k < 3 - wasteOpen; k++) {
        out << "___" << " ";
    }

    out << "        "; // 8 spaces
    for (int j = 0; j < 4; j++) {
        if (foundation[j].isEmpty()) {
            out << "___" << " ";
        } else {
            out << foundation[j].topElem().getName() << " ";
        }
    }
    out << std::endl << std::endl;

    out.close();
}



#endif //ASSIGNMENT1_IO_H
