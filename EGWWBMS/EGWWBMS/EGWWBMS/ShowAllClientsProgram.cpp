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
		Menus::GoBackToSerchMenu("Error: Sorry, there are no clients to display!\n");
		return false;
	}


	system("cls");
	int Count = 1;
	for (const sClient& Client : vClients)
	{
		
		cout << "\nClient Number: " << "\033[1;33m" << Count << "\033[0m";
		PrintClient(Client);
		Count++;
	}

	Menus::GoBackToSerchMenu("", true);

	return true;
}