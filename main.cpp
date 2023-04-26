#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

#include "Calculator.h"


int main() {
	//create calculator object
	Calculator userCalculator;

	//input variables from user
	double userInvestment;
	double userDeposit;
	double userInterest;
	int userYears;
	char menuChoice;
	
	//set cout display
	cout << fixed;
	cout << setprecision(2);
	cout << setw(15);

	//recieve initial user input and pass into setters
	cout << "Enter an initial investment amount: " << endl;
	cin >> userInvestment;

	// input validation
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a valid number\n";
		cin >> userInvestment;
	}
	userCalculator.SetInitialInvestment(userInvestment);


	cout << "Enter a monthly deposit amount: " << endl;
	cin >> userDeposit;
	// input validation
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a valid number\n";
		cin >> userDeposit;
	}
	userCalculator.SetMonthlyDeposit(userDeposit);	

	cout << "Enter an annual interest rate: " << endl;
	cin >> userInterest;
	// input validation
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a valid number\n";
		cin >> userInterest;
	}
	userCalculator.SetInterestRate(userInterest);

	cout << "Enter desired number of years: " << endl;
	cin >> userYears;
	// input validation
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "Enter a valid number\n";
		cin >> userYears;
	}
	userCalculator.SetNumberOfYears(userYears);

	//call menu and determine whether to proceed to calculator
	userCalculator.DisplayMenu();
	cin >> menuChoice;


	//input validation to determine whether or not to proceed
		if ((menuChoice == 'y') || (menuChoice == 'Y')) {
			cout << endl;
			cout << endl;

			userCalculator.WithoutMonthly(userCalculator.GetInitialInvestment(), userCalculator.GetInterestRate());

			cout << endl;
			cout << endl;

			userCalculator.WithMonthly(userCalculator.GetInitialInvestment(), userCalculator.GetMonthlyDeposit(), userCalculator.GetInterestRate(), userCalculator.GetNumberOfYears());

		}
		else{
			cout << "Thank you";
			cout << endl;
			menuChoice = false;;
		}

	return 0;
}