#pragma once
#include <iostream>
#include "Taxes.h"
#include "TranchesData.h"


using namespace std;

sTaxes TaxesProgram(const sTranchesData& TranchesDataElectricity, const sTranchesData& TranchesDataGas);