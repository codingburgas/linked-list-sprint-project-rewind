#pragma once

#include "pch.h"
#include "visualFunctions.h"

struct EVENT {
    std::string title;
    std::string date;
    std::string theme;
    std::string location;
    std::string participants;
    std::string eventContributor;
    bool winForBulgaria;

    EVENT* next;
};

void append(EVENT** head, const EVENT& newEvent);

void prepend(EVENT** head, const EVENT& newEvent);

void copyContent(EVENT* sourceList, EVENT** copyList);

void copyByResult(EVENT* allEvents, EVENT** reportedEvents, bool copyVictories);

void insertAt(EVENT** head, int index, const EVENT& newEvent);

EVENT* getElementByIndex(EVENT* head, int index);

void removeElement(EVENT** head, EVENT* deletedEvent);

int getEventCount(EVENT* head);

void clearList(EVENT** head);

int convertDate(std::string date);

EVENT* merge(EVENT* first, EVENT* second, std::string EVENT::* sortMember, bool ascendingOrder);

void split(EVENT* source, EVENT** front, EVENT** back);

void sortEvents(EVENT** headRef, std::string EVENT::* sortField, bool ascending = true);