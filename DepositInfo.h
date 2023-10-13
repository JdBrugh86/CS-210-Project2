/* Jonathan Brugh
 * CS-210 Programming languages
 * Eric Gregori
 * 09/30/2023
 * Takes in client input and outputs deposit info in two charts, one with and one without monthly deposits.
 */

#ifndef DEPOSITINFO_H
#define DEPOSITINFO_H

class DepositInfoi {
   public:
      void setInitDepositInfo();
      void printDepositChart();
      void printNoDepositChart();
     
   private:
      void topNoDepositChart();
      void topDepositChart();
      void topOfChart();
      void bottomOfChart();
      void getClosingAmount(double t_amountTotal, double t_accruedinterest);
      void getInterestAccrued(double t_initAmount, double t_percentRate);
      void getInterestAccrued(double t_initAmount, double t_depositMonthly, double t_percentRate);
      double m_annualInterestRate;
      double m_interestAccrued;
      double m_openAmount;
      double m_updateOpenAmount;
      double m_monthlyDeposit;
      double m_closeAmount;
      double m_totalAmount;
      int m_yearsToInvest;
      int m_yearNum;
      char m_resetInputs;
};

#endif
