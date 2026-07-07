#include "Tranch.h"
#include "Input.h"
#include "Math.h"


sTranch TrancheOperations::ReadTrancheInfo()
{
	sTranch Tranch;
	Tranch.MaximumTrancheConsumption =
		Reads::ReadPositiveDecimalNumber("Enter maximum consumption for the tranche: ");

	Tranch.TrancheUnitPrice = 
		Reads::ReadPositiveDecimalNumber("Please enter the unit price: ");

	return Tranch;
}

sTranch TrancheOperations::DistributeConsumptionToTranche(double &Consumption, sTranch Tranch)
{
	if (Consumption >= Tranch.MaximumTrancheConsumption)
	{
		Tranch.TrancheConsumption = Tranch.MaximumTrancheConsumption;
		Consumption = Consumption - Tranch.MaximumTrancheConsumption;
	}
	else
	{
		Tranch.TrancheConsumption = Consumption;
		Consumption = 0;
	}
	
	return Tranch;
}

sTranch TrancheOperations::CalculateTrancheAmount(sTranch Tranch)
{
	Tranch.TrancheAmount 
		= OperationsMath::Multiply(Tranch.TrancheConsumption, Tranch.TrancheUnitPrice);

	return Tranch;
}

short TrancheOperations::GetLastTrancheIndex(const vector <sTranch>& vTranchs)
{
	return vTranchs.size();
}

sTranch TrancheOperations::GetTrancheMaxConsumption(sTranch Tranch)
{
	Tranch.MaximumTrancheConsumption = std::numeric_limits<double>::max();
	return Tranch;
}

vector <sTranch> TrancheOperations::GetLastTrancheMaxConsumption(vector <sTranch> vTranchs)
{
	short LastTrancheIndex = GetLastTrancheIndex(vTranchs);
	vTranchs[LastTrancheIndex] = GetTrancheMaxConsumption(vTranchs[LastTrancheIndex]);
	return vTranchs;
}





vector <sTranch> TranchesOperations::ReadTranchesInfo()
{
	sTranch Tranch;
	vector <sTranch> vTranchesInfo;
	short Count = 1;
	char AnswerReadMoreTranch = 'Y';

	do
	{
		cout << "Reading information for tranche number [" << Count << "]\n";
		Tranch = TrancheOperations::ReadTrancheInfo();
		vTranchesInfo.push_back(Tranch);
		Count++;

		cout << "Do you want to add another tranche? Enter 'y' for Yes or 'n' for No: ";
		cin >> AnswerReadMoreTranch;
	} while (toupper(AnswerReadMoreTranch) == 'Y');
	vTranchesInfo = TrancheOperations::GetLastTrancheMaxConsumption(vTranchesInfo);

	return vTranchesInfo;
}

vector <sTranch> TranchesOperations::DistributeConsumptionToTranches
    (double Consumption, vector <sTranch> vTranchs)
{
	for (sTranch& Tranch : vTranchs)
		Tranch = TrancheOperations::DistributeConsumptionToTranche(Consumption, Tranch);
	return vTranchs;
}

vector <sTranch> TranchesOperations::CalculateTranchesAmounts(vector <sTranch> vTranchs)
{
	
	for (sTranch& Tranch : vTranchs)
		Tranch = TrancheOperations::CalculateTrancheAmount(Tranch);
	return vTranchs;
}



