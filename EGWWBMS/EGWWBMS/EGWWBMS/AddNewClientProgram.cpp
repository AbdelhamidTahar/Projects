#include "AddNewClientProgram.h"
#include "ClientProgram.h"
#include "Input.h"
#include "Print.h"


bool AddNewClient()
{
	sClient Client;

	if (ClientProgram(Client))
	{
		AddMenuProgram
		("Error: A client with this ID already exists! Please choose another ID.\n");
		return false;
	}

	Client.FullName = Reads::ReadFullName();

	if (ClientDataOperations::SaveClientToFile(Client))
	{
		PrintClient(Client);
		return true;
	}


	return true;
}

bool AddNewClients()
{
	char Answer = 'N';
	do
	{
		system("cls");
		if (AddNewClient())
		{
			cout << "\nClient added successfully!\n";

			cout << "\nDo You Want Add More Electricity And GasBill: ";
			cin >> Answer;
			Answer = toupper(Answer);
		}

	} while (Answer == 'Y');


	return true;
}






