#include "../header/visualFunctions.h"

//A function that clears the screen. Works across platforms
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

//A function that simulates the keybord combination used to fullscreen
void fullScreen() { 
    keybd_event(VK_MENU, 0x36, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
    std::cout << "Program running in Fullscreen.\n";
    system("pause");
}

int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleInfo);
    
    return consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
}

void centerText(std::string text) {
    int consoleWidth = getConsoleWidth();
    int paddingLeft = (consoleWidth - text.length()) / 2;
    if (paddingLeft < 0) paddingLeft = 0;

    std::cout << std::string(paddingLeft, ' ') << text;
}