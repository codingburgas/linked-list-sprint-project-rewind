#pragma once
#include "eventManager.h"

void saveEventsToFile(Event* head, const std::string& fileName);

bool loadEventsFromFile(Event*& head, const std::string& fileName);