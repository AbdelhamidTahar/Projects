#include <iostream>
#include "ElectricityProgram.h"
#include "ElectricityOrGasBilProgram.h"

using namespace std;

sElectricityOrGasBil ElectricityBillProgram
(const sElectricityAndGasBill& ElectricityAndGasBill)
{
	return  ElectricityOrGasBillProgram(ElectricityAndGasBill, eOldIndexes::OldElectricityIndex);
}