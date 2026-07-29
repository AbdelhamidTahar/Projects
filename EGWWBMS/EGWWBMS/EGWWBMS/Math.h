#pragma once
#include <iostream>
using namespace std;


namespace ConvertsMath
{
	double ConvertPercentageToDecimal(const double& Percentage);
}

namespace OperationsMath
{
	double Multiply(double firstNumber, double secondNumber);
}

namespace CheckMath
{
	bool IsNumberInRange(const int& Number, const int& From, const int& To);
}


