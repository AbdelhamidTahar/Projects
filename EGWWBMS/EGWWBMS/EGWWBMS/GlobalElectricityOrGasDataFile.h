#pragma once
#include <iostream>
#include <string>
#include "GlobalElectricityOrGas.h"
#include "GlobalElectricityOrGasDataFile.h"
using namespace std;


enum eOldIndexes { OldElectricityIndex = 1, OldGasIndex = 2 };

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

	double GetOldElectricityOrGasIndex
	(const string& ClientID, const string& FileName, eOldIndexes OldElectricityOrGasIndex);

}