#include "eventMenu.h"

void printEvents(EVENT* head, int currentEvent, int selectedEvent, int startIndex, int displayedEvents, bool eventIsChosen, std::string username) {
    if (!head) return;
    else if (currentEvent >= startIndex && currentEvent <= startIndex + displayedEvents - 1) {

        std::string eventDiscription = head->title + ": " + head->location + ", " + head->date + ". " + "Carried out by " + head->participants +
            ", resulting in a " + ((head->winForBulgaria) ? "Win" : "Loss") + " for Bulgaria.";

        std::cout << std::string((getConsoleWidth() - eventDiscription.length()) / 2 - ((selectedEvent == currentEvent) ? 5 : 0), ' ');

        if (currentEvent == selectedEvent) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
            std::cout << " --> ";
            if (!eventIsChosen) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }

        std::cout << eventDiscription << std::endl;

        std::cout << std::string((getConsoleWidth() - eventDiscription.length()) / 2, ' ');
        std::cout << "Keywords: " << head->theme + "           Added by: ";
        if (head->eventContributor == username)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        std::cout << head->eventContributor;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        paddingUp(2);
    }
    printEvents(head->next, currentEvent + 1, selectedEvent, startIndex, displayedEvents, eventIsChosen, username);
}

void showEventsMenu(std::string username) {
    clearScreen();

    std::string eventsMenuOptions[4] = {
        "Add Event",
        "Edit Event",
        "Delete Event",
        "Back"
    };

    bool selecting = true;
    bool selectingEvents = true;

    bool eventIsChosen = false;

    EVENT* allEvents = new EVENT;
    allEvents = nullptr;

    initializeEvents(&allEvents);

    int selectedOption = -1;
    int selectedEvent = 0;

    int startIndex = 0;

    while (selecting) {
        if (!allEvents) {
            addFirstEvent(&allEvents, username);
        }

        clearScreen();

        paddingUp(20);

        printEvents(allEvents, 0, startIndex + selectedEvent, startIndex, 8, eventIsChosen, username);

        paddingUp(3);

        printBoxesB(eventsMenuOptions, 4, selectedOption, 38, 2);

        char input = _getch();

        if (selectingEvents) {
            if (input == 72) {
                if (selectedEvent == 0) {
                    if (startIndex >= 8) {
                        startIndex -= 8;
                        selectedEvent = 7;
                    }
                }
                else {
                    selectedEvent--;
                }
            }
            else if (input == 80) {
                if (selectedEvent == 7 || (startIndex + selectedEvent + 1 >= getEventCount(allEvents))) {
                    if (startIndex + 8 < getEventCount(allEvents)) {
                        startIndex += 8;
                        selectedEvent = 0;
                    }
                }
                else {
                    selectedEvent++;
                }
            }
        }

        if (eventIsChosen) {
            if (input == 75) selectedOption = (selectedOption == 0) ? 3 : selectedOption - 1;
            else if (input == 77) selectedOption = (selectedOption == 3) ? 0 : selectedOption + 1;
        }

        if (input == 13) {
            if (selectingEvents) {
                selectingEvents = false;
                eventIsChosen = true;
                selectedOption = 0;
            }
            else {
                if (selectedOption == 0) {
                    selectingEvents = true;
                    eventIsChosen = false;
                    selectedOption = -1;
                    addEvent(&allEvents, username);
                }
                else if (selectedOption == 1) {
                    selectingEvents = true;
                    eventIsChosen = false;
                    selectedOption = -1;
                    editEvent(&allEvents, getElementByIndex(allEvents, selectedEvent + startIndex));
                }
                else if (selectedOption == 2) {
                    selectingEvents = true;
                    eventIsChosen = false;
                    selectedOption = -1;
                    confirmChanges(&allEvents, getElementByIndex(allEvents, selectedEvent + startIndex), 3);
                }
                else if (selectedOption == 3) {
                    clearList(&allEvents);
                    showMainMenu(username);
                }
            }
        }
    }
}