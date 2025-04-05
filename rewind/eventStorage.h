#pragma once
#include <vector>
#include "eventManager.h"

void saveEventsToFile(const std::vector<Event>& events, const std::string& fileName);

bool loadEventsFromFile(std::vector<Event>& events, const std::string& fileName);