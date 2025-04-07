#pragma once

#include "pch.h"
#include "visualFunctions.h"

void printBoxA(std::string option, bool isSelected, int fullWidth);

void printBoxesB(std::string options[], int numOptions, int selectedBox, int width, int spacing);

void printTextContainer(std::string text, bool isSelected, bool isHidden, int maxLength);

void printEyePassword(bool isSelected, bool isTurnedOn);

void printVictoryIndicator(bool victory, bool isSelected);