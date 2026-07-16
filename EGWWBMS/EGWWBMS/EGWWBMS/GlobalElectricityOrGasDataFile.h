#pragma once
#include <iostream>
#include <string>
#include "GlobalElectricityOrGas.h"
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

	sElectricityOrGasBil ConvertVectorsAndTranchesDataToElectricityOrGasBillStruct
	 (const vector<string>& vDataStringElectricityOrGasBil, const sTranchesData& TranchesData);

	sElectricityOrGasBil ConvertElectricityOrGasStringLineToDataStruct
	(
		string ElectricityOrGasStringLine,
		const string& StartMarker = "",
		const string& EndMarker = "",
		const string& Separator = "//#//"
	);
}