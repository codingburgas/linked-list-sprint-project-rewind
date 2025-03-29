#include "./pch.h"
#include "./reportsManager.h"
#include "./eventManager.h"
#include <iostream>

extern std::vector<Event> events;

void ShowEventsByDate(const std::vector<Event>& events) {
    std::string query;
    std::cout << "Enter date (or part of it) to search: ";
    std::getline(std::cin, query);

    bool found = false;
    for (const auto& event : events) {
        if (event.date.find(query) != std::string::npos) {
            PrintEventDetails(event);
            found = true;
        }
    }

    if (!found) std::cout << "No events found for this date.\n";
    system("pause");
}

void ShowEventsByTitle(const std::vector<Event>& events) {
    std::string query;
    std::cout << "Enter title (or part of it) to search: ";
    std::getline(std::cin, query);

    bool found = false;
    for (const auto& event : events) {
        if (event.title.find(query) != std::string::npos) {
            PrintEventDetails(event);
            found = true;
        }
    }

    if (!found) std::cout << "No events found with this title.\n";
    system("pause");
}

void ShowEventsByTheme(const std::vector<Event>& events) {
    std::string query;
    std::cout << "Enter theme (or part of it) to search: ";
    std::getline(std::cin, query);

    bool found = false;
    for (const auto& event : events) {
        if (event.theme.find(query) != std::string::npos) {
            PrintEventDetails(event);
            found = true;
        }
    }

    if (!found) std::cout << "No events found with this theme.\n";
    system("pause");
}

void ShowEventsByLocation(const std::vector<Event>& events) {
    std::string query;
    std::cout << "Enter location (or part of it) to search: ";
    std::getline(std::cin, query);

    bool found = false;
    for (const auto& event : events) {
        if (event.location.find(query) != std::string::npos) {
            PrintEventDetails(event);
            found = true;
        }
    }

    if (!found) std::cout << "No events found in this location.\n";
    system("pause");
}

void ShowEventsByParticipants(const std::vector<Event>& events) {
    std::string query;
    std::cout << "Enter participant name (or part of it) to search: ";
    std::getline(std::cin, query);

    bool found = false;
    for (const auto& event : events) {
        if (event.participants.find(query) != std::string::npos) {
            PrintEventDetails(event);
            found = true;
        }
    }

    if (!found) std::cout << "No events found with this participant.\n";
    system("pause");
}

void ShowEventsByResult(const std::vector<Event>& events) {
    std::string query;
    std::cout << "Enter result (or part of it) to search: ";
    std::getline(std::cin, query);

    bool found = false;
    for (const auto& event : events) {
        if (event.result.find(query) != std::string::npos) {
            PrintEventDetails(event);
            found = true;
        }
    }

    if (!found) std::cout << "No events found with this result.\n";
    system("pause");
}

void SearchEvent(const std::vector<Event>& events) {
    std::string query;
    std::cout << "Enter a keyword to search in all fields: ";
    std::getline(std::cin, query);

    bool found = false;
    for (const auto& event : events) {
        if (event.date.find(query) != std::string::npos ||
            event.title.find(query) != std::string::npos ||
            event.theme.find(query) != std::string::npos ||
            event.location.find(query) != std::string::npos ||
            event.participants.find(query) != std::string::npos ||
            event.result.find(query) != std::string::npos) {

            PrintEventDetails(event);
            found = true;
        }
    }

    if (!found) std::cout << "No events found matching that keyword.\n";
    system("pause");
}
