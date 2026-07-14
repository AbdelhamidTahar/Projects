#include <iostream>
#include <string>
#include "ClientDataFile.h"
#include "GlobalElectricityAndGasDataFile.h"
#include "TaxesDataFile.h"
#include "ElectricityAndGasBillDataFile.h"
using namespace std;


string ElectricityAndGasBillDataOperations::ConvertElectricityAndGasBillDataStructToStringLine
(
	const sElectricityAndGasBill& ElectricityAndGasBill,
	const string& Separator 
)
{
	string ElectricityAndGasBillLine = "";

	ElectricityAndGasBillLine += 
	  ClientDataOperations::ConvertClientDataStructToStringLine
	   (
	     ElectricityAndGasBill.Client
	   );

	ElectricityAndGasBillLine += ElectricityAndGasBill.ID;

	ElectricityAndGasBillLine += 
	  ElectricityOrGasBillDataOperations::ConvertElectricityOrGasDataStructToStringLine
	  (
	 	ElectricityAndGasBill.ElectricityBill, "StartElectricityBill", "EndElectricityBill"
	  );

	ElectricityAndGasBillLine +=
		ElectricityOrGasBillDataOperations::ConvertElectricityOrGasDataStructToStringLine
		(
			ElectricityAndGasBill.GasBill, "StartGasBill", "EndGasBill"
		);

	ElectricityAndGasBillLine += TaxesDataOperations::ConvertTaxesDataStructToStringLine
	    (
			ElectricityAndGasBill.Taxes
		);

	ElectricityAndGasBillLine += to_string(ElectricityAndGasBill.AmountWithoutTaxes) + Separator;
	ElectricityAndGasBillLine += to_string(ElectricityAndGasBill.AmountWithTaxes) + Separator;
	ElectricityAndGasBillLine += to_string(ElectricityAndGasBill.StampPercentage) + Separator;
	ElectricityAndGasBillLine += to_string(ElectricityAndGasBill.StampAmount) + Separator;
	ElectricityAndGasBillLine += to_string(ElectricityAndGasBill.TotalAmountDueCash);

	return ElectricityAndGasBillLine;
}
