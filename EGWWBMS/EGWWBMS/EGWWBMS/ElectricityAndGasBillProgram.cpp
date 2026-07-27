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
#include "Print.h"

using namespace std;

bool  AddElectricityAndGasBillProgram()
{
	sElectricityAndGasBill ElectricityAndGasBill;


	if (!ClientProgram(ElectricityAndGasBill.Client))
	{
		Menus::GoBackToAddMenu("Error: Client not found.\n");
		return false;
	}

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


	ElectricityAndGasBillDataOperations::SaveElectricityAndGasBillsInFile(ElectricityAndGasBill);

	PrintElectricityAndGasBill(ElectricityAndGasBill);


	return true;
}

bool AddElectricityAndGasBillsProgram()
{
	char Answer = 'N';
	do
	{
		system("cls");
		if(AddElectricityAndGasBillProgram())
		{
			cout << "\nDo You Want Add More Electricity And GasBill: ";
			cin >> Answer;
			Answer = toupper(Answer);
		}

	} while (Answer == 'Y');

	return true;
}