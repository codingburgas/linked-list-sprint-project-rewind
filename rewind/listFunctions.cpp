#include "listFunctions.h"

void append(EVENT** head, const EVENT& newEvent) {
    EVENT* newNode = new EVENT(newEvent);
    newNode->next = nullptr;

    if (!*head) {
        *head = newNode;
        return;
    }

    EVENT* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void copyContent(EVENT* sourceList, EVENT** copyList) {
    if (!sourceList) return;

    append(copyList, *sourceList);

    copyContent(sourceList->next, copyList);
}

void copyByResult(EVENT* allEvents, EVENT** reportedEvents, bool copyVictories) {
    if (!allEvents) return;

    if (copyVictories == allEvents->winForBulgaria) append(reportedEvents, *allEvents);

    copyByResult(allEvents->next, reportedEvents, copyVictories);
}

void prepend(EVENT** head, const EVENT& newEvent) {
    EVENT* newNode = new EVENT(newEvent);
    newNode->next = *head;
    *head = newNode;
}

void insertAt(EVENT** head, int index, const EVENT& newEvent) {
    if (index == 0 || !*head) {
        prepend(head, newEvent);
        return;
    }
    else if (index == getEventCount(*head)) {
        append(head, newEvent);
    }

    EVENT* temp = *head;
    for (int i = 0; temp->next && i < index - 1; i++) {
        temp = temp->next;
    }

    EVENT* newNode = new EVENT(newEvent);
    newNode->next = temp->next;
    temp->next = newNode;
}

EVENT* getElementByIndex(EVENT* head, int index) {
    int currentIndex = 0;
    EVENT* current = head;

    while (current != nullptr) {
        if (currentIndex == index) {
            return current;
        }
        current = current->next;
        currentIndex++;
    }

    return nullptr;
}

void removeElement(EVENT** head, EVENT* deletedEvent) {
    if (*head == nullptr || deletedEvent == nullptr) return;

    if ((*head)->title == deletedEvent->title) {
        *head = (*head)->next;
        return;
    }

    removeElement(&(*head)->next, deletedEvent);
}

int getEventCount(EVENT* head) {
    if (!head) return 0;

    return 1 + getEventCount(head->next);
}

void clearList(EVENT** head) {
    while (*head) {
        EVENT* temp = *head;
        *head = (*head)->next;
        delete temp;
    }
    *head = nullptr;
}

int convertDate(std::string date) {
    int day = (date[0] - '0') * 10 + (date[1] - '0');
    int month = (date[3] - '0') * 10 + (date[4] - '0');
    int year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');

    return year * 10000 + month * 100 + day;
}

EVENT* merge(EVENT* first, EVENT* second, std::string EVENT::* sortField, bool ascending) {
    if (!first) return second;
    if (!second) return first;

    bool compare;

    if (sortField == &EVENT::date) {
        compare = ascending
            ? (convertDate(first->*sortField) < convertDate(second->*sortField))
            : (convertDate(first->*sortField) > convertDate(second->*sortField));
    }
    else {
        compare = ascending
            ? (first->*sortField < second->*sortField)
            : (first->*sortField > second->*sortField);
    }

    if (compare) {
        first->next = merge(first->next, second, sortField, ascending);
        return first;
    }
    else {
        second->next = merge(first, second->next, sortField, ascending);
        return second;
    }
}

void split(EVENT* source, EVENT** front, EVENT** back) {
    EVENT* slow = source;
    EVENT* fast = source->next;

    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

void sortEvents(EVENT** headRef, std::string EVENT::* sortField, bool ascending) {
    if (!*headRef || !(*headRef)->next) return;

    EVENT* front;
    EVENT* back;

    split(*headRef, &front, &back);

    sortEvents(&front, sortField, ascending);
    sortEvents(&back, sortField, ascending);

    *headRef = merge(front, back, sortField, ascending);
}