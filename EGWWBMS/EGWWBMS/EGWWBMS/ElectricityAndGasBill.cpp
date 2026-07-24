#include <iostream>
#include "ElectricityAndGasBill.h"
using namespace std;

double CalculateAmountWithoutTaxes
(const sTranchesData& ElectricityTranchesData, const sTranchesData& GasTranchesData, const sTaxes& Taxes)

{
	double AmountWithoutTaxes = 0;

	AmountWithoutTaxes = ElectricityTranchesData.PrimaryTranchesTotalAmount +
		ElectricityTranchesData.SecondaryTranchesTotalAmount;

	AmountWithoutTaxes = GasTranchesData.PrimaryTranchesTotalAmount +
		GasTranchesData.SecondaryTranchesTotalAmount;

	AmountWithoutTaxes += Taxes.FixedCharges;

	AmountWithoutTaxes += Taxes.ServiceAndFees;


	return AmountWithoutTaxes;
}

double CalculateAmountAmountWithTaxes
(const sElectricityOrGasBil& ElectricityBill, const sElectricityOrGasBil& GasBill, const sTaxes& Taxes)
{
	return ElectricityBill.ConsumptionAmount +
		GasBill.ConsumptionAmount +
		Taxes.TotalTaxesAmount;
}