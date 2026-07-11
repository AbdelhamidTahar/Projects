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
}