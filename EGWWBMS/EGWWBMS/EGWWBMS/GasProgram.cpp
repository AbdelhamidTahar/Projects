#include <iostream>
#include "GasProgram.h"
#include "ElectricityOrGasBilProgram.h"

using namespace std;

sElectricityOrGasBil GasBillProgram
(const sClient& Client)
{
	return  ElectricityOrGasBillProgram(Client, eOldIndexes::OldGasIndex);
}