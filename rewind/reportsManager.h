#pragma once
#include <string>
#include <vector>
#include "./eventManager.h"

void ShowEventsByDate(const std::vector<Event>& events);
void ShowEventsByTitle(const std::vector<Event>& events);
void ShowEventsByTheme(const std::vector<Event>& events);
void ShowEventsByLocation(const std::vector<Event>& events);
void ShowEventsByParticipants(const std::vector<Event>& events);
void ShowEventsByResult(const std::vector<Event>& events);
void SearchEvent(const std::vector<Event>& events);
