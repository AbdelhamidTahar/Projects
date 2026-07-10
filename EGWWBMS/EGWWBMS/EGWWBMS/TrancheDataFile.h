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