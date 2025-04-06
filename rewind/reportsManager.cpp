#include "./pch.h"
#include "./reportsManager.h"
#include "./eventManager.h"
#include "./visualFunctions.h"

extern Event* head;

void PrintReportHeader(const std::string& title) {
    clearScreen();
    std::cout << "\n";
    centerText("-----------------------");
    centerText("====================================");
    centerText(title + " REPORT");
    centerText("====================================");
    std::cout << "\n";
}

void PrintReportFooter() {
    std::cout << "\n";
    centerText("------------------------------------");
    centerText(" END OF REPORT");
    centerText("------------------------------------");
    std::cout << "\n";

    centerText("Press any key to continue...");
    _getch();
}

void ShowEventsByField(const std::string& prompt, const std::string& fieldName) {
    PrintReportHeader("EVENTS BY " + fieldName);

    std::string searchQuery;
    centerText(prompt);
    std::cout << std::string((getConsoleWidth() - 1) / 2, ' ') << " > ";
    std::getline(std::cin, searchQuery);

    if (searchQuery.empty()) {
        centerText("Search cancelled. Returning to menu...");
        centerText("Press any key to continue...");
        _getch();
        return;
    }

    bool found = false;
    Event* current = head;

    while (current != nullptr) {
        std::string fieldValue;

        if (fieldName == "DATE") {
            fieldValue = current->date;
            std::cout << "Checking DATE: " << fieldValue << std::endl;
        }
        else if (fieldName == "TITLE") {
            fieldValue = current->title;
            std::cout << "Checking TITLE: " << fieldValue << std::endl;
        }
        else if (fieldName == "THEME") {
            fieldValue = current->theme;
            std::cout << "Checking THEME: " << fieldValue << std::endl;
        }
        else if (fieldName == "LOCATION") {
            fieldValue = current->location;
            std::cout << "Checking LOCATION: " << fieldValue << std::endl;
        }
        else if (fieldName == "PARTICIPANTS") {
            fieldValue = current->participants;
            std::cout << "Checking PARTICIPANTS: " << fieldValue << std::endl;
        }
        else if (fieldName == "RESULT") {
            fieldValue = current->result;
            std::cout << "Checking RESULT: " << fieldValue << std::endl;
        }

        if (fieldValue.find(searchQuery) != std::string::npos) {
            PrintEventDetails(*current);
            found = true;
        }

        current = current->next;
    }

    if (!found) centerText("No events found matching this " + fieldName + ".");

    PrintReportFooter();
}

void ShowEventsByDate() {
    ShowEventsByField("Enter date (or part of it) to search:", "DATE");
}

void ShowEventsByTitle() {
    ShowEventsByField("Enter title (or part of it) to search:", "TITLE");
}

void ShowEventsByTheme() {
    ShowEventsByField("Enter theme (or part of it) to search:", "THEME");
}

void ShowEventsByLocation() {
    ShowEventsByField("Enter location (or part of it) to search:", "LOCATION");
}

void ShowEventsByParticipants() {
    ShowEventsByField("Enter participants (or part of it) to search:", "PARTICIPANTS");
}

void ShowEventsByResult() {
    ShowEventsByField("Enter result (or part of it) to search:", "RESULT");
}

void SearchEvent() {
    PrintReportHeader("SEARCH EVENTS");

    std::string query;
    centerText("Enter a keyword to search in all fields (or press Enter to see all):");
    std::cout << std::string((getConsoleWidth() - 1) / 2, ' ') << " > ";
    std::getline(std::cin, query);

    bool found = false;
    Event* current = head;

    while (current != nullptr) {
        if (query.empty() ||
            current->date.find(query) != std::string::npos ||
            current->title.find(query) != std::string::npos ||
            current->theme.find(query) != std::string::npos ||
            current->location.find(query) != std::string::npos ||
            current->participants.find(query) != std::string::npos ||
            current->result.find(query) != std::string::npos) {

            PrintEventDetails(*current);
            found = true;
        }
        current = current->next;
    }

    if (!found) centerText("No events found matching that keyword.");

    PrintReportFooter();
}
