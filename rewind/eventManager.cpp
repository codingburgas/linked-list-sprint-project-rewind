#include "./pch.h"
#include "./eventManager.h"
#include "./eventStorage.h"
#include "./visualFunctions.h"
#include <vector>
#include <iostream>
#include <conio.h>

std::vector<Event> events;

const std::string eventsFilePath = "..\\rewind\\events.txt";

void AddEvent() {
    Event newEvent;
    do {
        std::cout << "Enter Event Date: ";
        std::getline(std::cin, newEvent.date);
        if (newEvent.date.empty())
            std::cout << "Date cannot be empty!\n";
    } while (newEvent.date.empty());

    do {
        std::cout << "Enter Event Title: ";
        std::getline(std::cin, newEvent.title);
        if (newEvent.title.empty())
            std::cout << "Title cannot be empty!\n";
    } while (newEvent.title.empty());

    do {
        std::cout << "Enter Event Theme: ";
        std::getline(std::cin, newEvent.theme);
        if (newEvent.theme.empty())
            std::cout << "Theme cannot be empty!\n";
    } while (newEvent.theme.empty());

    do {
        std::cout << "Enter Event Location: ";
        std::getline(std::cin, newEvent.location);
        if (newEvent.location.empty())
            std::cout << "Location cannot be empty!\n";
    } while (newEvent.location.empty());

    do {
        std::cout << "Enter Participants: ";
        std::getline(std::cin, newEvent.participants);
        if (newEvent.participants.empty())
            std::cout << "Participants cannot be empty!\n";
    } while (newEvent.participants.empty());

    do {
        std::cout << "Enter Result: ";
        std::getline(std::cin, newEvent.result);
        if (newEvent.result.empty())
            std::cout << "Result cannot be empty!\n";
    } while (newEvent.result.empty());

    events.push_back(newEvent);
    saveEventsToFile(events, eventsFilePath);

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

            saveEventsToFile(events, eventsFilePath);

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
                saveEventsToFile(events, eventsFilePath);
                std::cout << "\nEvent deleted!\n";
            }
            system("pause");
            return;
        }
    }
    std::cout << "Event not found!\n";
    system("pause");
}

void PrintEventDetails(const Event& event) {
    centerText("----------------------------------------");
    centerText("Date: " + event.date);
    centerText("Title: " + event.title);
    centerText("Theme: " + event.theme);
    centerText("Location: " + event.location);
    centerText("Participants: " + event.participants);
    centerText("Result: " + event.result);
}

void PrintAllEvents(const std::vector<Event>& events) {
    for (const auto& event : events) {
        PrintEventDetails(event);
    }
}

void loadEvents() {
    if (!loadEventsFromFile(events, eventsFilePath)) {
        std::cout << "No events found, starting fresh." << std::endl;
    }
}

void initializeEventSystem() {
    loadEvents();
}