#pragma once
#include "pch.h"
#include "./visualFunctions.h"
#include "loginValidation.h"
#include "userManagement.h"
#include "./button.h"
#include "./mainMenu.h"

void logInScreen();

void printLoginInput(std::string input, bool isSelected, bool isHidden, int inputWidth);

void logIn();

void signUp();