#pragma once
#include <iostream>
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
}
