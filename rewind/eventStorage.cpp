#include "eventStorage.h"
#include <fstream>
#include <sstream>
#include <iostream>

void saveEventsToFile(const std::vector<Event>& events, const std::string& fileName) {
    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        for (const auto& event : events) {
            outFile << event.date << ","
                << event.title << ","
                << event.theme << ","
                << event.location << ","
                << event.participants << ","
                << event.result << "\n";
        }
        outFile.close();
        std::cout << "Events saved successfully to " << fileName << std::endl;
    }
    else {
        std::cerr << "Error opening file for saving events!" << std::endl;
    }
}

bool loadEventsFromFile(std::vector<Event>& events, const std::string& fileName) {
    std::ifstream inFile(fileName);
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::istringstream ss(line);
            Event event;
            std::getline(ss, event.date, ',');
            std::getline(ss, event.title, ',');
            std::getline(ss, event.theme, ',');
            std::getline(ss, event.location, ',');
            std::getline(ss, event.participants, ',');
            std::getline(ss, event.result);
            events.push_back(event);
        }
        inFile.close();
        return true;
    }
    else {
        std::cerr << "Error opening file for loading events!" << std::endl;
        return false;
    }
}