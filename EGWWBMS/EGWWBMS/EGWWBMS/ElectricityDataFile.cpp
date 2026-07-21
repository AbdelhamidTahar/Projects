#include <iostream>
#include "ElectricityDataFile.h"
#include "GlobalElectricityOrGasDataFile.h"
using namespace std;



string ElectricityBillDataOperations::ConvertElectricityBillDataStructToStringLine
(
	const sElectricityOrGasBil& ElectricityBill,
	const string& StartMarker,
	const string& EndMarker,
	const string& Separator
)
{
	return ElectricityOrGasBillDataOperations::ConvertElectricityOrGasDataStructToStringLine
	(ElectricityBill, StartMarker, EndMarker, Separator);
}

sElectricityOrGasBil ElectricityBillDataOperations::ConvertElectricityBillStringLineToDataStruct
(
	string ElectricityBill,
	const string& StartMarker,
	const string& EndMarker,
	const string& Separator
)
{
	return ElectricityOrGasBillDataOperations::ConvertElectricityOrGasStringLineToDataStruct
	(ElectricityBill, StartMarker, EndMarker, Separator);
}


double ElectricityBillDataOperations::GetOldElectricityIndex
(
	const string& ClientID,
	const string& FileName
)
{
	return ElectricityOrGasBillDataOperations::GetOldElectricityOrGasIndex
	(ClientID, FileName, eOldIndexes::OldElectricityIndex);
}
