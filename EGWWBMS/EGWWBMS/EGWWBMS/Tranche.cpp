#include "Tranche.h"
#include "Input.h"
#include "Math.h"


sTranche TrancheOperations::ReadTrancheInfo()
{
	sTranche Tranch;
	Tranch.MaximumTrancheConsumption =
		Reads::ReadPositiveDecimalNumber("Enter maximum consumption for the tranche: ");

	Tranch.TrancheUnitPrice = 
		Reads::ReadPositiveDecimalNumber("Please enter the unit price: ");

	return Tranch;
}

sTranche TrancheOperations::DistributeConsumptionToTranche(double &Consumption, sTranche Tranch)
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

sTranche TrancheOperations::CalculateTrancheAmount(sTranche Tranch)
{
	Tranch.TrancheAmount 
		= OperationsMath::Multiply(Tranch.TrancheConsumption, Tranch.TrancheUnitPrice);

	return Tranch;
}

short TrancheOperations::GetLastTrancheIndex(const vector <sTranche>& vTranchs)
{
	return vTranchs.size();
}

sTranche TrancheOperations::GetTrancheMaxConsumption(sTranche Tranch)
{
	Tranch.MaximumTrancheConsumption = std::numeric_limits<double>::max();
	return Tranch;
}

vector <sTranche> TrancheOperations::GetLastTrancheMaxConsumption(vector <sTranche> vTranchs)
{
	short LastTrancheIndex = GetLastTrancheIndex(vTranchs);
	vTranchs[LastTrancheIndex-1] = GetTrancheMaxConsumption(vTranchs[LastTrancheIndex-1]);
	return vTranchs;
}





vector <sTranche> TranchesOperations::ReadTranchesInfo()
{
	sTranche Tranch;
	vector <sTranche> vTranchesInfo;
	short Count = 1;
	char AnswerReadMoreTranch = 'Y';

	do
	{
		cout << "\nReading information for tranche number [" << Count << "]\n";
		Tranch = TrancheOperations::ReadTrancheInfo();
		vTranchesInfo.push_back(Tranch);
		Count++;

		cout << "\nDo you want to add another tranche? Enter 'y' for Yes or 'n' for No: ";
		cin >> AnswerReadMoreTranch;
	} while (toupper(AnswerReadMoreTranch) == 'Y');
	vTranchesInfo = TrancheOperations::GetLastTrancheMaxConsumption(vTranchesInfo);

	return vTranchesInfo;
}

vector <sTranche> TranchesOperations::DistributeConsumptionToTranches
    (double Consumption, vector <sTranche> vTranchs)
{
	vector <sTranche> TvTranchs;
	for (sTranche& Tranch : vTranchs)
	{
		Tranch = TrancheOperations::DistributeConsumptionToTranche(Consumption, Tranch);
		TvTranchs.push_back(Tranch);
	}
	return TvTranchs;
}

vector <sTranche> TranchesOperations::CalculateTranchesAmounts(vector <sTranche> vTranchs)
{
	vector <sTranche> TvTranchs;
	for (sTranche& Tranch : vTranchs)
	{
		Tranch = TrancheOperations::CalculateTrancheAmount(Tranch);
		TvTranchs.push_back(Tranch);
	}
	return vTranchs;
}


short TranchesOperations::GetTranchesElementCount(const vector <sTranche>& vTranchs)
{
	return vTranchs.size();
}

