#include "eventManager.h"

void updateEventsFile(EVENT* head) {
    std::ofstream outFile("events.csv", std::ios::trunc);

    EVENT* current = head;
    while (current) {
        outFile << current->title << ','
            << current->date << ','
            << current->theme << ','
            << current->location << ','
            << current->participants << ','
            << current->eventContributor << ','
            << (current->winForBulgaria ? "1" : "0") << '\n';
        current = current->next;
    }

    outFile.close();
}

void updateLinePos(std::string& currentLine, size_t& commaPos) {
    currentLine = currentLine.substr(commaPos + 1);
    commaPos = currentLine.find(',');
}

bool isDateValid(std::string& date) {
    if (date.length() < 7) return false;

    if (date[2] != '-' || date[5] != '-') return false;

    int day = (date[0] - '0') * 10 + (date[1] - '0');
    int month = (date[3] - '0') * 10 + (date[4] - '0');
    int year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');

    if (day < 1 || day > 31) return false;
    if (month < 1 || month > 12) return false;
    if (year < 0) return false;

    return true;
}

int getPosDate(EVENT* head, const EVENT& newEvent) {
    int index = 0;

    int newDay = std::stoi(newEvent.date.substr(0, 2));
    int newMonth = std::stoi(newEvent.date.substr(3, 2));
    int newYear = std::stoi(newEvent.date.substr(6, 4));

    while (head) {
        int headDay = std::stoi(head->date.substr(0, 2));
        int headMonth = std::stoi(head->date.substr(3, 2));
        int headYear = std::stoi(head->date.substr(6, 4));

        if (headYear > newYear ||
            (headYear == newYear && headMonth > newMonth) ||
            (headYear == newYear && headMonth == newMonth && headDay > newDay)) {
            return index;
        }

        head = head->next;
        index++;
    }

    return index;
}

