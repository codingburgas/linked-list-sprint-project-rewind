#include "reportsManager.h"

//Gives the user the choice of sorting order
bool chooseOrder() {
    std::string orderOptions[] = { "Ascending", "Descending" };

    int selectedOption = 0;

    bool selecting = true;

    while (selecting) {
        clearScreen();

        paddingUp(16);

        centerText("Choose sorting order:");

        paddingUp(2);

        printBoxesB(orderOptions, 2, selectedOption, 24, 6);

        char keyboardInput = _getch();

        if (keyboardInput == 75) selectedOption = (selectedOption == 0) ? 1 : selectedOption - 1;
        if (keyboardInput == 77) selectedOption = (selectedOption == 1) ? 0 : selectedOption + 1;
        if (keyboardInput == 13) return !selectedOption;
    }

    return true;
}

//Function for sorting Reported Events based on keyword input by user
void setReportsByKeyword(EVENT* allEvents, EVENT** reportedEvents, std::string keyword) {
    if (allEvents == nullptr) return;

    if (allEvents->title == keyword ||
        allEvents->theme == keyword ||
        allEvents->location == keyword ||
        allEvents->participants == keyword ||
        allEvents->eventContributor == keyword) {
        append(reportedEvents, *allEvents);
    }

    setReportsByKeyword(allEvents->next, reportedEvents, keyword);
}

//Function for sorting Reported Events based on losses or victories for Bulgaria
void setReportsByResult(EVENT* allEvents, EVENT** reportedEvents) {
    bool isAscending = chooseOrder();

    clearList(reportedEvents);

    //The function is called twice: once for victories, once for losses
    copyByResult(allEvents, reportedEvents, !isAscending);
    copyByResult(allEvents, reportedEvents, isAscending);
}

//Main function for sorting Reported Events based on what member is to be compared
void setReportsByComparison(EVENT* allEvents, EVENT** reportedEvents, std::string EVENT::* comparedMember) {
    bool isAscending = chooseOrder();

    if (getEventCount(*reportedEvents) < getEventCount(allEvents)) copyContent(allEvents, reportedEvents);

    sortEvents(reportedEvents, comparedMember, isAscending);
}