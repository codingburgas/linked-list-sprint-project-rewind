#include "./pch.h"
#include "./visualFunctions.h"
#include "./logInScreen.h"
#include "./mainMenu.h"
#include "./eventManager.h"
#include "./eventStorage.h"

int main() {
    initializeEventSystem();
    fullScreen();
    logInScreen();
}