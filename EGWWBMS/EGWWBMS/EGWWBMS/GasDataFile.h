#pragma once
#include "GlobalElectricityAndGasDataFile.h"


namespace GasBillDataOperations
{
	string ConvertGasBillDataStructToStringLine
	(
		const sElectricityOrGasBil& GasBil,
		const string& StartMarker = "SatrtGasBill",
		const string& EndMarker = "EndGasBill",
		const string& Separator = "//#//"
	);

	sElectricityOrGasBil ConvertGasBillStringLineToDataStruct
	(
		string GasBil,
		const string& StartMarker = "SatrtGasBill",
		const string& EndMarker = "EndGasBill",
		const string& Separator = "//#//"
	);
}