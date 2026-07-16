#pragma once
#include <iostream>
#include <string>
#include "ElectricityAndGasBill.h"
using namespace std;

namespace ElectricityAndGasBillDataOperations
{
	string ConvertElectricityAndGasBillDataStructToStringLine
	(
		const sElectricityAndGasBill& ElectricityAndGasBill,
		const string& Separator = "//#//"
	);

	sElectricityAndGasBill ConvertVectorElectricityAndGasBillDataStringToElectricityAndGasBill
	(const vector<string>& ElectricityAndGasBillData, sElectricityAndGasBill ElectricityAndGasBill);


	sElectricityAndGasBill ConvertElectricityAndGasBillStringLineToDataStruct
	(
		string ElectricityAndGasBillLine,
		const string& Separator = "//#//"
	);
}