#pragma once
#include <iostream>
#include <vector>
#include "TranchesData.h"
using namespace std;

namespace TranchesDataOperations
{
	string convertTranchesDataStructToStringLine
	   (
		const sTranchesData& TranchesData,
		const string& StartMarker = "StartTranchesData",
		const string& EndMarker = "EndTranchesData",
		const string& Separator = "//#//"
	   );

	sTranchesData ConvertVectorsToTranchesDataStruct
	   (const vector<sTranche> &vTranches, const vector<string> &vRemainingData) ;

	sTranchesData ConvertTranchesDataStringLineToDataStruct
	(
	    string TranchesStringData,
		const string& StartMarker = "StartTranchesData",
		const string& EndMarker = "EndTranchesData",
		const string& Separator = "//#//"
	);
}


