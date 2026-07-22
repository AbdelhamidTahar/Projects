#include <iostream>
#include "ElectricityProgram.h"
#include "ElectricityOrGasBilProgram.h"

using namespace std;

sElectricityOrGasBil ElectricityBillProgram
(const sClient& Client)
{
	return  ElectricityOrGasBillProgram(Client, eOldIndexes::OldElectricityIndex);
}