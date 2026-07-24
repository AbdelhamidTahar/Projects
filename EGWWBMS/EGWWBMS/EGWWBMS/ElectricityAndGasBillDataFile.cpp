#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Input.h"
#include "GlobalDataFile.h"
#include "ElectricityAndGasBillDataFile.h"
#include "ClientDataFile.h"
#include "ElectricityDataFile.h"
#include "GasDataFile.h"
#include "TaxesDataFile.h"
using namespace std;



string ElectricityAndGasBillDataOperations::ConvertElectricityAndGasBillDataStructToStringLine
(
	const sElectricityAndGasBill& ElectricityAndGasBill,
	const string& Separator 
)
{
	string ElectricityAndGasBillAsString = "";

	ElectricityAndGasBillAsString += ClientDataOperations::ConvertClientDataStructToStringLine
	(ElectricityAndGasBill.Client);

	ElectricityAndGasBillAsString += ElectricityAndGasBill.ID + Separator;

	ElectricityAndGasBillAsString +=
		ElectricityBillDataOperations::ConvertElectricityBillDataStructToStringLine
		(ElectricityAndGasBill.ElectricityBill);
		
	ElectricityAndGasBillAsString +=
		GasBillDataOperations::ConvertGasBillDataStructToStringLine
		(ElectricityAndGasBill.GasBill);
	
	ElectricityAndGasBillAsString +=
		TaxesDataOperations::ConvertTaxesDataStructToStringLine(ElectricityAndGasBill.Taxes);


	ElectricityAndGasBillAsString += to_string(ElectricityAndGasBill.AmountWithoutTaxes);
	ElectricityAndGasBillAsString += Separator;
	ElectricityAndGasBillAsString += to_string(ElectricityAndGasBill.AmountWithTaxes);
	ElectricityAndGasBillAsString += Separator;
	ElectricityAndGasBillAsString += to_string(ElectricityAndGasBill.StampPercentage);
	ElectricityAndGasBillAsString += Separator;
	ElectricityAndGasBillAsString += to_string(ElectricityAndGasBill.StampAmount);
	ElectricityAndGasBillAsString += Separator;
	ElectricityAndGasBillAsString += to_string(ElectricityAndGasBill.TotalAmountDueCash);


	return ElectricityAndGasBillAsString;
}


sElectricityAndGasBill ElectricityAndGasBillDataOperations::ConvertVectorElectricityAndGasBillDataStringToElectricityAndGasBill
(const vector<string>& ElectricityAndGasBillData, sElectricityAndGasBill ElectricityAndGasBill)
{
	

	ElectricityAndGasBill.ID = ElectricityAndGasBillData[0];
	ElectricityAndGasBill.AmountWithoutTaxes = stod(ElectricityAndGasBillData[1]);
	ElectricityAndGasBill.AmountWithTaxes = stod(ElectricityAndGasBillData[2]);
	ElectricityAndGasBill.StampPercentage = stod(ElectricityAndGasBillData[3]);
	ElectricityAndGasBill.StampAmount = stod(ElectricityAndGasBillData[4]);
	ElectricityAndGasBill.TotalAmountDueCash = stod(ElectricityAndGasBillData[5]);

	return ElectricityAndGasBill;
}



sElectricityAndGasBill ElectricityAndGasBillDataOperations::ConvertElectricityAndGasBillStringLineToDataStruct
(
    string ElectricityAndGasBillLine,
	const string& Separator 
)
{
	sElectricityAndGasBill ElectricityAndGasBill;
	string TextData = "";


	TextData = GlobalOperations::GetTextFromStartMarkerToEndMarker
	(ElectricityAndGasBillLine, "StartClient", "EndClient");
	ElectricityAndGasBill.Client = ClientDataOperations::ConvertClientStringLineToDataStruct(TextData);
	ElectricityAndGasBillLine = GlobalOperations::DeleteTextFromStartMarkerToEndMarker
	(ElectricityAndGasBillLine, "StartClient", "EndClient");




	TextData = GlobalOperations::GetTextFromStartMarkerToEndMarker
	(ElectricityAndGasBillLine, "SatrtElectricityBill", "EndElectricityBill");
	ElectricityAndGasBill.ElectricityBill = ElectricityBillDataOperations::ConvertElectricityBillStringLineToDataStruct
	(TextData);
	ElectricityAndGasBillLine = GlobalOperations::DeleteTextFromStartMarkerToEndMarker
	(ElectricityAndGasBillLine, "SatrtElectricityBill", "EndElectricityBill");



	TextData = GlobalOperations::GetTextFromStartMarkerToEndMarker
	(ElectricityAndGasBillLine, "SatrtGasBill", "EndGasBill");
	ElectricityAndGasBill.GasBill = GasBillDataOperations::ConvertGasBillStringLineToDataStruct
	(TextData);
	ElectricityAndGasBillLine = GlobalOperations::DeleteTextFromStartMarkerToEndMarker
	(ElectricityAndGasBillLine, "SatrtGasBill", "EndGasBill");


	
	TextData = GlobalOperations::GetTextFromStartMarkerToEndMarker
	(ElectricityAndGasBillLine, "StartTaxes", "EndTaxes");
	ElectricityAndGasBill.Taxes = TaxesDataOperations::ConvertTaxesStringLineToDataStruct
	(TextData);
	ElectricityAndGasBillLine = GlobalOperations::DeleteTextFromStartMarkerToEndMarker
	(ElectricityAndGasBillLine, "StartTaxes", "EndTaxes");


	vector<string>ElectricityAndGasBillData;
	ElectricityAndGasBillData = InputOperations::SplitStringWithSeparator(ElectricityAndGasBillLine);
	ElectricityAndGasBill = ConvertVectorElectricityAndGasBillDataStringToElectricityAndGasBill
	(ElectricityAndGasBillData, ElectricityAndGasBill);

	

	return ElectricityAndGasBill;
}


vector<sElectricityAndGasBill> ElectricityAndGasBillDataOperations::LoadAllElectricityAndGasBills
(const string &FileName)
{
	vector<sElectricityAndGasBill>vElectricityAndGasBills;
	fstream ElectricityAndGasBillsFile;

	ElectricityAndGasBillsFile.open(FileName, ios::in);

	if (ElectricityAndGasBillsFile.is_open())
	{
		string Line = "";
		sElectricityAndGasBill ElectricityAndGasBill;

		while (getline(ElectricityAndGasBillsFile, Line))
		{
			ElectricityAndGasBill = ConvertElectricityAndGasBillStringLineToDataStruct(Line);
			vElectricityAndGasBills.push_back(ElectricityAndGasBill);
		}

		ElectricityAndGasBillsFile.close();
	}

	return vElectricityAndGasBills;
}

string ElectricityAndGasBillDataOperations::GenerateBillID()
{
	string BillID = "";
	vector<sElectricityAndGasBill> vElectricityAndGasBills =
		ElectricityAndGasBillDataOperations::LoadAllElectricityAndGasBills();

	sElectricityAndGasBill LastElectricityAndGasBills =
		vElectricityAndGasBills[vElectricityAndGasBills.size() - 1];


	BillID = to_string(stod(LastElectricityAndGasBills.ID) + 1);

	return BillID;
}