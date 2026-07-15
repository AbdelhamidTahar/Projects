#include "GasDataFile.h"
#include "GlobalElectricityAndGasDataFile.h"


string GasBillDataOperations::ConvertGasBillDataStructToStringLine
(
	const sElectricityOrGasBil& GasBil,
	const string& StartMarker ,
	const string& EndMarker,
	const string& Separator 
)
{
	return ElectricityOrGasBillDataOperations::ConvertElectricityOrGasDataStructToStringLine
	(GasBil, StartMarker, EndMarker, Separator);
}

sElectricityOrGasBil GasBillDataOperations::ConvertGasBillStringLineToDataStruct
(
	string GasBil,
	const string& StartMarker,
	const string& EndMarker,
	const string& Separator
)
{
	return ElectricityOrGasBillDataOperations::ConvertElectricityOrGasStringLineToDataStruct
	 (GasBil, StartMarker, EndMarker, Separator);
}