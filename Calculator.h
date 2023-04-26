#pragma once
#ifndef CALCULATOR_H

class Calculator {
public:
	Calculator();

	void SetInitialInvestment(double userInvestment);
	double GetInitialInvestment()const;

	void SetMonthlyDeposit(double userDeposit);
	double GetMonthlyDeposit()const;

	void SetInterestRate(double userInterest);
	double GetInterestRate()const;

	void SetNumberOfYears(int userYears);
	int GetNumberOfYears() const;

	void WithoutMonthly(double initialInvestment, double monthlyDeposit);
	void WithMonthly(double userInvestment, double userDeposit, double userInterest, int userYears);

	void DisplayMenu();

private:
	//initial variables
	double initialInvestment;
	double monthlyDeposit;
	double interestRate;
	int	   numberOfYears;
	//variables for calculating tables
	double monthlyInterest;
	double compoundedInterest;
	double openingSum;
	double monthlySum;
};

#endif // !CALCULATOR_H
