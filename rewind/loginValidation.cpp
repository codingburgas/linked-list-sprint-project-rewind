#include "loginValidation.h"

bool validPasswordRange(char input) {
    return (input >= 33 && input <= 126);
}

bool validUsernameRange(char input) {
    return (input >= 48 && input <= 57) ||
        (input >= 65 && input <= 90) ||
        (input >= 97 && input <= 122) ||
        input == 46 ||
        input == 95;
}

bool findUsername(std::string username) {
    std::ifstream file;
    file.open("users.csv", std::ios_base::in);

    std::string currentLine;

    while (std::getline(file, currentLine)) {
        size_t commaPos = currentLine.find(',');
        if (commaPos == std::string::npos) {
            continue;
        }
        if (currentLine.substr(0, commaPos) == username) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

bool* checkPassword(const std::string& password) {
    bool* checks = new bool[5] {false, false, false, false, false};

    std::string specialChars = "!@#$%^&*()-_=+[]{}|;:'\",.<>?/";

    if (password.length() >= 8) checks[0] = true;

    for (char letter : password) {
        if (std::isupper(letter)) checks[1] = true;
        else if (std::islower(letter)) checks[2] = true;
        else if (std::isdigit(letter)) checks[3] = true;
        else if (specialChars.find(letter) != std::string::npos) checks[4] = true;
    }

    return checks;
}

bool* checkUsername(const std::string& username) {
    bool* checks = new bool[2] {false, false};

    if (username.length() >= 8) checks[0] = true;
    if (!findUsername(username)) checks[1] = true;

    return checks;
}

bool fullValidation(std::string& password, std::string& username) {
    bool* passChecks = checkPassword(password);
    bool* nameChecks = checkUsername(username);

    bool result = (passChecks[0] && passChecks[1] && passChecks[2] && passChecks[3] && passChecks[4] && nameChecks[0] && nameChecks[1]);

    delete[] passChecks;
    delete[] nameChecks;

    return result;
}

void printCriteria(std::string input, int inputId) {
    paddingUp(10);

    bool* checks = nullptr;

    if (inputId == 0) {
        checks = checkUsername(input);

        if (!checks[0]) std::cout << std::string((getConsoleWidth() - 38) / 2, ' ') << "Username must be at least 8 characters" << "\n";
        if (!checks[1]) centerText("Username already in use");

        if (checks[0] && checks[1]) centerText("Your username looks good!");

        paddingUp(14);
    }
    else if (inputId < 3) {
        checks = checkPassword(input);

        if (!checks[0]) std::cout << std::string((getConsoleWidth() - 42) / 2, ' ') << "Password must be at least 8 characters" << "\n\n";
        if (!checks[1]) std::cout << std::string((getConsoleWidth() - 42) / 2, ' ') << "Password must contain at least one uppercase letter" << "\n\n";
        if (!checks[2]) std::cout << std::string((getConsoleWidth() - 42) / 2, ' ') << "Password must contain at least one Lowercase letter" << "\n\n";
        if (!checks[3]) std::cout << std::string((getConsoleWidth() - 42) / 2, ' ') << "Password must contain at least one number" << "\n\n";
        if (!checks[4]) std::cout << std::string((getConsoleWidth() - 42) / 2, ' ') << "Password must contain at least one special character (!, @, #...)" << "\n\n";

        if (checks[0] && checks[1] && checks[2] && checks[3] && checks[4]) centerText("Your password looks good!");

        paddingUp(((checks[0] + checks[1] + checks[2] + checks[3] + checks[4]) * 2 + 5) - ((checks[0] && checks[1] && checks[2] && checks[3] && checks[4]) ? 1 : 0));
    }

    delete[] checks;
}