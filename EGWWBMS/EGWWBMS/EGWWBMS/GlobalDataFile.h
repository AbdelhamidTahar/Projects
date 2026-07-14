#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace GlobalOperations
{
	string GetTextFromStartMarkerToEndMarker
	(
		 string Text, const string& StartMarker = "",const string& EndMarker = ""
	);

	string DeleteTextFromStartMarkerToEndMarker
	(
		 string Text, const string& StartMarker = "", const string& EndMarker = ""
	);

	string DeleteMarker
	(
		string Text, const string& Marker =""
	);

	string DeleteStartMarkerTAndEndMarker
	(
		string Text, const string& StartMarker = "", const string& EndMarker = ""
	);



}