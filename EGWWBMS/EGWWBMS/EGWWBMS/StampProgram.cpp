#include "StampProgram.h"
#include "Input.h"
#include "Math.h"

sElectricityAndGasBill StampProgram(sElectricityAndGasBill ElectricityAndGasBill)
{

	ElectricityAndGasBill.StampPercentage = Reads::ReadPositiveDecimalNumber
	("\nPlease enter the stamp percentage: ");

	double PercentageAsDecimal = 
		ConvertsMath::ConvertPercentageToDecimal(ElectricityAndGasBill.StampPercentage);

	ElectricityAndGasBill.StampAmount =
		OperationsMath::Multiply(ElectricityAndGasBill.AmountWithTaxes, PercentageAsDecimal);

	return ElectricityAndGasBill;
}