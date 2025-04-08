#include "reportsMenu.h"

//displayes reports
void showReports(EVENT* reportedEvents, std::string username) {
    bool selecting = true;

    int selectedEvent = 0;

    int startIndex = 0;

    while (selecting) {
        clearScreen();

        paddingUp(16);

        printEvents(reportedEvents, 0, selectedEvent + startIndex, startIndex, 10, false, username);

        char input = _getch();

        if (input == 13) return;

        if (input == 72) {
            if (selectedEvent == 0) {
                if (startIndex >= 10) {
                    startIndex -= 10;
                    selectedEvent = 9;
                }
            }
            else {
                selectedEvent--;
            }
        }
        else if (input == 80) {
            if (selectedEvent == 9 || (startIndex + selectedEvent + 1 >= getEventCount(reportedEvents))) {
                if (startIndex + 10 < getEventCount(reportedEvents)) {
                    startIndex += 10;
                    selectedEvent = 0;
                }
            }
            else {
                selectedEvent++;
            }
        }
    }
    clearList(&reportedEvents);
}

//Either enter keyword from keyboard or sort reports based on criteria 
void browseReportsByX(int prevOption, EVENT* allEvents, std::string username) {
    clearScreen();

    clearScreen();

    bool selecting = true;

    int selectedOption = 0;

    std::string keyword = "";

    EVENT* reportedEvents = new EVENT;
    reportedEvents = nullptr;

    while (selecting) {
        clearScreen();

        if (prevOption == 0) {

            paddingUp(16);

            centerText("Enter a valid keyword");

            paddingUp(2);

            printTextContainer(keyword, selectedOption == 0, false, (keyword.length() > 16 ? keyword.length() : 16));

            paddingUp(2);

            printBoxA("         Back         ", selectedOption == 1, 24);

            char keyboardInput = _getch();

            bool shiftPressed = (GetAsyncKeyState(160) & 0x8000);

            if (!shiftPressed) {
                if (keyboardInput == 72) {
                    selectedOption = (selectedOption == 0) ? 1 : selectedOption - 1;
                    keyboardInput = 224;
                }
                else if (keyboardInput == 80) {
                    selectedOption = (selectedOption == 1) ? 0 : selectedOption + 1;
                    keyboardInput = 224;
                }
                else if (keyboardInput == 13) {
                    if (selectedOption == 1) return;
                    else {
                        setReportsByKeyword(allEvents, &reportedEvents, keyword);
                        showReports(reportedEvents, username);
                    }
                }
            }

            if (keyboardInput == 0 || keyboardInput == 224) {
                keyboardInput = _getch();
            }
            else {
                if (selectedOption == 0) {
                    std::string* targetStr = &keyword;
                    bool isValidInput = validEventRange(keyboardInput);

                    if (isValidInput && targetStr->length() < 32) *targetStr += keyboardInput;
                    else if (keyboardInput == 8 && !targetStr->empty()) targetStr->pop_back();
                }
            }
        }
        else {
            std::string EVENT::* comparisonFields[] = {
                &EVENT::title,
                &EVENT::date,
                &EVENT::theme,
                &EVENT::location,
                &EVENT::participants,
                &EVENT::eventContributor,
            };

            std::string optionsLine1[] = { "Title", "Date", "Theme" };
            std::string optionsLine2[] = { "Location", "Leader", "Contributor" };

            paddingUp(16);

            centerText("Show Reports by:");

            paddingUp(2);

            printBoxesB(optionsLine1, 3, selectedOption, 32, 4);
            printBoxesB(optionsLine2, 3, selectedOption - 3, 32, 4);
            printBoxA("            Result            ", selectedOption == 6, 32);

            printBoxA("         Exit         ", selectedOption == 7, 24);

            char keyboardInput = _getch();

            bool shiftPressed = (GetAsyncKeyState(160) & 0x8000);

            if (keyboardInput == 72) {
                if (selectedOption < 3) selectedOption = 7;
                else if (selectedOption < 6) selectedOption -= 3;
                else selectedOption = selectedOption - ((selectedOption == 6) ? 2 : 1);
            }
            if (keyboardInput == 80) {
                if (selectedOption > 5) selectedOption = ((selectedOption == 6) ? 7 : 0);
                else selectedOption = selectedOption + ((selectedOption > 2) ? 6 - selectedOption : 3);
            }
            if (keyboardInput == 75) {
                if (selectedOption > 5) selectedOption = 3;
                else selectedOption = selectedOption - ((selectedOption == 0 || selectedOption == 3) ? -2 : 1);
            }
            if (keyboardInput == 77) {
                if (selectedOption > 5) selectedOption = 5;
                else selectedOption = selectedOption - ((selectedOption == 5 || selectedOption == 2) ? 2 : -1);
            }

            if (keyboardInput == 13) {
                if (selectedOption != 7) {
                    if (selectedOption < 6) setReportsByComparison(allEvents, &reportedEvents, comparisonFields[selectedOption]);
                    else if (selectedOption == 6) setReportsByResult(allEvents, &reportedEvents);
                    showReports(reportedEvents, username);
                }
                else return;
            }
        }
    }
}

//Redirects the user to sorting by entered keyword and sorting by members of EVENT struct
void showReportsMenu(std::string username) {
    EVENT* allEvents = new EVENT;
    allEvents = nullptr;
    initializeEvents(&allEvents);

    bool selecting = true;

    int selectedOption = 0;

    std::string menuOptions[] = {
        "         Reports by Keywords        ",
        "           Reports by Data          ",
        "                Back                "

    };

    while (selecting) {
        if (!allEvents) addFirstEvent(&allEvents, username);

        clearScreen();

        printLogo("reportslogo.txt");

        for (int i = 0; i < 3; i++) printBoxA(menuOptions[i], i == selectedOption, 38);

        char input = _getch();

        if (input == 72) selectedOption = (selectedOption == 0) ? 2 : selectedOption - 1;
        else if (input == 80) selectedOption = (selectedOption == 2) ? 0 : selectedOption + 1;
        else if (input == 13) {
            if (selectedOption != 2) browseReportsByX(selectedOption, allEvents, username);
            else return;
        }
    }

    clearList(&allEvents);
}