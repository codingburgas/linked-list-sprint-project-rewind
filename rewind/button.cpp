#include "button.h"

void printBoxA(std::string option, bool isSelected, int fullWidth) {
    if (isSelected) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

    std::cout << std::string((getConsoleWidth() - fullWidth) / 2, ' ') << char(201);
    std::cout << std::string(fullWidth - 2, char(205));
    std::cout << char(187) << std::endl;

    std::cout << std::string((getConsoleWidth() - fullWidth) / 2, ' ') << char(186)
        << std::string(fullWidth - 2, ' ') << char(186) << std::endl;

    std::cout << std::string((getConsoleWidth() - fullWidth) / 2, ' ') << char(186)
        << option << char(186) << std::endl;

    std::cout << std::string((getConsoleWidth() - fullWidth) / 2, ' ') << char(186)
        << std::string(fullWidth - 2, ' ') << char(186) << std::endl;

    std::cout << std::string((getConsoleWidth() - fullWidth) / 2, ' ') << char(200);
    std::cout << std::string(fullWidth - 2, char(205));
    std::cout << char(188) << "\n\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void printTextContainer(std::string text, bool isSelected, bool isHidden, int maxLength) {
    if (isHidden) text = std::string(text.length(), '*');

    if (isSelected) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

    std::cout << std::string((getConsoleWidth() - maxLength - 4) / 2, ' ') << char(201) << std::string(maxLength + 2, char(205)) << char(187) << std::endl;
    std::cout << std::string((getConsoleWidth() - maxLength - 4) / 2, ' ') << char(186) << ' ' << text << std::string(maxLength + 1 - text.length(), ' ') << char(186) << std::endl;
    std::cout << std::string((getConsoleWidth() - maxLength - 4) / 2, ' ') << char(200) << std::string(maxLength + 2, char(205)) << char(188) << std::endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void printBoxesB(std::string options[], int numOptions, int selectedBox, int width, int spacing) {
    for (int row = 0; row < 5; row++) {
        std::cout << std::string((getConsoleWidth() - (width + spacing) * numOptions + spacing) / 2, ' ');
        for (int i = 0; i < numOptions; i++) {
            if (i == selectedBox)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

            std::cout << char((row == 0) * 201 + (row == 4) * 200 + (row > 0 && row < 4) * 186);

            if (row == 2) {
                std::cout << std::string((width - options[i].size()) / 2, ' ')
                    << options[i]
                    << std::string(width - 2 - (width - options[i].size()) / 2 - options[i].size(), ' ');
            }
            else {
                std::cout << std::string(width - 2, (row == 0 || row == 4) ? char(205) : ' ');
            }

            std::cout << char((row == 0) * 187 + (row == 4) * 188 + (row > 0 && row < 4) * 186);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

            if (i != numOptions - 1)
                std::cout << std::string(spacing, ' ');
        }
        std::cout << std::endl;
    }
}

void printEyePassword(bool isSelected, bool isTurnedOn) {
    if (isSelected) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

    if (isTurnedOn) {
        centerText(std::string({ char(95), char(95), char(95) }));
        centerText(std::string({ char(196), char(205), char(196), char(205), char(196), char(205), char(196) }));
        centerText(std::string({ char(238), char(238), char(238) }));
    }
    else {
        centerText(std::string({ char(201), char(205), char(205), char(205), char(187) }));
        centerText(std::string({ char(196), char(205), char(205), ' ', char(254), ' ', char(205), char(205), char(196) }));
        centerText(std::string({ char(200), char(205), char(205), char(205), char(188) }));
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void printVictoryIndicator(bool victory, bool isSelected) {
    if (isSelected) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

    centerText(std::string({ char(201), char(205), char(205), char(205), char(187) }));
    centerText(std::string({ char(186), ' ', (victory ? 'X' : ' '), ' ', char(186) }));
    centerText(std::string({ char(200), char(205), char(205), char(205), char(188) }));

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}