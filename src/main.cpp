#include <iostream>
#include <fstream>

#include "Card.h"
#include "IO.h"
#include "Game.h"

Stack Game::tableau[7];
Stack Game::stock;
Stack Game::waste;
Stack Game::foundation[4];

int Game::wasteOpen;

int main(int argc, char **argv) {
    Stack deck = ASSIGNMENT1_IO_H::fileToStack(argv[1]);

    Game::dealCards(deck);

    // Read the command
    std::ifstream in;
    in.open(argv[2], std::ifstream::in);
    std::string line;
    std::string lineArray[256];

    // Place the command lines into an array
    int k = 0;
     while (std::getline(in, line)) {
        lineArray[k++] = line;
    }

    // Set the output file
    std::ofstream out;
    out.open(argv[3], std::ofstream::out | std::ofstream::trunc);
    out.close();
    out.open(argv[3], std::ofstream::app);

    // Execute the input commands
    int commandLine = 0;
    bool ended = false;
    while (!ended)  {

        std::string cmd;

        cmd = lineArray[commandLine++];

        if (lineArray[commandLine].empty()) {
            ended = true;
        }

        // Split the input command by spaces

        std::string cmdArray[5];

        std::string cmdCopy = cmd;

        std::string dlm = " ";
        int n = 0;
        std::string token;
        n = cmd.find(dlm);
        int i = 0;
        while (n != std::string::npos) {
            token = cmd.substr(0, n);
            cmdArray[i++] = token;
            cmd.erase(0, n + 1);

            n = cmd.find(dlm);
        }
        cmdArray[i] = cmd;

        ASSIGNMENT1_IO_H::displayUpper(Game::waste, Game::foundation, Game::stock, Game::wasteOpen, argv[3]);
        ASSIGNMENT1_IO_H::displayTableau(Game::tableau, argv[3]);

        out << cmdCopy << std::endl << std::endl;

        if (cmdArray[0] == "move" && cmdArray[1] != "to") {
            if (cmdArray[1] == "pile") {
                Game::move("pile", stoi(cmdArray[2]), stoi(cmdArray[3]), stoi(cmdArray[4]), argv[3]);

            } else if (cmdArray[1] == "waste") {
                Game::move("waste", 0, 0, stoi(cmdArray[2]), argv[3]);

            } else if (cmdArray[1] == "foundation") {
                Game::move("foundation", stoi(cmdArray[2]), 0, stoi(cmdArray[3]), argv[3]);

            } else {
                out << "Invalid Move! : In move command " << std::endl;
            }
        } else if (cmdArray[0] == "exit") {
            Game::exit(argv[3]);
            ended = true;

        } else if (cmdArray[0] == "open" && cmdArray[1] == "from" && cmdArray[2] == "stock") {
            Game::openStock();

        } else if (cmdArray[0] == "open") {
            Game::open(stoi(cmdArray[1]), argv[3]);

        } else if (cmdArray[0] == "move" && cmdArray[1] == "to" && cmdArray[2] == "foundation") {
            if (cmdArray[3] == "pile") {
                Game::moveToFoundation("pile", stoi(cmdArray[4]), argv[3]);

            } else if (cmdArray[3] == "waste") {
                Game::moveToFoundation("waste", 0, argv[3]);
            }
        }  else {
            out << "Invalid Move!" << std::endl;
        }

        out << "****************************************" << std::endl;

         bool winFlag = true;
         for (int j = 0; j < 4; j++) { // End the game if all foundation piles' top elements' numbers are 13
             winFlag = winFlag && (Game::foundation[j].topElem().getNumber() == 13);
         }
         if (winFlag) {
             out << "You Win!" << std::endl;
             ended = true;
         }
    }

    ASSIGNMENT1_IO_H::displayUpper(Game::waste, Game::foundation, Game::stock, Game::wasteOpen, argv[3]);
    ASSIGNMENT1_IO_H::displayTableau(Game::tableau, argv[3]);

    out << "****************************************" << std::endl;

    out << "Game Over!" << std::endl;

    out.close();
}
