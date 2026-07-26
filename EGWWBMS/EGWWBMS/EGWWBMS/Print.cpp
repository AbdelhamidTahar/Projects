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
	cout << "Client ID:" << left << setw(10) << Client.ID << endl;
	cout << "Client Full Name:" << left << setw(30) << Client.FullName << endl;
	cout << endl;
}


void PrintTranches(const vector<sTranche>& vTranche)
{


	cout << "__________________________________________________________________________________\n";
	cout << "|Tranche Consumption|Maximum Tranche Consumption|Tranche Unit Price|Tranche Amount|\n";
	cout << "----------------------------------------------------------------------------------\n";
	
	for (const sTranche& Tranche : vTranche)
	{
		cout << left << "|" << setw(19) << Tranche.TrancheConsumption << "|"
			<< setw(19) << Tranche.MaximumTrancheConsumption << "|"
			<< setw(19) << Tranche.TrancheUnitPrice << "|"
			<< setw(19) << Tranche.TrancheAmount << "|\n";
	cout << "----------------------------------------------------------------------------------\n";
	}
	
}

void PrintTranchesData(const sTranchesData& TranchesData)
{
	PrintTranches(TranchesData.vTranches);
	cout << "Primary Tranches Total Amount: " << TranchesData.PrimaryTranchesTotalAmount << endl;
	cout << "Secondary Tranches Total Amount: " << TranchesData.SecondaryTranchesTotalAmount << endl;
	cout << endl;
}

void PrintBodyElectricityAndGasBill(const sElectricityAndGasBill& ElectricityAndGasBill)
{
	PrintClient(ElectricityAndGasBill.Client);

	printf("Electricity Consumption: %.2f KWH\n", ElectricityAndGasBill.ElectricityBill.Consumption);
	printf("Electricity Consumption Amount: %.2f DA\n",
		ElectricityAndGasBill.ElectricityBill.ConsumptionAmount);

	cout << endl;


	printf("Gas Consumption: %.2f TH\n", ElectricityAndGasBill.GasBill.Consumption);
	printf("Gas Consumption Amount: %.2f DA\n",
		ElectricityAndGasBill.GasBill.ConsumptionAmount);

	cout << "Electricity Bill Tranches Data\n";
	PrintTranchesData(ElectricityAndGasBill.ElectricityBill.TranchesData);
	cout << "Gas Bill Tranches Data\n";
	PrintTranchesData(ElectricityAndGasBill.GasBill.TranchesData);


	cout << "Fixed Charges: " << ElectricityAndGasBill.Taxes.FixedCharges << endl;
	cout << "Service And Fees: " << ElectricityAndGasBill.Taxes.ServiceAndFees << endl;
	cout << "Amount Without Taxes: " << ElectricityAndGasBill.AmountWithoutTaxes << endl;
	cout << "VTA" << ElectricityAndGasBill.Taxes.FirstVATPercentage << ": " 
		<< ElectricityAndGasBill.Taxes.FirstVATAmount << endl;
	cout << "VTA" << ElectricityAndGasBill.Taxes.SecondVATPercentage << ": "
		<< ElectricityAndGasBill.Taxes.SecondVATAmount << endl;
	cout << "Total VTA" << ElectricityAndGasBill.Taxes.TotalVATAmount << endl;
	cout << "Fixed Consumption Duty: " << ElectricityAndGasBill.Taxes.FixedConsumptionDuty << endl;
	cout << "Housing Tax: " << ElectricityAndGasBill.Taxes.HousingTax << endl;
	cout << "Contribution: " << ElectricityAndGasBill.Taxes.Contribution << endl;
	cout << "REPE Tax Amount: " << ElectricityAndGasBill.Taxes.REPETaxAmount << endl;
	cout << "RGPE Tax Amount: " << ElectricityAndGasBill.Taxes.RGPETaxAmount << endl;
	
	cout << "__________________________________________\n";
	cout << "|" << setw(42) << ElectricityAndGasBill.AmountWithTaxes << "|\n";
	cout << "__________________________________________\n";

	cout << "Stamp" << ElectricityAndGasBill.StampPercentage << ": " 
		<< ElectricityAndGasBill.StampAmount << endl;


	cout << "__________________________________________\n";
	cout << "|Total Amount Due Cash: " << setw(17) << 
		ElectricityAndGasBill.TotalAmountDueCash << "|" << endl;
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
