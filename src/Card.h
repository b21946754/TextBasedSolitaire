//
// Created by bugra on 14/11/2020.
//

#ifndef ASSIGNMENT1_CARD_H
#define ASSIGNMENT1_CARD_H

const int MAX_SIZE = 60;

#include <string>
#include <iostream>
#include <utility>

class Card {
public:
    bool isOpen = false;

    int getSuit() {
        return this->suit;
    }

    int getNumber() {
        return this->number;
    }

    std::string getName() {
        if(name.empty() ) {
            return "EMP";
        }
        else if (isOpen) {
            return name;
        } else {
            return "@@@";
        }
    }
    void setName(std::string newName) {
        this -> name = newName;
        setSN();
    }

    void setSN () { // Set suit and number using card's name.
        if (name.substr(0, 1) == "H") {
            suit = 0;
        } else if (name.substr(0, 1) == "D") {
            suit = 1;
        } else if (name.substr(0, 1) == "S") {
            suit = 2;
        } else if (name.substr(0, 1) == "C") {
            suit = 3;
        }

        number = std::stoi(this->name.substr(1,2));
    }

private:
    std::string name; // name is for displaying, suit and number are for operations.
    int suit;
    int number;
};

class Stack {

public:
    int top = -1;
    Card data[MAX_SIZE];

    Card pop() {
        if (isEmpty()) {
            Card temp;
            temp.setName("NULL");
            return temp;
        }
        else {
            Card temp = data[top];
            top--;
            return temp;
        }
    }

    void push(Card card) {
        if (top >= MAX_SIZE - 1) {
        } else {
            top++;
            data[top] = card;
        }
    }

    void display() { // Used for testing
        for (int i = 0; i <= top; i++) {
            bool n = data[i].isOpen;
            data[i].isOpen = true;
            data[i].isOpen = n;
        }
    }

    bool isEmpty() {
        return this->top < 0;
    }

    Card topElem() {
        return this->data[this->top];
    }

    Card topIndexElem(int i) {
        return this->data[this->top - i];
    }
};


#endif //ASSIGNMENT1_CARD_H
