#include <iostream>
#include <string>
#include <vector>
#include "Input.h"
#include "TranchesData.h"
#include "GlobalDataFile.h"
#include "TrancheDataFile.h"
#include "TranchesDataFile.h"
using namespace std;

string TranchesDataOperations::convertTranchesDataStructToStringLine
(
	const sTranchesData& TranchesData,
	const string& StartMarker ,
	const string& EndMarker  ,
	const string& Separator 
)
{
	string TranchesDataLine = "";

	TranchesDataLine += StartMarker;

	TranchesDataLine += TranchesDataOperations::convertTranchesStructToStringLine(TranchesData.vTranches);
	TranchesDataLine += to_string(TranchesData.PrimaryTranchesTotalAmount) + Separator;
	TranchesDataLine += to_string(TranchesData.SecondaryTranchesTotalAmount) ;

	TranchesDataLine += EndMarker;


	return TranchesDataLine;
}


sTranchesData TranchesDataOperations::ConvertVectorsToTranchesDataStruct
 (const vector<sTranche>& vTranches, const vector<string> &vRemainingData)
{
	sTranchesData TranchesData;

	TranchesData.vTranches = vTranches;
	TranchesData.PrimaryTranchesTotalAmount = stod(vRemainingData[0]);
	TranchesData.SecondaryTranchesTotalAmount = stod(vRemainingData[1]);

	return TranchesData;
}

sTranchesData TranchesDataOperations::ConvertTranchesDataStringLineToDataStruct
(
	string TranchesDataString,
	const string& StartMarker,
	const string& EndMarker,
	const string& Separator
)
{
	sTranchesData TranchesData;
	vector<sTranche>vTranches;
	string Tranches = "";
	

	TranchesDataString = GlobalOperations::DeleteStartMarkerTAndEndMarker
	  (TranchesDataString, StartMarker, EndMarker);

	Tranches = GlobalOperations::GetTextFromStartMarkerToEndMarker
	  (TranchesDataString, "StartTranches", "EndTranches");

	vTranches = TranchesDataOperations::ConvertTranchesStringLineToStructs
	  (Tranches, "StartTranches", "EndTranches");

	TranchesDataString = GlobalOperations::DeleteTextFromStartMarkerToEndMarker
	(TranchesDataString, "StartTranches", "EndTranches");


	vector<string> vRemainingData;
	vRemainingData = InputOperations::SplitStringWithSeparator(TranchesDataString);

	TranchesData = ConvertVectorsToTranchesDataStruct(vTranches, vRemainingData);

	return TranchesData;
}