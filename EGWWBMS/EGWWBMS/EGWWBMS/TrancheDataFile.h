#pragma once
#include <iostream>
#include <vector>
#include "Tranche.h"
using namespace std;
namespace TrancheDataOperations
{
	string convertTrancheStructToStringLine
	(
		const sTranche& Tranch,
		const string& StartMarker = "StartTranche",
		const string& EndMarker = "EndTranche",
		const string& Separator = "//#//"
	);

}
namespace TranchesDataOperations
{
	string convertTranchesStructToStringLine
	(
		const vector <sTranche>& vTranchs,
		const string& StartMarker = "StartTranches",
		const string& EndMarker = "EndTranches",
		const string& Separator = "//#//"
	);
}
