#pragma once
#include <iostream>
using namespace std;

enum eAddMenuChoice { ElectricityAndGasBill = 1, Client = 2 };
void ExecuteAddMenuChoice(const eAddMenuChoice& AddMenuChoice);
void AddMenuProgram(const string Message ="");