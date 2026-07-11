#pragma once
#include <iostream>
#include <string>
#include "GlobalElectricityAndGas.h"
using namespace std;

namespace ElectricityOrGasBillDataOperations
{
	string ConvertElectricityOrGasDataStructToStringLine
	(
		const sElectricityOrGasBil& ElectricityOrGasBil,
		const string& StartMarker = "",
		const string& EndMarker = "",
		const string& Separator = "//#//"
	);
}