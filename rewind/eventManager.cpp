#include "./pch.h"
#include "eventManager.h"
#include "visualFunctions.h"
#include "eventStorage.h"
#include <cstdlib>

Event* head = nullptr;
const std::string eventsFilePath = "..\\rewind\\events.txt";

Event* createEventNode(const Event& newEvent) {
    Event* newNode = new Event;
    newNode->date = newEvent.date;
    newNode->title = newEvent.title;
    newNode->theme = newEvent.theme;
    newNode->location = newEvent.location;
    newNode->participants = newEvent.participants;
    newNode->result = newEvent.result;
    newNode->next = nullptr;
    return newNode;
}

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

    Event* newNode = createEventNode(newEvent);

    if (head == nullptr || head->date > newEvent.date) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Event* current = head;
        while (current->next != nullptr && current->next->date < newEvent.date) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    saveEventsToFile(head, eventsFilePath);

    std::cout << "\nEvent added successfully!\n";
    system("pause");
}

void EditEvent() {
    std::string title;
    std::cout << "Enter event title to edit: ";
    std::getline(std::cin, title);

    Event* current = head;
    while (current != nullptr) {
        if (current->title == title) {
            std::cout << "Editing: " << current->title << "\n";
            std::cout << "(Press ENTER to keep current value)\n";

            std::string temp;
            std::cout << "New Date (current: " << current->date << "): ";
            std::getline(std::cin, temp);
            if (!temp.empty()) current->date = temp;

            std::cout << "New Title (current: " << current->title << "): ";
            std::getline(std::cin, temp);
            if (!temp.empty()) current->title = temp;

            std::cout << "New Theme (current: " << current->theme << "): ";
            std::getline(std::cin, temp);
            if (!temp.empty()) current->theme = temp;

            std::cout << "New Location (current: " << current->location << "): ";
            std::getline(std::cin, temp);
            if (!temp.empty()) current->location = temp;

            std::cout << "New Participants (current: " << current->participants << "): ";
            std::getline(std::cin, temp);
            if (!temp.empty()) current->participants = temp;

            std::cout << "New Result (current: " << current->result << "): ";
            std::getline(std::cin, temp);
            if (!temp.empty()) current->result = temp;

            saveEventsToFile(head, eventsFilePath);

            std::cout << "Event updated successfully!\n";
            system("pause");
            return;
        }
        current = current->next;
    }
    std::cout << "Event not found!\n";
    system("pause");
}

void DeleteEvent() {
    std::string title;
    std::cout << "Enter event title to delete: ";
    std::getline(std::cin, title);

    Event* current = head;
    Event* previous = nullptr;

    while (current != nullptr) {
        if (current->title == title) {
            std::cout << "Are you sure? (y/n): ";
            char confirm = _getch();
            if (confirm == 'y' || confirm == 'Y') {
                if (previous == nullptr) {
                    head = current->next;
                }
                else {
                    previous->next = current->next;
                }
                delete current;
                saveEventsToFile(head, eventsFilePath);
                std::cout << "\nEvent deleted!\n";
            }
            system("pause");
            return;
        }
        previous = current;
        current = current->next;
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

void PrintAllEvents() {
    Event* current = head;
    while (current != nullptr) {
        PrintEventDetails(*current);
        current = current->next;
    }
}

void loadEvents() {
    if (!loadEventsFromFile(head, eventsFilePath)) {
        std::cout << "No events found, starting fresh." << std::endl;
    }
}

void initializeEventSystem() {
    loadEvents();
}
