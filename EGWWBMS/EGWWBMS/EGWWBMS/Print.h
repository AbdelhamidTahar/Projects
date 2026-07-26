#pragma once
#include <iostream>
#include <string>
#include "ElectricityAndGasBill.h"
#include "Client.h"

using namespace std;

void PrintHeadarElectricityAndGasBill();
void PrintClient(const sClient& Client);

void PrintBodyElectricityAndGasBill(const sElectricityAndGasBill& ElectricityAndGasBill);
void PrintElectricityAndGasBill(const sElectricityAndGasBill &ElectricityAndGasBill);
void PrintTranches(const vector<sTranche>& vTranche);
void PrintTranchesData(const sTranchesData& TranchesData);
void PrintFootarElectricityAndGasBill();


