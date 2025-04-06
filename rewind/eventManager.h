#pragma once
#include <string>

struct Event {
    std::string date;
    std::string title;
    std::string theme;
    std::string location;
    std::string participants;
    std::string result;
    Event* next;
};

void AddEvent();
void EditEvent();
void DeleteEvent();
void PrintEventDetails(const Event& event);
void PrintAllEvents();
void loadEvents();
void initializeEventSystem();
Event* createEventNode(const Event& newEvent);