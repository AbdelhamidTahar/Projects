#pragma once
struct sTaxes
{
	double FixedCharges         = 0;
	double ServiceAndFees       = 0;
	double FirstVATPercentage   = 0;
	double FirstVATAmount       = 0;
	double SecondVATPercentage  = 0;
	double SecondVATAmount      = 0;
	double TotalVAT             = 0;
	double FixedConsumptionDuty = 0;
	double HousingTax           = 0;
	double Contribution         = 0;
	double REPETaxAmount        = 0;
	double RGPETaxAmount        = 0;
	double TotalTaxes           = 0;
};

namespace TaxesOperations
{
	sTaxes ReadTaxesInfo();
	sTaxes CalculateTaxes(sTaxes Taxes);
}


