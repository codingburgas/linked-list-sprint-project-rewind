#pragma once
#include "./pch.h"

struct Event {
    std::string date;
    std::string title;
    std::string theme;
    std::string location;
    std::string participants;
    std::string result;
};

void addEvent();
void editEvent();
void deleteEvent();
void printEventDetails();
void printAllEvents();
