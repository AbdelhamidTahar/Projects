#include "SerchForClientWithIDProgram.h"
#include "ClientProgram.h"
#include "Print.h"
#include "UI.h"

bool SerchForClientWithIDProgram()
{
	sClient Client;

	if (!ClientProgram(Client))
	{
		Menus::GoBackToSerchMenu("Error: Sorry, no client found with this ID!\n");
		return false;
	}

	PrintClient(Client);


	return true;
}