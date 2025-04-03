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

    EVENT* temp = *head;
    for (int i = 0; temp->next && i < index - 1; i++) {
        temp = temp->next;
    }

    EVENT* newNode = new EVENT(newEvent);
    newNode->next = temp->next;
    temp->next = newNode;
}

void removeBack(EVENT** head) {
    if (!*head) return;
    if (!(*head)->next) {
        delete* head;
        *head = nullptr;
        return;
    }

    EVENT* temp = *head;
    while (temp->next->next) temp = temp->next;

    delete temp->next;
    temp->next = nullptr;
}

void removeFront(EVENT** head) {
    if (!*head) return;
    EVENT* temp = *head;
    *head = (*head)->next;
    delete temp;
}

void removeAt(EVENT** head, int index) {
    if (!*head) return;
    if (index == 0) {
        removeFront(head);
        return;
    }

    EVENT* temp = *head;
    for (int i = 0; temp->next && i < index - 1; i++) {
        temp = temp->next;
    }

    if (!temp->next) return;  // If index is out of bounds

    EVENT* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void printList(EVENT* head) {
    if (!head) return;

    //Work in progress;

    printList(head->next);
}

void clearList(EVENT** head) {
    while (*head) {
        EVENT* temp = *head;
        *head = (*head)->next;
        delete temp;
    }
    *head = nullptr;
}