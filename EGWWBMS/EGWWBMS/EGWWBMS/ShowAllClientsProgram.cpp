#include "ShowAllClientsProgram.h"
#include "ClientDataFile.h"
#include "UI.h"
#include "Print.h"
#include "Vector"
#include "SarchMenuProgram.h"

bool ShowAllClientsProgram()
{
	vector<sClient> vClients;

	vClients = ClientDataOperations::LoadDataClient();

	if (vClients.empty())
	{
		SarchMenuProgram("Error: Sorry, there are no clients to display!\n");
		return false;
	}


	int Count = 1;
	for (const sClient& Client : vClients)
	{
		cout << "\nClient Number: " << Count << endl;
		PrintClient(Client);
		Count++;
	}


	return true;
}