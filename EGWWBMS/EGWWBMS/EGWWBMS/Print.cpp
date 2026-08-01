#include "Print.h"
#include <iomanip>


void PrintHeadarElectricityAndGasBill()
{
	cout << "------------------------------------\n";
	cout << "|                                   |\n";
	cout << "|                                   |\n";
	cout << "|      Electricity And GasBill      |\n";
	cout << "|                                   |\n";
	cout << "|                                   |\n";
	cout << "------------------------------------\n";
	cout << "------------------------------------------------------------------------------------\n";
}
void PrintClient(const sClient& Client)
{
	cout << "\nClient ID:" << left << "\033[33m" << setw(10) << Client.ID << "\033[0m" << endl;
	cout << "Client Full Name:" << left << "\033[33m" << setw(30) << Client.FullName << "\033[0m" << endl;
	cout << endl;
}


void PrintTranches(const vector<sTranche>& vTranche)
{


	cout << "_______________________________________________________________________________________\n";
	cout << "|Tranche Consumption|Maximum Tranche Consumption|Tranche Unit Price|Tranche Amount    |\n";
	cout << "---------------------------------------------------------------------------------------\n";
	
	for (const sTranche& Tranche : vTranche)
	{

		cout << left << "|" << setw(19) << Tranche.TrancheConsumption << "|"
			<< setw(27) << Tranche.MaximumTrancheConsumption << "|";

		cout << left << setw(27) << ("\033[1;96m" + to_string(Tranche.TrancheUnitPrice) + "\033[0m") << "|";

		cout << left << "\033[1;96m" << setw(18) << to_string(Tranche.TrancheAmount) << "\033[0m" << "  |\n";

		cout << "---------------------------------------------------------------------------------------\n";
	}
	
}

void PrintTranchesData(const sTranchesData& TranchesData)
{
	PrintTranches(TranchesData.vTranches);
	

	cout << "Primary Tranches Total Amount: " 
		<< "\033[1;96m" << TranchesData.PrimaryTranchesTotalAmount << "\033[0m" << endl;
	cout << "Secondary Tranches Total Amount: " 
		<< "\033[1;96m" << TranchesData.SecondaryTranchesTotalAmount << "\033[0m" << endl;
	cout << endl;
}

void PrintBodyElectricityAndGasBill(const sElectricityAndGasBill& ElectricityAndGasBill)
{
	
	PrintClient(ElectricityAndGasBill.Client);

	cout << "Bill ID: " << "\033[33m" << ElectricityAndGasBill.ID << "\033[0m" << endl;
	cout << endl;

	printf("Old Index Electricity: \033[1;96m%.2f\033[0m\n", 
		ElectricityAndGasBill.ElectricityBill.OldIndex);

	printf("New Index Electricity:\033[1;96m%.2f\033[0m\n", 
		ElectricityAndGasBill.ElectricityBill.NewIndex);

	printf("Electricity Consumption: %.2f KWH\n", 
		ElectricityAndGasBill.ElectricityBill.Consumption);

	printf("Electricity Consumption Amount: %.2f DA\n",
		ElectricityAndGasBill.ElectricityBill.ConsumptionAmount);

	cout << endl;
	printf("Old Index Gas: \033[1;96m%.2f\033[0m\n", 
		ElectricityAndGasBill.GasBill.OldIndex);

	printf("New Index Gas:\033[1;96m%.2f\033[0m\n",
		ElectricityAndGasBill.GasBill.NewIndex);

	printf("Gas Consumption:\033[1; 96m %.2f TH\033[0m\n", 
		ElectricityAndGasBill.GasBill.Consumption);

	printf("Gas Consumption Amount:\033[1; 96m %.2f DA\033[0m\n",
		ElectricityAndGasBill.GasBill.ConsumptionAmount);

	cout << "\n\nElectricity Bill Tranches Data\n";
	PrintTranchesData(ElectricityAndGasBill.ElectricityBill.TranchesData);

	cout << "\n\nGas Bill Tranches Data\n";
	PrintTranchesData(ElectricityAndGasBill.GasBill.TranchesData);


	cout << "Fixed Charges: " << ElectricityAndGasBill.Taxes.FixedCharges << endl;
	cout << "Service And Fees: " << ElectricityAndGasBill.Taxes.ServiceAndFees << endl;
	cout << "Amount Without Taxes: " 
		<< "\033[1;96m" << ElectricityAndGasBill.AmountWithoutTaxes << "\033[0m" << endl;
	cout << "VTA" << ElectricityAndGasBill.Taxes.FirstVATPercentage << ": " 
		<< ElectricityAndGasBill.Taxes.FirstVATAmount << endl;
	cout << "VTA" << ElectricityAndGasBill.Taxes.SecondVATPercentage << ": "
		<< ElectricityAndGasBill.Taxes.SecondVATAmount << endl;
	cout << "Total VTA: " <<
		"\033[1;96m" << ElectricityAndGasBill.Taxes.TotalVATAmount << "\033[0m" << endl;
	cout << "Fixed Consumption Duty: " << ElectricityAndGasBill.Taxes.FixedConsumptionDuty << endl;
	cout << "Housing Tax: " << ElectricityAndGasBill.Taxes.HousingTax << endl;
	cout << "Contribution: " << ElectricityAndGasBill.Taxes.Contribution << endl;
	cout << "REPE Tax Amount: " << ElectricityAndGasBill.Taxes.REPETaxAmount << endl;
	cout << "RGPE Tax Amount: " << ElectricityAndGasBill.Taxes.RGPETaxAmount << endl;
	
	cout << "__________________________________________\n";
	cout << "|" << "Amount With Taxes: " << left << setw(30) 
		<<("\033[1;96m" + to_string(ElectricityAndGasBill.AmountWithTaxes) + "\033[0m") << "  |\n";
	cout << "__________________________________________\n";


	cout << "\nStamp" << ElectricityAndGasBill.StampPercentage << ": " 
		<< ElectricityAndGasBill.StampAmount << endl;


	cout << "\n__________________________________________\n";
	cout << "|" << "Amount With Taxes: " << left << setw(30) <<
		("\033[1;96m" + to_string(ElectricityAndGasBill.AmountWithTaxes) + "\033[0m") << "  |\n";
	cout << "------------------------------------------\n";



}

void PrintFootarElectricityAndGasBill()
{
	cout << "------------------------------------------------------------------------------------\n";
}

void PrintElectricityAndGasBill(const sElectricityAndGasBill& ElectricityAndGasBill)
{
	PrintHeadarElectricityAndGasBill();
	PrintBodyElectricityAndGasBill(ElectricityAndGasBill);
	PrintFootarElectricityAndGasBill();
}
