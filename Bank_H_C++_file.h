#ifndef BANKK_H_INCLUDED
#define BANKK_H_INCLUDED

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "STD_TYPES.h"
#include <conio.h>
#include <windows.h>
// using namespace std;
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>
#define CLEAR_SCREEN() system("cls")

using namespace std;
#define MIN_BALANCE 100
typedef enum
{
    ACTIVE = 1,
    RESTRICTED,
    CLOSED
} AccountStatus_t;

void Wellcom();
void startTheSystem();
void exitTheSystem();
void delay(u32 milli_seconds);

void Admin_Login();
void adminMode(void);
void createNewAccount();
void openExistingAccount();
void Opration_ON_Client(long ClinetID);
void Admin_changeAccountStatus(long userID);
void Make_Transaction(long SenderID);

void Client_Mode(void);
void Clint_Menu(long Clinet_ID);
void Chang_Pass(long bankAccountId);
void Balance_Inquiry(long Clinet_ID);

#if 1

class deficient_funds
{
};
class Cl_Accounts
{
private:
    std::string client_fname;
    std::string client_lname;
    std::string fullAddress;
    u32 client_age;
    f64 national_ID;
    u32 client_balance;
    AccountStatus_t accountStatus; // Default set to ACTIVE
    u32 password;
    long Accnt_No;

    static long Nxt_Accnt_No;

public:
    Cl_Accounts() : Accnt_No(0),
                    client_fname(""),
                    client_lname(""),
                    fullAddress(""),
                    accountStatus(ACTIVE),
                    client_age(0),
                    client_balance(0),
                    national_ID(0)
    {
    }

    Cl_Accounts(std::string fname, std::string lname, std::string Address, u32 Age, f64 National_id, u32 client_balance);

    long getAccNo() { return Accnt_No; }

    std::string getFName() { return client_fname; }
    std::string getLName() { return client_lname; }
    std::string getAddress() { return fullAddress; }
    u32 getAge() { return client_age; }
    f64 getNational_id() { return national_ID; }
    u32 getBlnce() { return client_balance; }
    u32 getPassword() { return password; }
    AccountStatus_t getStatus() { return accountStatus; }

    void Deposit(u32 amount);
    void Withdraw(u32 amount);
    void ChangeAccountStatus(AccountStatus_t statuss);
    void ChangePassword(u32 pass);
    static void setLstAccntNo(long Accnt_No);
    static long getLstAccntNo();
    friend ofstream &operator<<(ofstream &ofs, Cl_Accounts &acc);
    friend ifstream &operator>>(ifstream &ifs, Cl_Accounts &acc);
    friend ostream &operator<<(ostream &os, Cl_Accounts &acc);
};

///////////////////////////////////////////////////////////////////////////
class Bank
{
private:
    map<long, Cl_Accounts> accounts_cl;

public:
    Bank();
    Cl_Accounts Cl_Open_Account(std::string fname, std::string lname, std::string Address, u32 Age, f64 National_id, u32 client_balance);
    Cl_Accounts Cl_Balance_Enquiry(long Account_no);
    Cl_Accounts Deposit(long Account_no, u32 amt);
    Cl_Accounts Withdraw(long Account_no, u32 amt);

    Cl_Accounts ChangeAccountStatus(long Account_no, AccountStatus_t stat);
    u32 Check_Accountss(long RecivID);

    Cl_Accounts Change_Password(long Account_no, u32 passw);

    u32 Check_Balance(long Account_no, u32 monyy);

    u32 Check_password(long RecivID, u32 passworrd);

    u32 Check_Status(long RecivID, AccountStatus_t stat);
     
    void ShowAllAccounts();
    ~Bank();
};

#endif

#endif // BANK_INTERFACE_H_INCLUDED