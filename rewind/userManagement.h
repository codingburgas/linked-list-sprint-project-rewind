#pragma once
#include "pch.h"

void createNewUser(const std::string userPassword, const std::string username);

int findContributions(const std::string username);

bool findExistingUser(const std::string userPassword, const std::string username);

void updateContributions(const std::string username, bool isIncreased);