#pragma once

#include "pch.h"
#include "visualFunctions.h"

struct EVENT {
    std::string title;
    std::string date;
    std::string theme;
    std::string location;
    std::string participants;
    bool winForBulgaria;

    EVENT* next;
};

void append(EVENT** head, const EVENT& newEvent);

void prepend(EVENT** head, const EVENT& newEvent);

void insertAt(EVENT** head, int index, const EVENT& newEvent);

void removeBack(EVENT** head);

void removeFront(EVENT** head);

void printList(EVENT* head);

void clearList(EVENT** head);
