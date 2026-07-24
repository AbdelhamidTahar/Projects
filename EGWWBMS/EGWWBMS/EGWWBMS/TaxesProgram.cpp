#include <iostream>
#include "TaxesProgram.h"

using namespace std;

sTaxes TaxesProgram(const sTranchesData& TranchesDataElectricity, const sTranchesData& TranchesDataGas)
{
	sTaxes Taxes; 

	Taxes = TaxesOperations::ReadTaxesInfo();
	Taxes = TaxesOperations::CalculateTaxes(TranchesDataElectricity, TranchesDataGas, Taxes);


	return Taxes;
}