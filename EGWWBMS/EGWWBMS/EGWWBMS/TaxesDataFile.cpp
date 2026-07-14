#include <iostream>
#include <string>
#include "TaxesDataFile.h"
using namespace std;


string TaxesDataOperations::ConvertTaxesDataStructToStringLine
(
	const sTaxes& Taxes,
	const string& StartMarker,
	const string& EndMarker ,
	const string& Separator 
)
{
	string TaxesLine = "";
	TaxesLine += StartMarker;

	TaxesLine += to_string(Taxes.FixedCharges) + Separator;
	TaxesLine += to_string(Taxes.ServiceAndFees) + Separator;
	TaxesLine += to_string(Taxes.FirstVATPercentage) + Separator;
	TaxesLine += to_string(Taxes.FirstVATAmount) + Separator;;
	TaxesLine += to_string(Taxes.SecondVATPercentage) + Separator;
	TaxesLine += to_string(Taxes.SecondVATAmount) + Separator;
	TaxesLine += to_string(Taxes.TotalVATAmount) + Separator;
	TaxesLine += to_string(Taxes.FixedConsumptionDuty) + Separator;
	TaxesLine += to_string(Taxes.HousingTax) + Separator;
	TaxesLine += to_string(Taxes.Contribution) + Separator;
	TaxesLine += to_string(Taxes.REPETaxAmount) + Separator;
	TaxesLine += to_string(Taxes.RGPETaxAmount) + Separator;
	TaxesLine += to_string(Taxes.TotalTaxesAmount);

	TaxesLine += EndMarker;

	return TaxesLine;
}
