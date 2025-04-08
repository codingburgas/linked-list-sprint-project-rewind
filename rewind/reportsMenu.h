#pragma once
#include "pch.h"
#include "visualFunctions.h"
#include "eventMenu.h"
#include "reportsManager.h"
#include "listFunctions.h"
#include "eventManager.h"

void showReports(EVENT* reportedEvents, std::string username);
void showReportsMenu(std::string username);
void browseReportsByX(int prevOption, EVENT* allEvents, std::string username);