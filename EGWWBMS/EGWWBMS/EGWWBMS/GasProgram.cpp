#include <iostream>
#include "GasProgram.h"
#include "ElectricityOrGasBilProgram.h"

using namespace std;

sElectricityOrGasBil GasBillProgram
(const sClient& Client)
{
	cout << "\033[1;95m\Gas Bill\033[0m\n";
	return  ElectricityOrGasBillProgram(Client, eOldIndexes::OldGasIndex);
}