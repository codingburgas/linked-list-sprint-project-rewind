#include "userManagement.h"

void createNewUser(const std::string userPassword, const std::string username) {
    std::ifstream checkFile("users.csv");
    if (!checkFile) {
        std::ofstream createFile("users.csv");
        createFile.close();
    }

    std::ofstream file("users.csv", std::ios::app);
    file << username << "," << userPassword << ",0\n";
}

bool findExistingUser(const std::string userPassword, const std::string username) {
    std::ifstream file;
    file.open("users.csv", std::ios_base::in);

    std::string currentLine;

    while (std::getline(file, currentLine)) {
        size_t commaPos = currentLine.find(',', currentLine.find(',') + 1);
        if (commaPos == std::string::npos) {
            continue;
        }
        if (currentLine.substr(0, commaPos) == username + "," + userPassword) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

int findContributions(const std::string username) {
    std::ifstream file("users.csv");
    std::string currentLine;

    while (std::getline(file, currentLine)) {
        
        if (currentLine.find(username + ",") == 0) {
            int lastComma = currentLine.rfind(',');
            if (lastComma != -1) {
                std::string countStr = currentLine.substr(lastComma + 1);

                int count = 0;
                for (int i = 0; i < countStr.length(); ++i) {
                    if (countStr[i] >= '0' && countStr[i] <= '9') {
                        count = count * 10 + (countStr[i] - '0');
                    }
                    else {
                        break;
                    }
                }

                file.close();
                return count;
            }
        }
    }

    file.close();
    return -1;
}

void updateContributions(const std::string username, bool isIncreased) {
    std::ifstream file("users.csv");
    std::string currentLine;
    std::string updatedContent;

    while (std::getline(file, currentLine)) {

        if (currentLine.rfind(username + ",", 0) == 0) {
            size_t lastComma = currentLine.rfind(',');
            if (lastComma != std::string::npos) {
                std::string contributionStr = currentLine.substr(lastComma + 1);
                int contributions = std::stoi(contributionStr);
                contributions += isIncreased ? 1 : -1;
                if (contributions < 0) contributions = 0;

                currentLine = currentLine.substr(0, lastComma + 1) + std::to_string(contributions);
            }
        }

        updatedContent += currentLine + "\n";
    }

    file.close();

    std::ofstream outFile("users.csv");
    outFile << updatedContent;
    outFile.close();
}