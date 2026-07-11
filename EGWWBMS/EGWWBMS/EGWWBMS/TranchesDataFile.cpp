#include <iostream>
#include <string>
#include <vector>
#include "TrancheDataFile.h"
#include "TranchesDataFile.h"
using namespace std;

string TranchesDataOperations::convertTranchesDataStructToStringLine
(
	const sTranchesData& TranchesData,
	const string& StartMarker ,
	const string& EndMarker  ,
	const string& Separator 
)
{
	string TranchesDataLine = "";
	TranchesDataLine += StartMarker;
	TranchesDataLine += TranchesDataOperations::convertTranchesStructToStringLine(TranchesData.vTranches);
	TranchesDataLine += to_string(TranchesData.PrimaryTranchesTotalAmount) + Separator;
	TranchesDataLine += to_string(TranchesData.SecondaryTranchesTotalAmount) ;
	TranchesDataLine += EndMarker;


	return TranchesDataLine;
}