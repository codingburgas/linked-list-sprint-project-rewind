#pragma once

#include "pch.h"
#include "visualFunctions.h"
#include "eventManager.h"
#include "mainMenu.h"
#include "button.h"

void printEvents(EVENT* head, int currentEvent, int selectedEvent, int startIndex, int displayedEvents, bool eventIsChosen, std::string username);

void showEventsMenu(std::string username);