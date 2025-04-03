#include "./pch.h"
#include "./reportsManager.h"
#include "./eventManager.h"
#include "./visualFunctions.h"
#include <iostream>

void PrintReportHeader(const std::string& title) {
    /*clearScreen();
    std::cout << "\n";
    centerText("-----------------------");
    centerText("====================================");
    centerText(title + " REPORT");
    centerText("====================================");
    std::cout << "\n";*/
}

void PrintReportFooter() {
    /*std::cout << "\n";
    centerText("------------------------------------");
    centerText(" END OF REPORT");
    centerText("------------------------------------");
    std::cout << "\n";
    system("pause");*/
}

void ShowEventsByDate() {
    /*PrintReportHeader("EVENTS BY DATE");

    std::string searchQuery;
    centerText("Enter date (or part of it) to search:");
    std::cout << " > ";
    std::getline(std::cin, searchQuery);

    bool found = false;
    for (const auto& event : events) {
        if (event.date.find(searchQuery) != std::string::npos) {
            //PrintEventDetails(event);
            found = true;
        }
    }

    if (!found) {
        centerText("No events found for this date.");
    }

    PrintReportFooter();*/
}

void ShowEventsByTitle() {
    /*PrintReportHeader("EVENTS BY TITLE");

    std::string searchQuery;
    centerText("Enter title (or part of it) to search:");
    std::cout << " > ";
    std::getline(std::cin, searchQuery);

    bool found = false;
    for (const auto& event : events) {
        if (event.title.find(searchQuery) != std::string::npos) {
            //PrintEventDetails(event);
            found = true;
        }
    }

    if (!found) {
        centerText("No events found for this title.");
    }

    PrintReportFooter();*/
}

void ShowEventsByTheme() {
    /*PrintReportHeader("EVENTS BY THEME");

    std::string searchQuery;
    centerText("Enter theme (or part of it) to search:");
    std::cout << " > ";
    std::getline(std::cin, searchQuery);

    bool found = false;
    for (const auto& event : events) {
        if (event.theme.find(searchQuery) != std::string::npos) {
            //PrintEventDetails(event);
            found = true;
        }
    }

    if (!found) {
        centerText("No events found for this theme.");
    }

    PrintReportFooter();*/
}

void ShowEventsByLocation() {
    /*PrintReportHeader("EVENTS BY LOCATION");

    std::string searchQuery;
    centerText("Enter location (or part of it) to search:");
    std::cout << " > ";
    std::getline(std::cin, searchQuery);

    bool found = false;
    for (const auto& event : events) {
        if (event.location.find(searchQuery) != std::string::npos) {
            //PrintEventDetails(event);
            found = true;
        }
    }

    if (!found) {
        centerText("No events found for this location.");
    }

    PrintReportFooter();*/
}

void ShowEventsByParticipants() {
    /*PrintReportHeader("EVENTS BY PARTICIPANTS");

    std::string searchQuery;
    centerText("Enter participants (or part of it) to search:");
    std::cout << " > ";
    std::getline(std::cin, searchQuery);

    bool found = false;
    for (const auto& event : events) {
        if (event.participants.find(searchQuery) != std::string::npos) {
            //PrintEventDetails(event);
            found = true;
        }
    }

    if (!found) {
        centerText("No events found for these participants.");
    }

    PrintReportFooter();*/
}

void ShowEventsByResult() {
    /*PrintReportHeader("EVENTS BY RESULT");

    std::string searchQuery;
    centerText("Enter result (or part of it) to search:");
    std::cout << " > ";
    std::getline(std::cin, searchQuery);

    bool found = false;
    for (const auto& event : events) {
        if (event.result.find(searchQuery) != std::string::npos) {
            //PrintEventDetails(event);
            found = true;
        }
    }

    if (!found) {
        centerText("No events found for this result.");
    }

    PrintReportFooter();*/
}

void SearchEvent() {
    /*PrintReportHeader("SEARCH EVENTS");

    std::string query;
    centerText("Enter a keyword to search in all fields (or press Enter to see all):");
    std::cout << " > ";
    std::getline(std::cin, query);

    bool found = false;
    for (const auto& event : events) {
        if (query.empty() || 
            event.date.find(query) != std::string::npos ||
            event.title.find(query) != std::string::npos ||
            event.theme.find(query) != std::string::npos ||
            event.location.find(query) != std::string::npos ||
            event.participants.find(query) != std::string::npos ||
            event.result.find(query) != std::string::npos) {

            //PrintEventDetails(event);
            found = true;
        }
    }

    if (!found) centerText("No events found matching that keyword.");

    PrintReportFooter();*/
}