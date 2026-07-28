#include <vector>
#include "SerchForClientWithFullNameProgram.h"
#include "Input.h"
#include "ClientDataFile.h"
#include "UI.h"
#include "Print.h"

bool SerchForClientWithFullNameProgram()
{
	string FullName = Reads::ReadFullName();

	vector <sClient> vClient;
	vClient = ClientDataOperations::LoadDataClient();

	if (vClient.empty())
	{
		Menus::GoBackToSerchMenu("Error: Sorry, there are no clients found with this name!\n");
		return false;
	}
	 

	vector <sClient> TvClient;
	bool IsClientExectByFullName = false;
	for (const sClient& Client : vClient)
	{
		if (Client.FullName == FullName)
		{
			IsClientExectByFullName = true;
			TvClient.push_back(Client);
		}
	}


	if (IsClientExectByFullName == false)
	{
		Menus::GoBackToSerchMenu("Sorry, no client found with this full name!\n");
		return false;
	}

	int Count = 1;
	for (const sClient& Client : TvClient)
	{
		cout << "\nClient Number: " << Count << endl;
		PrintClient(Client);
		Count++;
	}


	return true;
}