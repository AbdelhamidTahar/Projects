#pragma once
#include<string>
using namespace std;

enum eMainMenuChoice { Add = 1, Sarch = 2 };
void ExecuteMainMenuChoice(const eMainMenuChoice& MainMenuChoice);
void MainMenuProgram();