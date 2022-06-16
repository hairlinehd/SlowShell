#include "bundle.h"
#include <iostream>
#include <Windows.h>


// if ur confused where all the code is go to bundle.cpp (i regret doing that)
int main() { 
	SetConsoleTitle(TEXT("SlowShell Terminal 0.3"));
	TerminalStartPage();
	TerminalHelpStr();
	Terminal();
}