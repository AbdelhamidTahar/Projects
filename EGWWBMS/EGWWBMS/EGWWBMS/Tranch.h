#pragma once
#include <iostream>
#include<vector>;
using namespace std;
struct sTranch
{
	double MaximumTrancheConsumption = 0;
	double TrancheUnitPrice = 0;
	double TrancheConsumption = 0;
	double TrancheAmount = 0;
};

namespace TrancheOperations
{
	sTranch ReadTrancheInfo();
	sTranch DistributeConsumptionToTranche(double &Consumption, sTranch Tranch);
	sTranch CalculateTrancheAmount(sTranch Tranch);
	vector <sTranch> GetLastTrancheMaxConsumption(vector <sTranch> vTranchs);
	short GetLastTrancheIndex(const vector <sTranch>& vTranchs);
	sTranch GetTrancheMaxConsumption(sTranch Tranch);
}


namespace TranchesOperations
{
	vector <sTranch> ReadTranchesInfo();
	vector <sTranch> DistributeConsumptionToTranches(double Consumption, vector <sTranch> vTranchs);
	vector <sTranch> CalculateTranchesAmounts(vector <sTranch> vTranchs);

}


