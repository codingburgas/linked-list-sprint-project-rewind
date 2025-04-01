#pragma once
#include "pch.h"

void createNewUser(const std::string userPassword, const std::string userName);

bool findExistingUser(const std::string userPassword, const std::string userName);