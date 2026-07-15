#pragma once
#include "GlobalElectricityAndGasDataFile.h"


namespace ElectricityBillDataOperations
{
	string ConvertElectricityBillDataStructToStringLine
	(
		const sElectricityOrGasBil& ElectricityBill,
		const string& StartMarker = "SatrtElectricityBill",
		const string& EndMarker = "EndElectricityBill",
		const string& Separator = "//#//"
	);

	sElectricityOrGasBil ConvertElectricityBillStringLineToDataStruct
	(
		string ElectricityBill,
		const string& StartMarker = "SatrtElectricityBill",
		const string& EndMarker = "EndElectricityBill",
		const string& Separator = "//#//"
	);
}