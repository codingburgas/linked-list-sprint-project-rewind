#pragma once
#include "pch.h"
#include "eventManager.h"
#include "listFunctions.h"
#include "visualFunctions.h"

bool chooseOrder();

void setReportsByKeyword(EVENT* allEvents, EVENT** reportedEvents, std::string keyword);

void setReportsByResult(EVENT* allEvents, EVENT** reportedEvents);

void setReportsByComparison(EVENT* allEvents, EVENT** reportedEvents, std::string EVENT::* comparedMember);