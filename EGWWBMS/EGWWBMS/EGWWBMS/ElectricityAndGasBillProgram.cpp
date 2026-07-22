#include <iostream>
#include "Input.h"
#include "Ui.h"
#include "ElectricityProgram.h"
#include "GasProgram.h"
#include "ElectricityAndGasBillProgram.h"
#include "ClientProgram.h"

using namespace std;

sElectricityAndGasBill  ElectricityAndGasBillProgram()
{
	sElectricityAndGasBill ElectricityAndGasBill;


	if (!ClientProgram(ElectricityAndGasBill.Client))
		Menus::GoBackTotMainMenu("Error: Client not found.\n");

	// generat id bill.
	ElectricityAndGasBill.ElectricityBill = ElectricityBillProgram(ElectricityAndGasBill.Client);
	ElectricityAndGasBill.GasBill = GasBillProgram(ElectricityAndGasBill.Client);
	// برنامج الضرائب




	return ElectricityAndGasBill;
}