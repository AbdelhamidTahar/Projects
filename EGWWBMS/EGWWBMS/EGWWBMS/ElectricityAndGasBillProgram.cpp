#include <iostream>
#include "Input.h"
#include "Ui.h"
#include "ElectricityAndGasBillDataFile.h"
#include "ElectricityProgram.h"
#include "GasProgram.h"
#include "ElectricityAndGasBillProgram.h"
#include "ClientProgram.h"
#include "TaxesProgram.h"
#include "StampProgram.h"

using namespace std;

sElectricityAndGasBill  ElectricityAndGasBillProgram()
{
	sElectricityAndGasBill ElectricityAndGasBill;


	if (!ClientProgram(ElectricityAndGasBill.Client))
		Menus::GoBackTotMainMenu("Error: Client not found.\n");

	ElectricityAndGasBill.ID = ElectricityAndGasBillDataOperations::GenerateBillID();
	ElectricityAndGasBill.ElectricityBill = ElectricityBillProgram(ElectricityAndGasBill.Client);
	ElectricityAndGasBill.GasBill = GasBillProgram(ElectricityAndGasBill.Client);
	ElectricityAndGasBill.Taxes = TaxesProgram
	(
		ElectricityAndGasBill.ElectricityBill.TranchesData,
		ElectricityAndGasBill.GasBill.TranchesData
	);

	ElectricityAndGasBill.AmountWithoutTaxes = CalculateAmountWithoutTaxes
	(
		ElectricityAndGasBill.ElectricityBill.TranchesData,
		ElectricityAndGasBill.GasBill.TranchesData,
		ElectricityAndGasBill.Taxes
	);

	ElectricityAndGasBill.AmountWithTaxes = CalculateAmountAmountWithTaxes
	(
		ElectricityAndGasBill.ElectricityBill,
		ElectricityAndGasBill.GasBill,
		ElectricityAndGasBill.Taxes
	);

	ElectricityAndGasBill = StampProgram(ElectricityAndGasBill);
	

	ElectricityAndGasBill.TotalAmountDueCash = ElectricityAndGasBill.AmountWithTaxes +
		ElectricityAndGasBill.StampAmount;



	return ElectricityAndGasBill;
}