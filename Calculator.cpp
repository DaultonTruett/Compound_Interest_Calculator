#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#include "Calculator.h"

//default constructor
Calculator::Calculator() {
	initialInvestment = 0.0;
	monthlyDeposit = 0.0;
	interestRate = 0.0;
	numberOfYears = 0.0;
}

// setters and getters for calculator
void Calculator::SetInitialInvestment(double userInvestment) {
	initialInvestment = userInvestment;
}

double Calculator::GetInitialInvestment()const {
	return initialInvestment;
}

void Calculator::SetMonthlyDeposit(double userDeposit) {
	monthlyDeposit = userDeposit;
}

double Calculator::GetMonthlyDeposit()const {
	return monthlyDeposit;
}

void Calculator::SetInterestRate(double userInterest) {
	interestRate = userInterest;
}

double Calculator::GetInterestRate()const {
	return interestRate;
}

void Calculator::SetNumberOfYears(int userYears) {
	numberOfYears = userYears;
}

int Calculator::GetNumberOfYears() const {
	return numberOfYears;
}

//Calculate interest for user input WITHOUT monthly deposits
void Calculator::WithoutMonthly(double userInvestment, double userInterest) {

	cout << "-----Balance and interest without additional monthly deposits----" << endl;
	cout << "=================================================================" << endl;
	cout << "Month          Month end Balance          Month end interest balance" << endl;
	cout << "=================================================================" << endl;
	cout << endl;

	monthlyInterest = (userInvestment) * ((userInterest / 100.0) / 12.0);
	openingSum = userInvestment + monthlyInterest;

	for (int i = 1; i <= GetNumberOfYears() * 12; ++i) {

		if (i == 1) {
			cout << i << setw(25) << "$"<< openingSum << setw(25) << "$" << monthlyInterest << endl;
		}

		else if (i == 2) {
			compoundedInterest = monthlyInterest + monthlyInterest;
			monthlySum = openingSum + compoundedInterest;
			cout << i << setw(25) << "$" << monthlySum << setw(25) << "$" << compoundedInterest << endl;
		}

		else {
			compoundedInterest = compoundedInterest + monthlyInterest;
			monthlySum = openingSum + compoundedInterest;
			cout << i << setw(25) << "$" << monthlySum << setw(25) << "$" << compoundedInterest << endl;
		}
	}
}

//Calculate interest for user input WITH monthly deposits
void Calculator::WithMonthly(double userInvestment, double userDeposit, double userInterest, int userYears) {
	cout << "------Balance and interest with additional monthly deposits------" << endl;
	cout << "=================================================================" << endl;
	cout << "Month          Month end Balance          Month end interest balance" << endl;
	cout << "=================================================================" << endl;
	cout << endl;


	monthlyInterest = (userInvestment + userDeposit) * (userInterest / 100.0 / 12.0);
	openingSum = userInvestment + userDeposit + monthlyInterest;

	for (int j = 1; j <= GetNumberOfYears() * 12; ++j) {

		if (j == 1) {
			cout << j << setw(25) << "$" << openingSum << setw(25) << "$" << monthlyInterest << endl;
		}

		else if (j == 2) {
			compoundedInterest = monthlyInterest + monthlyInterest;
			monthlySum = openingSum + userDeposit + compoundedInterest;
			cout << j << setw(25) << "$" << monthlySum << setw(25) << "$" << compoundedInterest << endl;

		}
		else {
			compoundedInterest = compoundedInterest + monthlyInterest;
			monthlySum = monthlySum + userDeposit + compoundedInterest;
			cout << j << setw(25) << "$" << monthlySum << setw(25) << "$" << compoundedInterest << endl;

		}
	}
}

//Display input data
void Calculator::DisplayMenu() {
	cout << endl;
	cout << endl;
	cout << "*************************************" << endl;
	cout << "************ Data Input *************" << endl;
	cout << endl;
	cout << "Investment Amount: $" << GetInitialInvestment() << endl;
	cout << "Monthly Deposit: $" << GetMonthlyDeposit() << endl;
	cout << "Anual Interest: " << GetInterestRate() << "%" << endl;
	cout << "Number of years: " << GetNumberOfYears() << endl;
	cout << "Press 'y' or 'Y' to continue..." << endl;
	cout << "If you would like to exit the appplication: Press any other key" << endl;
}