#include <iostream>
#include "ElectricityDataFile.h"
#include "GlobalElectricityAndGasDataFile.h"
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
