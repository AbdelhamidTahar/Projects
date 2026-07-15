#pragma once
#include <iostream>
#include <string>
#include "Input.h"
#include "GlobalDataFile.h"
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
	ElectricityOrGasLine += StartMarker;
	ElectricityOrGasLine += to_string(ElectricityOrGasBil.OldIndex) + Separator;
	ElectricityOrGasLine += to_string(ElectricityOrGasBil.NewIndex) + Separator;
	ElectricityOrGasLine += to_string(ElectricityOrGasBil.Factor) + Separator;
	ElectricityOrGasLine += TranchesDataOperations::convertTranchesDataStructToStringLine
	 (
		ElectricityOrGasBil.TranchesData
	 );

	ElectricityOrGasLine += to_string(ElectricityOrGasBil.Consumption) + Separator;
	ElectricityOrGasLine += to_string(ElectricityOrGasBil.ConsumptionAmount) ;
	ElectricityOrGasLine += EndMarker;

	return ElectricityOrGasLine;
}

sElectricityOrGasBil ElectricityOrGasBillDataOperations::ConvertVectorsAndTranchesDataToElectricityOrGasBillStruct
(const vector<string>& vDataStringElectricityOrGasBil,const sTranchesData &TranchesData)
{
	sElectricityOrGasBil ElectricityOrGasBil;

	ElectricityOrGasBil.OldIndex = stod(vDataStringElectricityOrGasBil[0]);
	ElectricityOrGasBil.NewIndex = stod(vDataStringElectricityOrGasBil[1]);
	ElectricityOrGasBil.Factor = stod(vDataStringElectricityOrGasBil[2]);
	ElectricityOrGasBil.TranchesData = TranchesData;
	ElectricityOrGasBil.Consumption = stod(vDataStringElectricityOrGasBil[3]);
	ElectricityOrGasBil.ConsumptionAmount = stod(vDataStringElectricityOrGasBil[4]);

	return ElectricityOrGasBil;
}

sElectricityOrGasBil ElectricityOrGasBillDataOperations::ConvertElectricityOrGasStringLineToDataStruct
(
	string ElectricityOrGasStringLine,
	const string& StartMarker ,
	const string& EndMarker ,
	const string& Separator
)
{


	ElectricityOrGasStringLine = GlobalOperations::DeleteStartMarkerTAndEndMarker
	 (ElectricityOrGasStringLine, StartMarker, EndMarker);

	string DataTranchesLine = "";
	DataTranchesLine = GlobalOperations::GetTextFromStartMarkerToEndMarker
	 (ElectricityOrGasStringLine, "StartTranchesData", "EndTranchesData");


	sTranchesData TranchesData;
	TranchesData = TranchesDataOperations::ConvertTranchesDataStringLineToDataStruct(DataTranchesLine);


	ElectricityOrGasStringLine = GlobalOperations::DeleteTextFromStartMarkerToEndMarker
	 (ElectricityOrGasStringLine, "StartTranchesData", "EndTranchesData");


	vector<string> vElectricityOrGasStringLine;
	vElectricityOrGasStringLine = InputOperations::SplitStringWithSeparator
	 (ElectricityOrGasStringLine);


	sElectricityOrGasBil ElectricityOrGasBil;
	ElectricityOrGasBil = ConvertVectorsAndTranchesDataToElectricityOrGasBillStruct
	(vElectricityOrGasStringLine, TranchesData);



	return ElectricityOrGasBil;
}