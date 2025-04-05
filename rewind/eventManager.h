#pragma once
#include <string>
#include <vector>

struct Event {
    std::string date;
    std::string title;
    std::string theme;
    std::string location;
    std::string participants;
    std::string result;
};

void AddEvent();
void EditEvent();
void DeleteEvent();
void PrintEventDetails(const Event& event);
void PrintAllEvents(const std::vector<Event>& events);

void loadEvents();
void initializeEventSystem();