bool findEventByTitle(std::string eventTitle) {
    std::ifstream file;
    file.open("events.csv", std::ios_base::in);

    std::string currentLine;

    while (std::getline(file, currentLine)) {
        size_t commaPos = currentLine.find(',');
        if (commaPos == std::string::npos) {
            continue;
        }
        if (currentLine.substr(0, commaPos) == eventTitle) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

bool validEventRange(char input) {
    return (input >= '0' && input <= '9') ||
        (input >= 'A' && input <= 'Z') ||
        (input >= 'a' && input <= 'z') ||
        input == '.' ||
        input == '_' ||
        input == '\'' ||
        input == ' ' ||
        input == '-';
}

bool areAttributesFilled(EVENT* newEvent) {
    return !newEvent->title.empty() &&
        !newEvent->date.empty() &&
        !newEvent->theme.empty() &&
        !newEvent->location.empty() &&
        !newEvent->participants.empty();
}

void initializeEvents(EVENT** head) {
    std::ifstream file;
    file.open("events.csv", std::ios_base::in);

    if (!file.is_open()) {
        centerText("Error, could open the file");
        return;
    }

    std::string currentLine;

    while (std::getline(file, currentLine)) {
        EVENT* newEvent = new EVENT;

        size_t commaPos = currentLine.find(',');

        newEvent->title = currentLine.substr(0, commaPos);
        updateLinePos(currentLine, commaPos);

        newEvent->date = currentLine.substr(0, commaPos);
        updateLinePos(currentLine, commaPos);

        newEvent->theme = currentLine.substr(0, commaPos);
        updateLinePos(currentLine, commaPos);

        newEvent->location = currentLine.substr(0, commaPos);
        updateLinePos(currentLine, commaPos);

        newEvent->participants = currentLine.substr(0, commaPos);
        updateLinePos(currentLine, commaPos);

        newEvent->eventContributor = currentLine.substr(0, commaPos);
        updateLinePos(currentLine, commaPos);

        newEvent->winForBulgaria = (currentLine == "1");

        append(head, *newEvent);
    }

    file.close();
}

void addFirstEvent(EVENT** head, std::string username) {
    int selectedOption = 0;
    bool selecting = true;

    std::string options[] = {
        "Add the first Event",
        "Back"
    };

    while (selecting) {
        clearScreen();

        paddingUp(16);

        centerText("No events have been added yet.");

        paddingUp(2);

        printBoxesB(options, 2, selectedOption, 24, 6);

        char keyboardInput = _getch();

        if (keyboardInput == 75) selectedOption = (selectedOption == 0) ? 1 : selectedOption - 1;
        if (keyboardInput == 77) selectedOption = (selectedOption == 1) ? 0 : selectedOption + 1;
        if (keyboardInput == 13) {
            if (selectedOption == 0) {
                selecting = false;
                addEvent(head, username);
            }
            else return;
        }
    }
}

void confirmEventPosition(EVENT** head, const EVENT& newEvent) {
    std::string eventPositions[] = { "At the Front", "According to Date", "At the Back" };

    int selectedOption = 0;
    bool selecting = true;

    while (selecting) {
        clearScreen();

        paddingUp(16);

        centerText("Event Positioning:");

        paddingUp(2);

        printBoxesB(eventPositions, 3, selectedOption, 24, 6);
        char keyboardInput = _getch();

        if (keyboardInput == 75) selectedOption = (selectedOption == 0) ? 2 : selectedOption - 1;
        if (keyboardInput == 77) selectedOption = (selectedOption == 2) ? 0 : selectedOption + 1;
        if (keyboardInput == 13) {
            if (selectedOption != 1) (selectedOption == 0) ? append(head, newEvent) : prepend(head, newEvent);
            else insertAt(head, getPosDate(*head, newEvent), newEvent);
            updateEventsFile(*head);
            return;
        }
    }
}

void addEvent(EVENT** head, std::string username) {
    EVENT* newEvent = new EVENT();

    std::string EVENT::* writingFields[] = {
        &EVENT::title,
        &EVENT::date,
        &EVENT::theme,
        &EVENT::location,
        &EVENT::participants,
    };

    bool typing = true;
    bool bulgariaHasWon = false;

    int selectedOption = 0;

    while (typing) {
        clearScreen();

        paddingUp(6);
        if (findEventByTitle(newEvent->title)) centerText("Event title must not have any duplicates!");
        if (selectedOption < 5) centerText("Press Enter when you have filled in the Event details");
        paddingUp((selectedOption < 5) ? 5 : 6);

        centerText("Enter title of Event");
        printTextContainer(newEvent->title, selectedOption == 0, false, (newEvent->title.length() > 16 ? newEvent->title.length() : 16));

        paddingUp(2);

        centerText("Enter date of Event");
        centerText("Format: DD-MM-YYYY");
        printTextContainer(newEvent->date, selectedOption == 1, false, 16);

        paddingUp(2);

        centerText("Enter theme of Event");
        printTextContainer(newEvent->theme, selectedOption == 2, false, (newEvent->theme.length() > 16 ? newEvent->theme.length() : 16));

        paddingUp(2);

        centerText("Enter location of Event");
        printTextContainer(newEvent->location, selectedOption == 3, false, (newEvent->location.length() > 16 ? newEvent->location.length() : 16));

        paddingUp(2);

        centerText("Enter leader of Event");
        printTextContainer(newEvent->participants, selectedOption == 4, false, (newEvent->participants.length() > 16 ? newEvent->participants.length() : 16));

        paddingUp(2);

        centerText("Did the event lead to a victory for Bulgaria?");
        paddingUp(1);
        printVictoryIndicator(bulgariaHasWon, selectedOption == 5);

        paddingUp(2);

        printBoxA("         Exit         ", selectedOption == 6, 24);

        char keyboardInput = _getch();

        bool shiftPressed = (GetAsyncKeyState(160) & 0x8000);

        if (!shiftPressed) {
            if (keyboardInput == 72) {
                selectedOption = (selectedOption == 0) ? 6 : selectedOption - 1;
                keyboardInput = 224;
            }
            else if (keyboardInput == 80) {
                selectedOption = (selectedOption == 6) ? 0 : selectedOption + 1;
                keyboardInput = 224;
            }
            else if (keyboardInput == 13) {
                if (selectedOption == 6) return;
                else if (selectedOption == 5) bulgariaHasWon = !bulgariaHasWon;
                else if (areAttributesFilled(newEvent) && isDateValid(newEvent->date) && !findEventByTitle(newEvent->title)) {
                    typing = false;
                    newEvent->eventContributor = username;
                    newEvent->winForBulgaria = bulgariaHasWon;
                    confirmChanges(head, newEvent, 1);
                }
            }
        }

        if (keyboardInput == 0 || keyboardInput == 224) {
            keyboardInput = _getch();
        }
        else {
            if (selectedOption < 5) {
                std::string* targetStr = &(newEvent->*writingFields[selectedOption]);
                int maxLength = (selectedOption != 1) ? 32 : 10;
                bool isValidInput = validEventRange(keyboardInput);

                if (isValidInput && targetStr->length() < maxLength) *targetStr += keyboardInput;
                else if (keyboardInput == 8 && !targetStr->empty()) targetStr->pop_back();
            }
        }
    }
}

void confirmChanges(EVENT** head, EVENT* newEvent, int prevOption) {
    std::string yesOrNo[] = { "Yes", "No" };

    int selectedOption = 0;
    bool selecting = true;

    while (selecting) {
        clearScreen();

        paddingUp(16);

        if (prevOption == 3) centerText("Are you sure you want to delete " + newEvent->title + '?');
        else centerText("Confirm Changes?");

        paddingUp(2);

        printBoxesB(yesOrNo, 2, selectedOption, 24, 6);
        char keyboardInput = _getch();

        if (keyboardInput == 75) selectedOption = (selectedOption == 0) ? 1 : selectedOption - 1;
        if (keyboardInput == 77) selectedOption = (selectedOption == 1) ? 0 : selectedOption + 1;
        if (keyboardInput == 13) {
            selecting = false;
            if (selectedOption == 0) {
                if (prevOption == 3) {
                    updateContributions(newEvent->eventContributor, false);
                    removeElement(head, newEvent);
                }
                if (prevOption == 1) {
                    updateContributions(newEvent->eventContributor, true);
                    confirmEventPosition(head, *newEvent);
                }
                else updateEventsFile(*head);
            }
            else return;
        }
    }
}

void editEvent(EVENT** head, EVENT* editedEvent) {
    std::string EVENT::* writingFields[] = {
        &EVENT::title,
        &EVENT::date,
        &EVENT::theme,
        &EVENT::location,
        &EVENT::participants,
    };

    bool typing = true;
    bool bulgariaHasWon = editedEvent->winForBulgaria;

    int selectedOption = 0;

    while (typing) {
        clearScreen();

        paddingUp(6);
        if (selectedOption < 5) centerText("Press Enter when you have filled in the Event details");
        paddingUp((selectedOption < 5) ? 5 : 6);

        centerText("Title of Event");
        printTextContainer(editedEvent->title, selectedOption == 0, false, (editedEvent->title.length() > 16 ? editedEvent->title.length() : 16));

        paddingUp(2);

        centerText("Date of Event");
        centerText("Format: DD-MM-YYYY");
        printTextContainer(editedEvent->date, selectedOption == 1, false, 16);

        paddingUp(2);

        centerText("Theme of Event");
        printTextContainer(editedEvent->theme, selectedOption == 2, false, (editedEvent->theme.length() > 16 ? editedEvent->theme.length() : 16));

        paddingUp(2);

        centerText("Location of Event");
        printTextContainer(editedEvent->location, selectedOption == 3, false, (editedEvent->location.length() > 16 ? editedEvent->location.length() : 16));

        paddingUp(2);

        centerText("Leader of Event");
        printTextContainer(editedEvent->participants, selectedOption == 4, false, (editedEvent->participants.length() > 16 ? editedEvent->participants.length() : 16));

        paddingUp(2);

        centerText("Did the event lead to a victory for Bulgaria?");
        paddingUp(1);
        printVictoryIndicator(bulgariaHasWon, selectedOption == 5);

        paddingUp(2);

        printBoxA("         Exit         ", selectedOption == 6, 24);

        char keyboardInput = _getch();

        bool shiftPressed = (GetAsyncKeyState(160) & 0x8000);

        if (!shiftPressed) {
            if (keyboardInput == 72) {
                selectedOption = (selectedOption == 0) ? 6 : selectedOption - 1;
                keyboardInput = 224;
            }
            else if (keyboardInput == 80) {
                selectedOption = (selectedOption == 6) ? 0 : selectedOption + 1;
                keyboardInput = 224;
            }
            else if (keyboardInput == 13) {
                if (selectedOption == 6) return;
                else if (selectedOption == 5) bulgariaHasWon = !bulgariaHasWon;
                else if (areAttributesFilled(editedEvent) && isDateValid(editedEvent->date)) {
                    typing = false;
                    confirmChanges(head, editedEvent, 2);
                }
            }
        }

        if (keyboardInput == 0 || keyboardInput == 224) {
            keyboardInput = _getch();
        }
        else {
            if (selectedOption < 5) {
                std::string* targetStr = &(editedEvent->*writingFields[selectedOption]);
                int maxLength = (selectedOption != 1) ? 32 : 10;
                bool isValidInput = validEventRange(keyboardInput);
                
                if (isValidInput && targetStr->length() < maxLength) *targetStr += keyboardInput;
                else if (keyboardInput == 8 && !targetStr->empty()) targetStr->pop_back();
            }
        }
    }
}