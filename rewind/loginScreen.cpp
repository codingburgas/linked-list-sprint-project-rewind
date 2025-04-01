#include "./logInScreen.h"
#include "./visualFunctions.h"

void printLoginInput(std::string input, bool isSelected, bool isHidden, int  inputWidth) {
    if (isHidden) input = std::string(input.length(), '*');

    if (isSelected) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

    std::cout << std::string((getConsoleWidth() - inputWidth - 4) / 2, ' ') << char(201) << std::string(inputWidth + 2, char(205)) << char(187) << std::endl;
    std::cout << std::string((getConsoleWidth() - inputWidth - 4) / 2, ' ') << char(186) << ' ' << input << std::string(inputWidth + 1 - input.length(), ' ') << char(186) << std::endl;
    std::cout << std::string((getConsoleWidth() - inputWidth - 4) / 2, ' ') << char(200) << std::string(inputWidth + 2, char(205)) << char(188) << std::endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void signUp() {

    std::string userName = "";
    std::string userPass = "";

    bool typing = true;

    int selectedOption = 0;

    bool hidePass = false;

    while (typing) {
        clearScreen();

        if (fullValidation(userPass, userName) && (selectedOption == 0 || selectedOption == 2)) {
            paddingUp(6);
            centerText("Press Enter to continue");
        }

        paddingUp(20 - ((fullValidation(userPass, userName) && (selectedOption == 0 || selectedOption == 2)) ? 7 : 0));

        centerText("Enter a valid username");
        paddingUp(2);
        printLoginInput(userName, selectedOption == 0, false, 16);

        paddingUp(3);

        centerText("Enter a valid password");
        paddingUp(1);

        printEyePassword(selectedOption == 1, hidePass);

        paddingUp(1);
        printLoginInput(userPass, selectedOption == 2, hidePass, (userPass.length() > 16) ? userPass.length() : 16);

        if (selectedOption < 3) {
            printCriteria((selectedOption == 0) ? userName : userPass, selectedOption);
        }

        if (selectedOption == 3) paddingUp(25);
        printBoxA("         Exit         ", selectedOption == 3, 24);

        char keyboardInput = _getch();

        bool shiftPressed = (GetAsyncKeyState(160) & 0x8000);

        if (!shiftPressed) {
            if (keyboardInput == 72) {
                selectedOption = (selectedOption == 0) ? 3 : selectedOption - 1;
                keyboardInput = 224;
            }
            else if (keyboardInput == 80) {
                selectedOption = (selectedOption == 3) ? 0 : selectedOption + 1;
                keyboardInput = 224;
            }
            else if (keyboardInput == 13) {
                if (selectedOption == 1) hidePass = !hidePass;
                if (selectedOption == 3) return;
                if (fullValidation(userPass, userName) && (selectedOption == 0 || selectedOption == 2)) {
                    typing = false;
                    createNewUser(userPass, userName);
                    return;
                }
            }
        }

        if (keyboardInput == 0 || keyboardInput == 224) {
            keyboardInput = _getch();
        }
        else {
            if (selectedOption == 0 || selectedOption == 2) {
                std::string* targetStr = (selectedOption == 0) ? &userName : &userPass;
                int maxLength = (selectedOption == 0) ? 16 : 32;
                bool isValidInput = (selectedOption == 0) ? validUsernameRange(keyboardInput) : validPasswordRange(keyboardInput);

                if (isValidInput && targetStr->length() < maxLength) *targetStr += keyboardInput;
                else if (keyboardInput == 8 && !targetStr->empty()) targetStr->pop_back();
            }
        }
    }
}

void logIn() {
    std::string userName = "";
    std::string userPass = "";

    bool typing = true;

    int selectedOption = 0;

    bool hidePass = false;

    while (typing) {
        clearScreen();

        if (selectedOption == 0 || selectedOption == 2) {
            paddingUp(6);
            centerText("Press Enter to Log In");
        }

        paddingUp(20 - ((selectedOption == 0 || selectedOption == 2) ? 7 : 0));

        centerText("Enter your username");
        paddingUp(2);
        printLoginInput(userName, selectedOption == 0, false, 16);

        paddingUp(3);

        centerText("Enter your password");
        paddingUp(1);

        printEyePassword(selectedOption == 1, hidePass);

        paddingUp(1);
        printLoginInput(userPass, selectedOption == 2, hidePass, (userPass.length() > 16) ? userPass.length() : 16);

        paddingUp(25);
        printBoxA("         Exit         ", selectedOption == 3, 24);

        char keyboardInput = _getch();

        bool shiftPressed = (GetAsyncKeyState(160) & 0x8000);

        if (!shiftPressed) {
            if (keyboardInput == 72) {
                selectedOption = (selectedOption == 0) ? 3 : selectedOption - 1;
                keyboardInput = 224;
            }
            else if (keyboardInput == 80) {
                selectedOption = (selectedOption == 3) ? 0 : selectedOption + 1;
                keyboardInput = 224;
            }
            else if (keyboardInput == 13) {
                if (selectedOption == 1) hidePass = !hidePass;
                if (selectedOption == 3) return;
                if (findExistingUser(userPass, userName) && (selectedOption == 0 || selectedOption == 2)) {
                    typing = false;
                    showMainMenu();
                    return;
                }
            }
        }

        if (keyboardInput == 0 || keyboardInput == 224) {
            keyboardInput = _getch();
        }
        else {
            if (selectedOption == 0 || selectedOption == 2) {
                std::string* targetStr = (selectedOption == 0) ? &userName : &userPass;
                int maxLength = (selectedOption == 0) ? 16 : 32;
                bool isValidInput = (selectedOption == 0) ? validUsernameRange(keyboardInput) : validPasswordRange(keyboardInput);

                if (isValidInput && targetStr->length() < maxLength) *targetStr += keyboardInput;
                else if (keyboardInput == 8 && !targetStr->empty()) targetStr->pop_back();
            }
        }
    }
}

void logInScreen() {
    clearScreen();

    bool selecting = true;

    int selectedOption = 0;

    std::string logInOptions[3] = {
        "        Log In        ",
        "       Sign Up        ",
        "         Exit         "
    };

    while (selecting) {
        clearScreen();

        printLogo("logo.txt");

        paddingUp(5);

        for (int i = 0; i < 3; i++) {
            printBoxA(logInOptions[i], i == selectedOption, 24);
        }

        char key = _getch();

        if (key == 72) {
            selectedOption = (selectedOption == 0) ? 2 : selectedOption - 1;
        }
        else if (key == 80) {
            selectedOption = (selectedOption == 2) ? 0 : selectedOption + 1;
        }
        else if (key == 13) {
            if (selectedOption == 0) {
                logIn();
            }
            else if (selectedOption == 1) {
                signUp();
            }
            else if (selectedOption == 2) {
                exitMessage();
                exit(0);
            }
        }
    }
}