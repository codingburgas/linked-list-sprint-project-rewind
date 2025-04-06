#include "userManagement.h"

void createNewUser(const std::string userPassword, const std::string userName) {
    std::ifstream checkFile("users.csv");
    if (!checkFile) {
        std::ofstream createFile("users.csv");
        createFile.close();
    }

    std::ofstream file("users.csv", std::ios::app);
    file << userName << "," << userPassword << ",0\n";
}

bool findExistingUser(const std::string userPassword, const std::string userName) {
    std::ifstream file;
    file.open("users.csv", std::ios_base::in);

    std::string currentLine;

    while (std::getline(file, currentLine)) {
        size_t commaPos = currentLine.find(',', currentLine.find(',') + 1);
        if (commaPos == std::string::npos) {
            continue;
        }
        if (currentLine.substr(0, commaPos) == userName + "," + userPassword) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}
