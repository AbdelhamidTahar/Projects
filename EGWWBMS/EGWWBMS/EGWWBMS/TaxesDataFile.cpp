#include <iostream>
#include <string>
#include <vector>
#include "GlobalDataFile.h"
#include "Input.h"
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

	TaxesLine += to_string(Taxes.FixedCharges        ) + Separator;
	TaxesLine += to_string(Taxes.ServiceAndFees      ) + Separator;
	TaxesLine += to_string(Taxes.FirstVATPercentage  ) + Separator;
	TaxesLine += to_string(Taxes.FirstVATAmount      ) + Separator;;
	TaxesLine += to_string(Taxes.SecondVATPercentage ) + Separator;
	TaxesLine += to_string(Taxes.SecondVATAmount     ) + Separator;
	TaxesLine += to_string(Taxes.TotalVATAmount      ) + Separator;
	TaxesLine += to_string(Taxes.FixedConsumptionDuty) + Separator;
	TaxesLine += to_string(Taxes.HousingTax          ) + Separator;
	TaxesLine += to_string(Taxes.Contribution        ) + Separator;
	TaxesLine += to_string(Taxes.REPETaxAmount       ) + Separator;
	TaxesLine += to_string(Taxes.RGPETaxAmount       ) + Separator;
	TaxesLine += to_string(Taxes.TotalTaxesAmount    );

	TaxesLine += EndMarker;

	return TaxesLine;
}


sTaxes TaxesDataOperations::ConvertVectorsToTaxesDataStruct
(const vector<string>& vTaxes)
{
	sTaxes Taxes;

	Taxes.FixedCharges         = stod(vTaxes[0]);
	Taxes.ServiceAndFees       = stod(vTaxes[1]);
	Taxes.FirstVATPercentage   = stod(vTaxes[2]);
	Taxes.FirstVATAmount       = stod(vTaxes[3]);
	Taxes.SecondVATPercentage  = stod(vTaxes[4]);
	Taxes.SecondVATAmount      = stod(vTaxes[5]);
	Taxes.TotalVATAmount       = stod(vTaxes[6]);
	Taxes.FixedConsumptionDuty = stod(vTaxes[7]);
	Taxes.HousingTax           = stod(vTaxes[8]);
	Taxes.Contribution         = stod(vTaxes[9]);
	Taxes.REPETaxAmount        = stod(vTaxes[10]);
	Taxes.RGPETaxAmount        = stod(vTaxes[11]);
	Taxes.TotalTaxesAmount     = stod(vTaxes[12]);

	return Taxes;
}


sTaxes TaxesDataOperations::ConvertTaxesStringLineToDataStruct
(
	string TaxesStringLine,
	const string& StartMarker,
	const string& EndMarker ,
	const string& Separator 
)
{
	TaxesStringLine = GlobalOperations::DeleteStartMarkerTAndEndMarker
	 (TaxesStringLine, StartMarker, EndMarker);

	vector<string> vDataTaxes;
	vDataTaxes = InputOperations::SplitStringWithSeparator(TaxesStringLine, Separator);

	sTaxes Taxes;
	Taxes = ConvertVectorsToTaxesDataStruct(vDataTaxes);

	return Taxes;
}