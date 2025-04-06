#include "eventStorage.h"
#include <fstream>
#include <sstream>
#include <iostream>

void saveEventsToFile(Event* head, const std::string& fileName) {
    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        Event* current = head;
        while (current != nullptr) {
            outFile << current->date << ","
                << current->title << ","
                << current->theme << ","
                << current->location << ","
                << current->participants << ","
                << current->result << "\n";
            current = current->next;
        }
        outFile.close();
        std::cout << "Events saved successfully to " << fileName << std::endl;
    }
    else {
        std::cerr << "Error opening file for saving events!" << std::endl;
    }
}

bool loadEventsFromFile(Event*& head, const std::string& fileName) {
    std::ifstream inFile(fileName);
    if (inFile.is_open()) {
        std::string line;
        Event* tempHead = nullptr;

        while (std::getline(inFile, line)) {
            std::istringstream ss(line);
            Event newEvent;
            std::getline(ss, newEvent.date, ',');
            std::getline(ss, newEvent.title, ',');
            std::getline(ss, newEvent.theme, ',');
            std::getline(ss, newEvent.location, ',');
            std::getline(ss, newEvent.participants, ',');
            std::getline(ss, newEvent.result);

            Event* newNode = createEventNode(newEvent);

            if (tempHead == nullptr || tempHead->date > newEvent.date) {
                newNode->next = tempHead;
                tempHead = newNode;
            }
            else {
                Event* current = tempHead;
                while (current->next != nullptr && current->next->date < newEvent.date) {
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
            }
        }

        head = tempHead;
        inFile.close();
        return true;
    }
    else {
        std::cerr << "Error opening file for loading events!" << std::endl;
        return false;
    }
}