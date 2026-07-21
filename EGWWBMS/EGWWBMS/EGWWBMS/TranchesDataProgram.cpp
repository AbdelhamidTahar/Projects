#include <iostream>
#include "TranchesDataProgram.h"
using namespace std;

sTranchesData TranchesDataProgram(const double& Consumption)
{
	sTranchesData TranchesData;

	TranchesData.vTranches = TranchesOperations::ReadTranchesInfo();

	TranchesData.vTranches = TranchesOperations::DistributeConsumptionToTranches
	(Consumption, TranchesData.vTranches);

	TranchesData.vTranches = TranchesOperations::CalculateTranchesAmounts(TranchesData.vTranches);

	TranchesData.PrimaryTranchesTotalAmount = TranchesDataOperations::CalculateTotalTrancheAmountFromTo
	(1, 2, TranchesData.vTranches);

	TranchesData.SecondaryTranchesTotalAmount = TranchesDataOperations::CalculateTotalTrancheAmountFromTo
	(3, TranchesOperations::GetTranchesElementCount(TranchesData.vTranches), TranchesData.vTranches);


	return TranchesData;
}
