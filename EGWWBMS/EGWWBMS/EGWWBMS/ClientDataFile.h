#pragma once
#include <iostream>
#include <vector>
#include "Client.h"
using namespace std;

namespace ClientDataOperations
{
	string ConvertClientDataStructToStringLine
	(
		const sClient& Client,
		const string& StartMarker = "StartClient",
		const string& EndMarker = "EndClient",
		const string& Separator = "//#//"
	);

	sClient ConvertClientStringLineToDataStruct
	(
		string ClientStringLine,
		const string& StartMarker = "StartClient",
		const string& EndMarker = "EndClient",
		const string& Separator = "//#//"
	);

	sClient ConvertvDataClientToDataStruct
	(
		const vector<string> &vDataClient
	);

}
