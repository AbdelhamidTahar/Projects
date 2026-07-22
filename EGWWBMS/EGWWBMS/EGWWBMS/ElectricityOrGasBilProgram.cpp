#include <iostream>
#include "TranchesDataProgram.h"
#include "ElectricityOrGasBilProgram.h"
using namespace std;

double CalculateConsumptionElectricityOrGas(const sElectricityOrGasBil &ElectricityOrGasBil)
{
	return (ElectricityOrGasBil.NewIndex - ElectricityOrGasBil.OldIndex) * ElectricityOrGasBil.Factor;
}


sElectricityOrGasBil ElectricityOrGasBillProgram
(const sClient& Client, eOldIndexes eTypeOfBill)
{
	sElectricityOrGasBil ElectricityOrGasBil;

	ElectricityOrGasBil.OldIndex = ElectricityOrGasBillDataOperations::GetOldElectricityOrGasIndex
	(Client.ID, "ElectricityAndGasBills", eTypeOfBill);

	ElectricityOrGasBil.NewIndex = Reads::ReadNewIndex
	(ElectricityOrGasBil.OldIndex, "\nPlease enter the new reading between parentheses (NewIndex): ");

	ElectricityOrGasBil.Factor = Reads::ReadFactor
	("\nPlease enter the Factor: ");

	ElectricityOrGasBil.Consumption = CalculateConsumptionElectricityOrGas(ElectricityOrGasBil);

	ElectricityOrGasBil.TranchesData = TranchesDataProgram(ElectricityOrGasBil.Consumption);

	ElectricityOrGasBil.ConsumptionAmount =
		ElectricityOrGasBil.TranchesData.PrimaryTranchesTotalAmount +
		ElectricityOrGasBil.TranchesData.SecondaryTranchesTotalAmount;


	return ElectricityOrGasBil;
}