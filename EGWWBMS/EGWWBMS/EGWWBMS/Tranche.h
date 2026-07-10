#pragma once
#include <iostream>
#include <vector>;
using namespace std;
struct sTranche
{
	double MaximumTrancheConsumption = 0;
	double TrancheUnitPrice = 0;
	double TrancheConsumption = 0;
	double TrancheAmount = 0;
};

namespace TrancheOperations
{
	sTranche ReadTrancheInfo();
	sTranche DistributeConsumptionToTranche(double &Consumption, sTranche Tranch);
	sTranche CalculateTrancheAmount(sTranche Tranch);
	vector <sTranche> GetLastTrancheMaxConsumption(vector <sTranche> vTranchs);
	short GetLastTrancheIndex(const vector <sTranche>& vTranchs);
	sTranche GetTrancheMaxConsumption(sTranche Tranch);
}


namespace TranchesOperations
{
	vector <sTranche> ReadTranchesInfo();
	vector <sTranche> DistributeConsumptionToTranches(double Consumption, vector <sTranche> vTranchs);
	vector <sTranche> CalculateTranchesAmounts(vector <sTranche> vTranchs);
	short GetTranchesElementCount(const vector <sTranche> &vTranchs);
}


