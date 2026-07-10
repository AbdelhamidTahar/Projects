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
		const string& StartMarker = "StartTTranchesData",
		const string& EndMarker = "EndTranchesData",
		const string& Separator = "//#//"
	   );
}


