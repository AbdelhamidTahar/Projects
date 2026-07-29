#include "Math.h"

double ConvertsMath::ConvertPercentageToDecimal(const double & Percentage)
{
	return (Percentage / 100);
}

double OperationsMath::Multiply(double firstNumber, double secondNumber)
{
	return (firstNumber * secondNumber);
}

bool CheckMath::IsNumberInRange(const int& Number, const int& From, const int& To)
{
	return (Number >= From && Number <= To);
}
