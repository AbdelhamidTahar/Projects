#include <iostream>
#include <string>
#include "TranchDataFile.h"
using namespace std;


string TrancheDataOperations::convertTrancheStructToStringLine
(
	const sTranch& Tranch,
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

string TrancheسDataOperations::convertTrancheStructToStringLine
(
	const vector <sTranch>& vTranchs,
	const string& StartMarker,
	const string& EndMarker ,
	const string& Separator 
)
{
	string TranchsLine = "";
	TranchsLine += StartMarker;
	for (const sTranch& Tranch : vTranchs)
		TranchsLine += TrancheDataOperations::convertTrancheStructToStringLine(Tranch);
	TranchsLine += EndMarker;

	return TranchsLine;
}