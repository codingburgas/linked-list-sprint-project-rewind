#pragma once
#include "pch.h"
#include "button.h"
#include "visualFunctions.h"
#include "listFunctions.h"
#include "userManagement.h"

void updateEventsFile(EVENT* head);
void updateLinePos(std::string& currentLine, size_t& commaPos);
bool isDateValid(std::string& date);
int getPosDate(EVENT* head, const EVENT& newEvent);
bool validEventRange(char input);
void addFirstEvent(EVENT** head, std::string username);
bool areAttributesFilled(EVENT* newEvent);
void initializeEvents(EVENT** head);
void confirmEventPosition(EVENT** head, const EVENT& newEvent);
bool findEventByTitle(std::string eventTitle);
void addEvent(EVENT** head, std::string username);
void confirmChanges(EVENT** head, EVENT* newEvent, int prevOption);
void editEvent(EVENT** head, EVENT* editedEvent);