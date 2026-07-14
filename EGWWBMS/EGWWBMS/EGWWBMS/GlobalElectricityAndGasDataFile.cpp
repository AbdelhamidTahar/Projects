#pragma once
#include <iostream>
#include "TranchesDataFile.h"
#include "GlobalElectricityAndGasDataFile.h"
using namespace std;

string ElectricityOrGasBillDataOperations::ConvertElectricityOrGasDataStructToStringLine
(
	const sElectricityOrGasBil& ElectricityOrGasBil,
	const string& StartMarker ,
	const string& EndMarker ,
	const string& Separator 
)
{
	string ElectricityOrGasLine = "";
	ElectricityOrGasLine += to_string(ElectricityOrGasBil.OldIndex) + Separator;
	ElectricityOrGasLine += to_string(ElectricityOrGasBil.NewIndex) + Separator;
	ElectricityOrGasLine += ElectricityOrGasBil.Factor;
	ElectricityOrGasLine += TranchesDataOperations::convertTranchesDataStructToStringLine
	 (
		ElectricityOrGasBil.TranchesData
	 );

	ElectricityOrGasLine += to_string(ElectricityOrGasBil.Consumption) + Separator;
	ElectricityOrGasLine += to_string(ElectricityOrGasBil.ConsumptionAmount) + Separator;
	ElectricityOrGasLine += EndMarker;

	return ElectricityOrGasLine;
}

