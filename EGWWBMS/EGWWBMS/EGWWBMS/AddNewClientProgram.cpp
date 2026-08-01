#include "AddNewClientProgram.h"
#include "ClientProgram.h"
#include "Input.h"
#include "Print.h"
#include "UI.h"


bool AddNewClient()
{
	sClient Client;

	if (ClientProgram(Client))
	{
		Menus::GoBackToAddMenu
		("\033[31mError: A client with this ID already exists! Please choose another ID.\n\033[0m");
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
			cout << "\n\033[32mClient added successfully!\033[0m\n";

			cout << "\nDo You Want Add More Client: ";
			cin >> Answer;
			Answer = toupper(Answer);
		}
		else
		{
			return false;
		}

	} while (Answer == 'Y');


	return true;
}






