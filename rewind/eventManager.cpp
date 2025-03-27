#include "./pch.h"
#include "./eventManager.h"
#include <vector>
#include <iostream>

std::vector<Event> events;

void AddEvent() {
    Event newEvent;

    std::cout << "Enter Event Date: ";
    std::getline(std::cin, newEvent.date);

    do {
        std::cout << "Enter Event Title: ";
        std::getline(std::cin, newEvent.title);
        if (newEvent.title.empty()) std::cout << "Title cannot be empty!\n";
    } while (newEvent.title.empty());

    std::cout << "Enter Event Theme: ";
    std::getline(std::cin, newEvent.theme);
    std::cout << "Enter Event Location: ";
    std::getline(std::cin, newEvent.location);
    std::cout << "Enter Participants: ";
    std::getline(std::cin, newEvent.participants);
    std::cout << "Enter Result: ";
    std::getline(std::cin, newEvent.result);

    events.push_back(newEvent);
    std::cout << "\nEvent added successfully!\n";
    system("pause");
}

void EditEvent() {
    std::string title;
    std::cout << "Enter event title to edit: ";
    std::getline(std::cin, title);

    for (auto& event : events) {
        if (event.title == title) {
            std::cout << "Editing: " << event.title << "\n";
            std::cout << "(Press ENTER to keep current value)\n";

            std::string temp;
            std::cout << "New Date (current: " << event.date << "): ";
            std::getline(std::cin, temp);
            if (!temp.empty()) event.date = temp;

            std::cout << "New Title (current: " << event.title << "): ";
            std::getline(std::cin, temp);
            if (!temp.empty()) event.title = temp;

            std::cout << "New Theme (current: " << event.theme << "): ";
            std::getline(std::cin, temp);
            if (!temp.empty()) event.theme = temp;

            std::cout << "New Location (current: " << event.location << "): ";
            std::getline(std::cin, temp);
            if (!temp.empty()) event.location = temp;

            std::cout << "New Participants (current: " << event.participants << "): ";
            std::getline(std::cin, temp);
            if (!temp.empty()) event.participants = temp;

            std::cout << "New Result (current: " << event.result << "): ";
            std::getline(std::cin, temp);
            if (!temp.empty()) event.result = temp;

            std::cout << "Event updated successfully!\n";
            system("pause");
            return;
        }
    }
    std::cout << "Event not found!\n";
    system("pause");
}

void DeleteEvent() {
    std::string title;
    std::cout << "Enter event title to delete: ";
    std::getline(std::cin, title);

    for (auto it = events.begin(); it != events.end(); ++it) {
        if (it->title == title) {
            std::cout << "Are you sure? (y/n): ";
            char confirm = _getch();
            if (confirm == 'y' || confirm == 'Y') {
                events.erase(it);
                std::cout << "Event deleted!\n";
            }
            system("pause");
            return;
        }
    }
    std::cout << "Event not found!\n";
    system("pause");
}

void SearchEvent() {
    std::string query;
    std::cout << "Enter a keyword to search: ";
    std::getline(std::cin, query);

    bool found = false;
    for (const auto& event : events) {
        if (event.title.find(query) != std::string::npos || event.theme.find(query) != std::string::npos) {
            PrintEventDetails(event);
            found = true;
        }
    }

    if (!found) {
        std::cout << "No events found matching that keyword.\n";
    }
    system("pause");
}

void PrintEventDetails(const Event& event) {
    std::cout << "Date: " << event.date << "\n";
    std::cout << "Title: " << event.title << "\n";
    std::cout << "Theme: " << event.theme << "\n";
    std::cout << "Location: " << event.location << "\n";
    std::cout << "Participants: " << event.participants << "\n";
    std::cout << "Result: " << event.result << "\n";
    std::cout << "----------------------------------------\n";
}

void PrintAllEvents(const std::vector<Event>& events) {
    for (const auto& event : events) {
        PrintEventDetails(event);
    }
}
