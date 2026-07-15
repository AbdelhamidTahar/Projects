#include <iostream>
#include <string>
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


sElectricityAndGasBill ElectricityAndGasBillDataOperations::ConvertElectricityAndGasBillStringLineToDataStruct
(
	const sElectricityAndGasBill& ElectricityAndGasBill,
	const string& Separator 
)
{

	return ElectricityAndGasBill;
}
