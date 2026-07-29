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
		SarchMenuProgram("Error: Sorry, no client found with this ID!\n");
		return false;
	}

	PrintClient(Client);


	return true;
}