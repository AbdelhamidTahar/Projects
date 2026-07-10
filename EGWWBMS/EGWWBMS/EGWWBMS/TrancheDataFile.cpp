#include <iostream>
#include <string>
#include "TrancheDataFile.h"
using namespace std;


string TrancheDataOperations::convertTrancheStructToStringLine
(
	const sTranche& Tranch,
	const string& StartMarker ,
	const string& EndMarker ,
	const string& Separator 
)
{
	string TrancheLine = "";
	TrancheLine += StartMarker;
	TrancheLine += to_string(Tranch.MaximumTrancheConsumption) + Separator;
	TrancheLine += to_string(Tranch.TrancheConsumption) + Separator;
	TrancheLine += to_string(Tranch.TrancheUnitPrice) + Separator;
	TrancheLine += to_string(Tranch.TrancheAmount) ;
	TrancheLine += EndMarker;

	return TrancheLine;
}

string TranchesDataOperations::convertTranchesStructToStringLine
(
	const vector <sTranche>& vTranchs,
	const string& StartMarker,
	const string& EndMarker ,
	const string& Separator 
)
{
	string TranchsLine = "";
	TranchsLine += StartMarker;
	for (const sTranche& Tranch : vTranchs)
		TranchsLine += TrancheDataOperations::convertTrancheStructToStringLine(Tranch);
	TranchsLine += EndMarker;

	return TranchsLine;
}