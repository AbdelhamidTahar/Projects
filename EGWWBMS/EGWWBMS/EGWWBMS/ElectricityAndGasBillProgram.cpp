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
		Menus::GoBackToAddMenu("\033[1;31mError: Client not found.\033[0m\n");
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

	system("cls");
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
			cout << "\n\033[32mBill added successfully!\033[0m\n";

			cout << "\nDo You Want Add More Electricity And GasBill: ";
			cin >> Answer;
			Answer = toupper(Answer);
		}
		else
		{
			return false;
		}

	} while (Answer == 'Y');

	return true;
}

