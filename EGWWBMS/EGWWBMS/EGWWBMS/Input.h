#pragma once
#include <iostream>
#include <vector>
using namespace std;

namespace Validations
{
	bool IsHasSymbol(const string& Input);
	bool IsHasDigit(const string& Input);
	bool IsHasChar(const string& Input);
	bool IsDecimalNumberValidat(const string& Input);
	bool IsIDValidat(const string& Input);

	
}

namespace Checks
{
	bool IsVectorOfStringIsEmpty(vector<string>& vStrings);
	bool IsStringEmpty(const string& Text);
}

namespace InputOperations
{
	vector<string> SplitStringIntoPartsUsingSeparator(string Input,const string& Separator = ".");
}

namespace Reads
{
	string ReadID(const string& Message);

	double ReadPositiveDecimalNumber(const string& Message);
}

namespace Messages
{
	void PrintErrorMessage(const string& ErrorMessage);
}
