#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Client.h"
#include "TranchesData.h"
using namespace std;

struct sElectricityOrGasBil
{
	double OldIndex = 0;
	double NewIndex = 0;
	double Factor = 0;
	sTranchesData TranchesData;
	double Consumption = 0;
	double ConsumptionAmount = 0;
};

