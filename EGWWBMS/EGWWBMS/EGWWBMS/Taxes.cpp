#include "Taxes.h"
#include "Input.h"
#include "Math.h"

sTaxes TaxesOperations::ReadTaxesInfo()
{
	sTaxes Taxes;
	Taxes.FixedCharges = Reads::ReadPositiveDecimalNumber
	    ("Enter the fixed charges amount (subscription) in DZD: ");

	Taxes.ServiceAndFees = Reads::ReadPositiveDecimalNumber
	    ("Enter the service and fees amount in DZD: ");

	Taxes.FirstVATPercentage = Reads::ReadPositiveDecimalNumber
	    ("Enter the first VAT percentage (%): ");

	Taxes.SecondVATPercentage = Reads::ReadPositiveDecimalNumber
	    ("Enter the Second VAT percentage (%): ");

	Taxes.FixedConsumptionDuty = Reads::ReadPositiveDecimalNumber
	    ("Enter the fixed consumption duty amount in DZD: ");

	Taxes.HousingTax = Reads::ReadPositiveDecimalNumber
	    ("Enter the housing tax amount in DZD: ");

	Taxes.Contribution = Reads::ReadPositiveDecimalNumber
	    ("Enter the contribution amount in DZD: ");

	Taxes.REPETaxAmount = Reads::ReadPositiveDecimalNumber
	    ("Enter the REPE tax amount in DZD: ");

	Taxes.RGPETaxAmount = Reads::ReadPositiveDecimalNumber
	    ("Enter the RGPE tax amount in DZD: ");
 
	return Taxes;
}

double TaxesOperations::CalculateFirstVATAmount
      (const double& PrimaryTranchesTotalAmountElectricityAndGas, const sTaxes& Taxes)
{
	double VATAmount = CalculateVTA(PrimaryTranchesTotalAmountElectricityAndGas, Taxes.FirstVATPercentage) +
		Taxes.FixedCharges + Taxes.ServiceAndFees;
	return VATAmount;
}

double TaxesOperations::CalculateVTA(const double& Amount, const double& Percentage)
{
	double PercentageTAsDecimal = ConvertsMath::ConvertPercentageToDecimal(Percentage);

	return (Amount * PercentageTAsDecimal);
}

double TaxesOperations::CalculateTotalTaxes(const sTaxes& Taxes)
{
	return Taxes.FixedCharges + Taxes.ServiceAndFees + 
		   Taxes.TotalVATAmount + Taxes.FixedConsumptionDuty + 
		   Taxes.HousingTax + Taxes.Contribution +
		   Taxes.REPETaxAmount + Taxes.RGPETaxAmount;
}

sTaxes TaxesOperations::CalculateTaxes
      (const sTranchesData& TranchesDataElectricity, const sTranchesData& TranchesDataGas, sTaxes Taxes)
{
	double PrimaryTranchesTotalAmountElectricityAndGas = 
		TranchesDataElectricity.PrimaryTranchesTotalAmount +
		TranchesDataGas.PrimaryTranchesTotalAmount;

	Taxes.FirstVATAmount = TaxesOperations::CalculateFirstVATAmount
	    (PrimaryTranchesTotalAmountElectricityAndGas, Taxes);


	double SecondaryTranchesTotalAmountElectricityAndGas =
		TranchesDataElectricity.SecondaryTranchesTotalAmount +
		TranchesDataGas.SecondaryTranchesTotalAmount;

	Taxes.SecondVATAmount = TaxesOperations:: CalculateVTA
	    (SecondaryTranchesTotalAmountElectricityAndGas, Taxes.SecondVATPercentage);

	Taxes.TotalVATAmount = Taxes.FirstVATAmount + Taxes.SecondVATAmount;

	Taxes.TotalTaxesAmount = TaxesOperations::CalculateTotalTaxes(Taxes);

	
	return Taxes;
}


