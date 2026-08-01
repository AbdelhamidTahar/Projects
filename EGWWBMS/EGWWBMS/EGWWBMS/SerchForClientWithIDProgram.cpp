#include "SerchForClientWithIDProgram.h"
#include "ClientProgram.h"
#include "Print.h"
#include "UI.h"
#include "SarchMenuProgram.h"

bool SerchForClientWithIDProgram()
{
	sClient Client;

	if (!ClientProgram(Client))
	{
		Menus::GoBackToSerchMenu("\033[1;31mError: Sorry, no client found with this ID!\033[0m\n");
		return false;
	}

	PrintClient(Client);

	Menus::GoBackToSerchMenu("", true);


	return true;
}