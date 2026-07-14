#include <iostream>
#include <string>
#include <cctype>
#include "Input.h"
using namespace std;

bool Validations::IsHasSymbol(const string& Input)
{
	for (const char& Character : Input)
	{
		if (ispunct(Character))
			return true;
	}
	return false;

}

bool Validations::IsHasDigit(const string& Input)
{
	for (const char& Character : Input)
	{
		if (isdigit(Character))
			return true;
	}
	return false;

}

bool Validations::IsHasChar(const string& Input)
{
	for (const char& Character : Input)
	{
		if (isalpha(Character))
			return true;
	}
	return false;

}

bool Validations::IsDecimalNumberValidat(const string& Input)
{
	if (Validations::IsHasChar(Input))
	{
		return false;
	}

	vector<string>StringIntoParts;
	StringIntoParts = InputOperations::SplitStringIntoTwoParts(Input);

	//not found dot (.).
	if (StringIntoParts.empty())
	{
		return !IsHasSymbol(Input);
	}

	if (IsHasSymbol(StringIntoParts[0]) || IsHasSymbol(StringIntoParts[1]))
		return false;

	return true;
}

bool Validations::IsIDValidat(const string& ID)
{
	return !IsHasSymbol(ID);
}

string Reads::ReadID(const string& Message)
{
	string ID = "";
	cout << Message;
	cin >> ID;

	if (!Validations::IsIDValidat(ID))
	{
		Messages::PrintErrorMessage
		("Invalid input. Symbols are not allowed. Please enter a ID and try again.\n");
		return ReadID(Message);
	}
	return ID;
}

bool Checks::IsVectorOfStringIsEmpty(vector<string>& vStrings)
{
	return vStrings.empty();
}

bool Checks::IsStringEmpty(const string& Text)
{
	return (Text.length() == 0 ? true : false);
}

void Messages::PrintErrorMessage(const string& ErrorMessage)
{
	cout << ErrorMessage;
}

vector<string> InputOperations::SplitStringIntoTwoParts(string Input,const string & Separator)
{
	vector<string> vPartsOfInput;
	short Pos = 0;

	if ((Pos = Input.find(Separator)) != std::string::npos)
	{
		while ((Pos = Input.find(Separator)) != std::string::npos)
		{
			vPartsOfInput.push_back(Input.substr(0, Pos));
			Input = Input.erase(0, Pos + Separator.length());
			vPartsOfInput.push_back(Input);
		}
	}

	return vPartsOfInput;
}

double Reads::ReadPositiveDecimalNumber(const string& Message)
{
	string DecimalNumber = "";
	cout << Message;
	cin >> DecimalNumber;

	if (Checks::IsStringEmpty(DecimalNumber))
	{
		Messages::PrintErrorMessage
		("Invalid input. Null are not allowed. Please enter a decimal number and try again.\n");
		return ReadPositiveDecimalNumber(Message);
	}

	if (!Validations::IsDecimalNumberValidat(DecimalNumber))
	{
		Messages::PrintErrorMessage
		("Invalid input. Symbols and Chars are not allowed. Please enter a decimal number and try again.\n");
		return ReadPositiveDecimalNumber(Message);
	}

	if (stod(DecimalNumber) < 0)
	{
		Messages::PrintErrorMessage
		("Invalid input. The value cannot be less than zero. Please try again.\n");
		return ReadPositiveDecimalNumber(Message);
	}

	return stod(DecimalNumber);
}

bool Validations::IsFullNameValidat(const string& FullName)
{
	return !(IsHasSymbol(FullName) || IsHasDigit(FullName));
}

string Reads::ReadFullName(const string& Message)
{
	string FullName = "";
	cout << "Please enter your full name: ";
	cin >> FullName;

	if (!Validations::IsFullNameValidat(FullName))
	{
		Messages::PrintErrorMessage
		("Invalid input. Symbols and Digits are not allowed. Please enter a Fuul Name and try again.\n");
		FullName = ReadFullName(Message);
	}
	return FullName;
}

vector<string> InputOperations::SplitStringWithSeparator(string Text, const string& Separator )
{
	vector<string> vString;
	string RemainingString = "";
	int SeparatorPos = 0;

	while ((SeparatorPos = Text.find(Separator)) != std::string::npos)
	{
		RemainingString = Text.substr(0, SeparatorPos);
		vString.push_back(RemainingString);
		Text.erase(0, SeparatorPos + Separator.length());
	}

	if (!Checks::IsStringEmpty(Text))
		vString.push_back(Text);

	return vString;
}
