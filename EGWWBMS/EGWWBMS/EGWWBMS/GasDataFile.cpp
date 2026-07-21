#include "GasDataFile.h"
#include "GlobalElectricityOrGasDataFile.h"


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


double GasBillDataOperations::GetOldGasIndex
(
	const string& ClientID,
	const string& FileName
)
{
	return ElectricityOrGasBillDataOperations::GetOldElectricityOrGasIndex
	(ClientID, FileName, eOldIndexes::OldGasIndex);
}