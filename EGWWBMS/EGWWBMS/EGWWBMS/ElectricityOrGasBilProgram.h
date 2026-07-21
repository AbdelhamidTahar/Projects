#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Input.h"
#include"GlobalElectricityOrGasDataFile.h"
#include "GlobalElectricityOrGas.h"
#include "ElectricityAndGasBill.h"
using namespace std;


sElectricityOrGasBil ElectricityOrGasBillProgram
(const sElectricityAndGasBill& ElectricityAndGasBill, eOldIndexes eTypeOfBill);

double CalculateConsumptionElectricityOrGas(const sElectricityOrGasBil& ElectricityOrGasBil);