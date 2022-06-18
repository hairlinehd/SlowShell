// libraries n shit
#include "bundle.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <chrono>
#include <Urlmon.h>
#include <cmath>
#include <sys/types.h>
#include <dirent.h>
namespace fs = std::filesystem;
using namespace std;
void getCurrentDirItems() {
    Sleep(2009);
    DIR* dr;
    struct dirent* en;
    dr = opendir(".");
    if (dr) {
        while ((en = readdir(dr)) != NULL) {
            cout << " \n" << en->d_name;
        }
        closedir(dr);
    }
}
void TerminalDefaultPage() {
    TerminalHelpStr();
    Terminal();
}
void getOSVersion() {
    OSVERSIONINFOEX info;
    ZeroMemory(&info, sizeof(OSVERSIONINFOEX));
    info.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    GetVersionEx((LPOSVERSIONINFO)&info);//info requires typecasting

    printf("Microsoft Windows %u.%u\n", info.dwMajorVersion, info.dwMinorVersion);
}
void getTime() {
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "Today is " << std::ctime(&end_time);
}
void TerminalStartPage() {
    getOSVersion();
    getTime();
    cout << "\n";
}
void Terminal() {
    cout << "$ ";
    string TerminalUsrChoice;
    cin >> TerminalUsrChoice;
    if (TerminalUsrChoice == "help") {
        cout << "help - shows this dialogue\n";
        cout << "exit - exits terminal\n";
        cout << "clear - clear terminal\n";
        cout << "startpage - why man\n";
        cout << "overload() - causes a giant memory leak because its funny\n";
        cout << "\n";
        Terminal();
    }
    else if (TerminalUsrChoice == "exit") {
        return;
    }
    else if (TerminalUsrChoice == "clear") {
        system("cls");
        TerminalHelpStr();
        Terminal();
    }
    else if (TerminalUsrChoice == "startpage") {
        system("cls");
        TerminalStartPage();
        TerminalHelpStr();
        Terminal();
    }
    else if (TerminalUsrChoice == "overload()") {
        string overloadsecurityforidiot;
        cout << "Are you sure about this????????????????????????????????????\n";
        cout << "hint = yes for yes no for no idiot\n";
        cin >> overloadsecurityforidiot;
        if (overloadsecurityforidiot == "yes") {
            for (int i = 0; i < 1000; i++) {
                double* ptr = (double*)malloc(999999999 * sizeof(double));
            }
        }
        else {
            cout << "Returning\n";
            _sleep(2000);
            TerminalHelpStr();
            Terminal();
        }
    }
    else if (TerminalUsrChoice == "crash()") {
        system("powershell wininit");
    }
    else if (TerminalUsrChoice == "textedit") {
        system("C:\\Windows\\system32\\notepad.exe");
        system("cls"); 
        TerminalHelpStr();
        Terminal();
        
    }
    else if (TerminalUsrChoice == "ls") {
        getCurrentDirItems();
        cout << "\n\n";
        TerminalDefaultPage();

    }
    else {
        cout << "'" + TerminalUsrChoice + "'" " is not a recognized as a command, stupid idiot!!!!!!!!!!!!!\n";
        TerminalHelpStr();
        Terminal();
    }
   
}
void TerminalHelpStr() {
    cout << "For available commands use 'help' on the terminal\n";
}

