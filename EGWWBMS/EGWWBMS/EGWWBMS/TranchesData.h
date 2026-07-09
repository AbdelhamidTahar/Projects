#pragma once
#include "Tranch.h"

struct sTranchesData
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
	(const short& From,  short To, const vector <sTranch>& vTrTranchsan);


} 