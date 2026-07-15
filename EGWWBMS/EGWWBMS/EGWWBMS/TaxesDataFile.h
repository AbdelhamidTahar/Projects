#pragma once
#include <iostream>
#include "Taxes.h"
using namespace std;

namespace TaxesDataOperations
{
	string ConvertTaxesDataStructToStringLine
	(
		const sTaxes& Taxes,
		const string& StartMarker = "StartTaxes",
		const string& EndMarker = "EndTaxes",
		const string& Separator = "//#//"
	);

	sTaxes ConvertVectorsToTaxesDataStruct
	(const vector<string>& vTaxes);

	sTaxes ConvertTaxesStringLineToDataStruct
	(
		string TaxesStringLine,
		const string& StartMarker = "StartTaxes",
		const string& EndMarker = "EndTaxes",
		const string& Separator = "//#//"
	);
}

