#include <iostream>
#include "ClientDataFile.h"
using namespace std;


string ClientDataOperations::ConvertClientDataStructToStringLine
(
	const sClient& Client,
	const string& StartMarker = "StartClient",
	const string& EndMarker = "EndClient",
	const string& Separator = "//#//"
)
{
	string ClientLine = "";
	ClientLine += StartMarker;
	ClientLine += Client.ID + Separator;
	ClientLine += Client.FullName;
	ClientLine += EndMarker;

	return ClientLine;
}
