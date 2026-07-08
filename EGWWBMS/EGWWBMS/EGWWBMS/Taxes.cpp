#include "Taxes.h"
#include "Input.h"

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