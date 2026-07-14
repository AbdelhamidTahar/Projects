#include <iostream>
#include <string>
#include "Input.h"
#include "GlobalDataFile.h"
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
	TrancheLine += to_string(Tranch.TrancheUnitPrice) + Separator;
	TrancheLine += to_string(Tranch.TrancheConsumption) + Separator;
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
	string TranchesLine = "";
	TranchesLine += StartMarker;
	for (const sTranche& Tranch : vTranchs)
		TranchesLine += TrancheDataOperations::convertTrancheStructToStringLine(Tranch);
	TranchesLine += EndMarker;

	return TranchesLine;
}

sTranche TrancheDataOperations::ConvertvDataTrancheToDataStruct
(
	const vector<string>& vTranche
)
{
	sTranche Tranche;

	Tranche.MaximumTrancheConsumption = stod(vTranche[0]);
	Tranche.TrancheUnitPrice = stod(vTranche[1]);
	Tranche.TrancheConsumption = stod(vTranche[2]);
	Tranche.TrancheAmount = stod(vTranche[3]);

	return Tranche;
}

sTranche TrancheDataOperations::ConvertTrancheStringLineToDataStruct
(
	string TrancheStringLine,
	const string& StartMarker  ,
	const string& EndMarker ,
	const string& Separator 
)
{
	TrancheStringLine = GlobalOperations::DeleteStartMarkerTAndEndMarker
	  (TrancheStringLine, StartMarker, EndMarker);


	vector<string> vDataTranche;
	vDataTranche = InputOperations::SplitStringWithSeparator(TrancheStringLine);


	sTranche Tranche = ConvertvDataTrancheToDataStruct(vDataTranche);

	return Tranche;
}


vector<sTranche> TranchesDataOperations::ConvertTranchesStringLineToStructs
(
	string TranchesStringLine,
	const string& StartMarker,
	const string& EndMarker,
	const string& Separator
)
{

	string TrancheStringLine = "";
	sTranche Tranche;
	vector<sTranche> vTranches;

	TranchesStringLine = GlobalOperations::DeleteStartMarkerTAndEndMarker
	(TranchesStringLine, StartMarker, EndMarker);

	do
	{
		TrancheStringLine = GlobalOperations::GetTextFromStartMarkerToEndMarker
		(TranchesStringLine, "StartTranche", "EndTranche");

		Tranche = TrancheDataOperations::ConvertTrancheStringLineToDataStruct
		(TrancheStringLine, "StartTranche", "EndTranche");

		vTranches.push_back(Tranche);

		TranchesStringLine = GlobalOperations::DeleteTextFromStartMarkerToEndMarker
		(TranchesStringLine, "StartTranche", "EndTranche");

	} while (!Checks::IsStringEmpty(TranchesStringLine));

	return vTranches;
}
