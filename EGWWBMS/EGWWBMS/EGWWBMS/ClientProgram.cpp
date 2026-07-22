#pragma once
#include <iostream>
#include "ClientDataFile.h"
#include "ClientProgram.h"
#include "Input.h"

using namespace std;

sClient ReadClientID()
{
	sClient Client;
	Client.ID = Reads::ReadID("Please enter the Client ID: ");

	return Client;
}

bool ClientProgram(sClient& Client)
{
	Client = ReadClientID();

	if (!ClientDataOperations::GetClientByID(Client, Client.ID))
		return false;


	return true;
}
