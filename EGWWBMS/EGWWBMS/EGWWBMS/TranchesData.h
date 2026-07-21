#pragma once
#include "Tranche.h"

struct sTranchesData
{
	vector<sTranche> vTranches;
	//trache 1 and 2.
	double PrimaryTranchesTotalAmount = 0;
	//Secondary tranches (Tranches 3 and above).
	double SecondaryTranchesTotalAmount = 0;
};

namespace TranchesDataOperations
{
	double CalculateTotalTrancheAmountFromTo
	(const short& From,  short To, const vector <sTranche>& vTrTranchsan);
} 