#include "AddNewClientProgram.h"
#include "ClientProgram.h"
#include "Input.h"


bool AddNewClient()
{
	sClient Client;

	if (ClientProgram(Client))
		return false;
	Client.FullName = Reads::ReadFullName();

	if (ClientDataOperations::SaveClientToFile(Client))
	{

	}

}
bool AddNewClients();




	ElectricityAndGasBillDataOperations::SaveElectricityAndGasBillsInFile(ElectricityAndGasBill);

	PrintElectricityAndGasBill(ElectricityAndGasBill);


	return true;
}

bool AddElectricityAndGasBillsProgram()
{
	char Answer = 'N';
	do
	{
		system("cls");
		if (AddElectricityAndGasBillProgram())
		{
			cout << "\nDo You Want Add More Electricity And GasBill: ";
			cin >> Answer;
			Answer = toupper(Answer);
		}

	} while (Answer == 'Y');

	return true;
}