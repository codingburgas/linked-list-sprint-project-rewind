#pragma once
#include "pch.h"
#include "visualFunctions.h"

bool validPasswordRange(char input);

bool validUsernameRange(char input);

bool findUsername(std::string username);

bool* checkPassword(const std::string& password);

bool* checkUsername(const std::string& username);

bool fullValidation(std::string& password, std::string& username);

void printCriteria(std::string input, int inputId);