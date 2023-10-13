#include "DepositInfo.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Takes in client input and error checks input is positive
void DepositInfoi::setInitDepositInfo() {
   
   cout << "Enter initial investment amount: $";
   cin >> m_openAmount;
   if (m_openAmount < 0) {
      while (m_openAmount < 0) {
         cout << "Input error. Amount must be 0 or higher." << endl;
         cout << "Enter initial investment amount: $";
         cin >> m_openAmount;
      }
   }

   cout << endl << "Enter monthly deposit amount: $";
   cin >> m_monthlyDeposit;
   if (m_monthlyDeposit < 0) {
      while (m_monthlyDeposit < 0) {
         cout << "Input error. Amount must be 0 or higher." << endl;
         cout << "Enter initial investment amount: $";
         cin >> m_monthlyDeposit;
      }
   }

   cout << endl << "Enter annual interest rate: ";
   cin >> m_annualInterestRate;
   if (m_annualInterestRate < 0) {
      while (m_annualInterestRate < 0) {
         cout << "Input error. Amount must be 0 or higher." << endl;
         cout << "Enter initial investment amount: $";
         cin >> m_annualInterestRate;
      }
   }

   cout << endl << "Enter number of years to invest: ";
   cin >> m_yearsToInvest;
   if (m_yearsToInvest < 0) {
      while (m_yearsToInvest < 0) {
         cout << "Input error. Amount must be 0 or higher." << endl;
         cout << "Enter initial investment amount: $";
         cin >> m_yearsToInvest;
      }
   }
   cout << endl;
}

// Calculates interest accrued without a monthly deposit
void DepositInfoi::getInterestAccrued(double t_initAmount, double t_percentRate) {
   m_totalAmount = t_initAmount;
   m_interestAccrued = m_totalAmount * ((t_percentRate / 100) / 12);
}

// Calculates interest accrued with a monthly deposit
void DepositInfoi::getInterestAccrued(double t_initAmount, double t_depositMonthly, double t_percentRate) {
   m_totalAmount = t_initAmount + t_depositMonthly;
   m_interestAccrued = m_totalAmount * ((t_percentRate / 100) / 12);
}

// Calculates monthly closing amount
void DepositInfoi::getClosingAmount(double t_amountTotal, double t_accruedinterest) {
   m_closeAmount = m_totalAmount + m_interestAccrued;
}

// Prints a chart of clients money with accrued interest without monthly deposits
void DepositInfoi::printNoDepositChart() {
     
   getInterestAccrued(m_openAmount, m_annualInterestRate);
   getClosingAmount(m_totalAmount, m_interestAccrued);
   
   topNoDepositChart();
   topOfChart();

   m_yearNum = 1;
   for (unsigned i = 1; i <= (m_yearsToInvest * 12); ++i) {
      if (i % 12 == 0) {         
         cout << fixed << setprecision(2);
         cout << setfill(' ');
         cout << setw(6) << right << m_yearNum << setw(6) << right << '|';
         cout << setw(16) << right << m_closeAmount << setw(11) << right << '|';
         cout << setw(23) << right << (m_interestAccrued * 12) << endl;      
         
         ++m_yearNum;
      }

      m_updateOpenAmount = m_closeAmount;
      getInterestAccrued(m_updateOpenAmount, m_annualInterestRate);
      getClosingAmount(m_totalAmount, m_interestAccrued);
   }

   bottomOfChart();
   cout << endl;
}

// Prints a chart of clients money with accrued interest with monthly depsoits
void DepositInfoi::printDepositChart() {
   
   getInterestAccrued(m_openAmount, m_monthlyDeposit, m_annualInterestRate);
   getClosingAmount(m_totalAmount, m_interestAccrued);

   topDepositChart();
   topOfChart();
   
   m_yearNum = 1;
   for (unsigned i = 1; i <= (m_yearsToInvest * 12); ++i) {
      if (i % 12 == 0) {
         cout << setfill(' ');
         cout << setw(6) << right << m_yearNum << setw(6) << right << '|';
         cout << setw(16) << right << m_closeAmount << setw(11) << right << '|';
         cout << setw(23) << right << (m_interestAccrued * 12) << endl;
         
         ++m_yearNum;
      }
     
      m_openAmount = m_closeAmount;
      getInterestAccrued(m_openAmount, m_monthlyDeposit, m_annualInterestRate);
      getClosingAmount(m_totalAmount, m_interestAccrued);
   
   }
   bottomOfChart();
   cout << endl;

   // Allows for client to change input info
   cout << "Would you like to change your investment inputs? (Y/N)" << endl;
   cin >> m_resetInputs;
   if ((m_resetInputs == 'y') || (m_resetInputs == 'Y')) {
      setInitDepositInfo();
      printNoDepositChart();
      printDepositChart();
   }

   else {
      cout << "Goodbye";
      return;
   }

}

// Prints top of deposit chart without monthly deposits
void DepositInfoi::topNoDepositChart() {
   cout << "Year end balance and interest accrued without monthly deposits" << endl;
}

// Prints top of deposit chart with monthly deposits
void DepositInfoi::topDepositChart() {
   cout << "Year end balance and interest accrued with monthly deposits" << endl;
}

// Prints top of both charts
void DepositInfoi::topOfChart() {
   
   cout << setfill(' ');
   cout << setw(11) << left << "| Year" << '|';
   cout << setw(21) << right << "Year end balance" << setw(6) << right << '|';
   cout << setw(23) << right << "Interest Accrued |" << endl;

   for (unsigned i = 0; i < 62; ++i){
      cout << '_';
   }
   cout << endl;
   cout << endl;
}

// Prints bottom of both charts
void DepositInfoi::bottomOfChart() {
   for (unsigned i = 0; i < 62; ++i){
      cout << '_';
   }
   cout << endl;
   cout << endl;
}
