#pragma once
#include <iostream>
#include <string>
#include "Client.h"

#include "GlobalElectricityOrGas.h"
#include "Taxes.h"

using namespace std;

struct sElectricityAndGasBill
{
	sClient Client;
	string ID;
	sElectricityOrGasBil ElectricityBill;
	sElectricityOrGasBil GasBill;
	sTaxes Taxes;
	double AmountWithoutTaxes = 0;
	double AmountWithTaxes = 0;
	double StampPercentage = 0;
	double StampAmount = 0;
	double TotalAmountDueCash = 0;
};

double CalculateAmountWithoutTaxes
(const sTranchesData& ElectricityTranchesData,const sTranchesData& GasTranchesData,const sTaxes& Taxes);

double CalculateAmountAmountWithTaxes
(const sElectricityOrGasBil& ElectricityBill, const sElectricityOrGasBil& GasBill, const sTaxes& Taxes);

