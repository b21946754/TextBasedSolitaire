//
// Created by bugra on 15/11/2020.
//

#include <iostream>
#include <fstream>
#include "Card.h"

Stack fileToStack (std::string fileName) {
    Stack stack;

    std::ifstream DeckFile(fileName);
    std::string line;

    while (std::getline(DeckFile, line)) {
        Card temp;
        temp.setName(line);

        stack.push(temp);
    }
    DeckFile.close();

    return stack;
}

void writeToFile(std::string fileName, std::string data, bool addLineBreak) {
    std::ofstream out;
    out.open(fileName, std::ios_base::app);
    out << data;
    if (addLineBreak) {
        out << std::endl;
    }
    out.close();
}
