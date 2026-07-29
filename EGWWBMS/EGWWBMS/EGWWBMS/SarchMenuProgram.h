#pragma once
#include <string>

using namespace std;

enum eSarchMenuChoice
{
	eElectricityAndGasBillWithID = 1,
	eElectricityAndGasBillWithClientID = 2,
	eShowAllElectricityAndGasBills = 3,
	eSerchForClientWithID = 4,
	eSerchForClientWithFullName = 5,
	eSowAllClients = 6,

};

void ExecuteSarchMenuChoice(const eSarchMenuChoice& SarchMenuChoice);

void SarchMenuProgram(const string Message = "");