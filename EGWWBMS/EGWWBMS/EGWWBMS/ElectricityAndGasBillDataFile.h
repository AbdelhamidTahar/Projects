#pragma once
#include <iostream>
#include <vector>
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

	vector<sElectricityAndGasBill> LoadAllElectricityAndGasBills
	(const string &FileName = "ElectricityAndGasBills");

	string GenerateBillID();

	bool SaveElectricityAndGasBillsInFile
	(
	const sElectricityAndGasBill& ElectricityAndGasBill, const string& FileName = "ElectricityAndGasBills"
	);

	bool FindElectricityAndGasBillWithID
	(
		const string& BillID,
		const vector<sElectricityAndGasBill>& vElectricityAndGasBill,
		sElectricityAndGasBill& ElectricityAndGasBill
	);

	bool GetForElectricityAndGasBillWithID
	(
		const string& BillID,
		sElectricityAndGasBill& ElectricityAndGasBill
	);
	vector<sElectricityAndGasBill>FindElectricityAndGasBillWithClientID
	(
		const vector<sElectricityAndGasBill>& vElectricityAndGasBill,
		const string& ClientID
	);
}