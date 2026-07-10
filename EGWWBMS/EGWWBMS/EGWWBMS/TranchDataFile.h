#pragma once
#pragma once
#include <iostream>
#include <vector>
#include "Tranch.h"
using namespace std;
namespace TrancheDataOperations
{
	string convertTrancheStructToStringLine
	(
		const sTranch& Tranch,
		const string& StartMarker = "StartTranche",
		const string& EndMarker = "EndTranche",
		const string& Separator = "//#//"
	);

}
namespace TrancheسDataOperations
{
	string convertTrancheStructToStringLine
	(
		const vector <sTranch>& vTranchs,
		const string& StartMarker = "",
		const string& EndMarker = "",
		const string& Separator = "//#//"
	);
}
