#pragma once
#include "Tranch.h"

struct TranchesData
{
	vector<sTranch> vTranches;
	//trache 1 and 2.
	double PrimaryTranchesTotalAmount = 0;
	//Secondary tranches (Tranches 3 and above).
	double SecondaryTranchesTotalAmount = 0;
};

namespace TranchesDataOperations
{
	double CalculateTotalTrancheAmountFromTo
	(const short& startTrancheIndex, const short& endTrancheIndex, const vector <sTranch>& vTrTranchsan);

} 