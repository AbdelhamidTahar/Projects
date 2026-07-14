#include <iostream>
#include <string>
#include <vector>
#include "Input.h"
#include "ClientDataFile.h"
#include "GlobalDataFile.h"
using namespace std;


string ClientDataOperations::ConvertClientDataStructToStringLine
(
	const sClient& Client,
	const string& StartMarker,
	const string& EndMarker ,
	const string& Separator
)
{
	string ClientLine = "";
	ClientLine += StartMarker;
	ClientLine += Client.ID + Separator;
	ClientLine += Client.FullName;
	ClientLine += EndMarker;

	return ClientLine;
}


sClient ClientDataOperations::ConvertvDataClientToDataStruct
(
	const vector<string>& vDataClient
)
{
	sClient Client;

	Client.ID = vDataClient[0];
	Client.FullName= vDataClient[1];

	return Client;
}


sClient ClientDataOperations::ConvertClientStringLineToDataStruct
(
	string ClientStringLine,
	const string& StartMarker ,
	const string& EndMarker ,
	const string& Separator 
)
{

	ClientStringLine = GlobalOperations::DeleteStartMarkerTAndEndMarker
	 (ClientStringLine, StartMarker, EndMarker);

	string DataClient = "";
	vector<string> vDataClient;
	int SeparatorPos = 0;

	while ((SeparatorPos = ClientStringLine.find(Separator)) != std::string::npos)
	{
		DataClient = ClientStringLine.substr(0, SeparatorPos);
		vDataClient.push_back(DataClient);
		ClientStringLine.erase(0, SeparatorPos + Separator.length());
	}

	if(!Checks::IsStringEmpty(ClientStringLine))
		vDataClient.push_back(ClientStringLine);

	
	sClient Client = ConvertvDataClientToDataStruct(vDataClient);

	return Client;
}