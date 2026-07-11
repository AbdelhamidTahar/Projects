#include "TranchesData.h"

double TranchesDataOperations::CalculateTotalTrancheAmountFromTo
  (const short& From, short To, const vector <sTranche>& vTrTranchsan)
{
	short NumberOfElement = NumberOfElement = TranchesOperations::GetTranchesElementCount(vTrTranchsan);
	To = (NumberOfElement >= To ? To : NumberOfElement);

	short StartIndexTranche = From - 1;
	short 	EndIndexTranche = To - 1;

	short Sum = 0;

	for (short i = StartIndexTranche; i <= EndIndexTranche; i++)
	{
		Sum += vTrTranchsan[i].TrancheAmount;
	}

	return Sum;
}
