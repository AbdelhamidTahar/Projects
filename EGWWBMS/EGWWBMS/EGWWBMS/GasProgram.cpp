#include <iostream>
#include "GasProgram.h"
#include "ElectricityOrGasBilProgram.h"

using namespace std;

sElectricityOrGasBil GasBillProgram
(const sElectricityAndGasBill& ElectricityAndGasBill)
{
	return  ElectricityOrGasBillProgram(ElectricityAndGasBill, eOldIndexes::OldGasIndex);
}