#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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

bool ClientDataOperations::FindLastElectricityAndGasBillByClientID
(
	const string& ClientID, 
	const vector<sElectricityAndGasBill>& vElectricityAndGasBill, 
	sElectricityAndGasBill &ElectricityAndGasBill
)
{
	int NumberOfBills = vElectricityAndGasBill.size();

	if (NumberOfBills == 0)
		return false;

	NumberOfBills--;

	for (int i = NumberOfBills; i >= 0; i--)
	{
		if (vElectricityAndGasBill[i].Client.ID == ClientID)
		{
			ElectricityAndGasBill = vElectricityAndGasBill[i];
			return true;
		}
	}

	return false;
}


vector<sClient> ClientDataOperations::LoadDataClient(const string& FileName)
{
	sClient Client;
	vector<sClient> vClients;
	fstream ClientData;
	string ClientLine = "";

	ClientData.open(FileName);
	if (ClientData.is_open())
	{
		while (getline(ClientData, ClientLine))
		{
			Client = ConvertClientStringLineToDataStruct(ClientLine);
			vClients.push_back(Client);
		}
		ClientData.close();
	}


	return vClients;
}


bool ClientDataOperations::FindClientByID
(
	sClient& Client,
	const string& ClientID,
	const vector<sClient>& vClients
)
{
	for (const sClient &TClients : vClients)
	{
		if (TClients.ID == ClientID)
		{
			Client = TClients;
			return true;
		}

	}

	return false;
}

bool ClientDataOperations::GetClientByID(sClient& Client, const string& ClientID, const string& FileName)
{
	vector<sClient> vClients = LoadDataClient(FileName);
	if (vClients.empty())
		return false;
	if (FindClientByID(Client, ClientID, vClients))
		return true;

	return false;
}