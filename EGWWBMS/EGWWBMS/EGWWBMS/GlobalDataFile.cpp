#include "GlobalDataFile.h"
#include <iostream>
#include <string>

using namespace std;


string GlobalOperations::GetTextFromStartMarkerToEndMarker
(
	string Text, const string& StartMarker , const string& EndMarker 
)
{
	int PosStartMarker = Text.find(StartMarker);
	int PosEndMarker = Text.find(EndMarker);
	PosEndMarker += EndMarker.length() - 1;
	Text = Text.substr(PosStartMarker, (PosEndMarker + 1) - PosStartMarker);

	return Text;
}


string GlobalOperations::DeleteTextFromStartMarkerToEndMarker
(
	string Text, const string& StartMarker , const string& EndMarker 
)
{
	int PosStartMarker = Text.find(StartMarker);
	int PosEndMarker = Text.find(EndMarker);
	PosEndMarker += EndMarker.length() - 1;
	Text = Text.erase(PosStartMarker, (PosEndMarker + 1) - PosStartMarker);

	return Text;
}

string GlobalOperations::DeleteMarker
(
	string Text, const string& Marker 
)
{
	int PosStartMarker = Text.find(Marker);
	Text = Text.erase(PosStartMarker, Marker.length());

	return Text;
}


string GlobalOperations::DeleteStartMarkerTAndEndMarker
(
	string Text, const string& StartMarker , const string& EndMarker 
)
{
	
	Text = DeleteMarker(Text, StartMarker);
	Text = DeleteMarker(Text, EndMarker);

	return Text;
}

