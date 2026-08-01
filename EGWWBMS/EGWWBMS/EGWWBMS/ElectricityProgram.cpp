#include <iostream>
#include "ElectricityProgram.h"
#include "ElectricityOrGasBilProgram.h"

using namespace std;


sElectricityOrGasBil ElectricityBillProgram
(const sClient& Client)
{
	cout << "\033[1;95m\nElectricity Bill\033[0m\n";
	return  ElectricityOrGasBillProgram(Client, eOldIndexes::OldElectricityIndex);
}