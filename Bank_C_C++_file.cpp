#include <iostream>
#include "Bank_H_C++_file.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "STD_TYPES.h"
#include <conio.h>
#include <windows.h>
//#include <cstring.h>

const std::string ADMIN_USERNAME = "Admin";
const std::string ADMIN_PASSWORD = "1234";
long Cl_Accounts::Nxt_Accnt_No = 0;
Bank b;
Cl_Accounts acc;

/////////////////// System Functions ///////////////////////////////

void delay(u32 milli_seconds)
{
    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
void Wellcom()
{

    system("color 6");
    CLEAR_SCREEN();
    SetConsoleTitle(" Bank System | DIU");
    std::cout << " \n\n\n\n\n\t\t\t\t\t***************************************************";
    std::cout << "\n\t\t\t\t\t*                                                 *";
    std::cout << "\n\t\t\t\t\t*             Wellcom To Bank System              *";
    std::cout << "\n\t\t\t\t\t*                                                 *";
    std::cout << "\n\t\t\t\t\t***************************************************";
    std::cout << "\n\n\n\n\n\t\t\t\t\tPress any key to continue...... ";
    getch();
}
void exitTheSystem()
{

    CLEAR_SCREEN();
    std::cout << " \n\n\n\n\n\t\t\t\t\t***************************************************";
    std::cout << "\n\t\t\t\t\t*                                                 *";
    std::cout << "\n\t\t\t\t\t*         Thanks For Using Bank System            *";
    std::cout << "\n\t\t\t\t\t*                                                 *";
    std::cout << "\n\t\t\t\t\t***************************************************";

    delay(5000);
    CLEAR_SCREEN();
    exit(0);
}
void startTheSystem()
{
    CLEAR_SCREEN();
    u32 systemChoice;

    std::cout << "Choose from these options:\n\n\
           1-for Administrator mode.\n\
           2-for Client mode.\n\
           3-for Exit.\n\n";
    std::cout << "Enter your choice: ";
    std::cin >> systemChoice;
    switch (systemChoice)
    {
    case 1:
        CLEAR_SCREEN();
        Admin_Login();

        break;
    case 2:
        CLEAR_SCREEN();
        Client_Mode();

        break;
    case 3:
        CLEAR_SCREEN();
        exitTheSystem();

        break;
    default:
        CLEAR_SCREEN();
        std::cout << " \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ";
        std::cout << "\n\n\t\t\t\t\t     *      You entered invalid option     *";
        std::cout << "\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * *";

        delay(3000);
        CLEAR_SCREEN();
        startTheSystem();

        break;
    }
}

//////////////////// Admin Functions ///////////////////////////////

void Admin_Login()
{
    CLEAR_SCREEN();
    u32 choice;
    std::cout << "*********************************************************************                          \n";
    std::cout << "*                      Admin Mode                                   *                          \n";
    std::cout << "*********************************************************************                          \n";

    std::string adminUsername;

    std::cout << "Enter username please: ";
    std::cin >> adminUsername;

    std::cout << "\nEnter password please: ";
    // To make Password Invisible and predetermined with (ADMIN_PASSWORD_LENGTH) digits
    std::string adminPassword;

    std::cin >> adminPassword;

    if (ADMIN_USERNAME == adminUsername)
    {
        if (ADMIN_PASSWORD == adminPassword)
        {
            CLEAR_SCREEN();
            adminMode();
        }
        else
        {
            CLEAR_SCREEN();
            std::cout << " \n\n\n\n\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
            std::cout << "\n\t\t\t\t\t*      You Enter invalid password, please try again...      *";
            std::cout << "\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
            std::cout << std::endl
                      << "\n\nDo you want to continue?\n1-for Yes.\n2-for No.\n\nEnter your choice: ";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
                CLEAR_SCREEN();
                Admin_Login();
                break;
            case 2:
            default:
                CLEAR_SCREEN();
                startTheSystem();
                break;
            }
        }
    }
    else
    {
        CLEAR_SCREEN();
        std::cout << " \n\n\n\n\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
        std::cout << "\n\t\t\t\t\t*      You Enter invalid username , please try again...      *";
        std::cout << "\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ";
        std::cout << std::endl
                  << "\n\nDo you want to continue?\n1-for Yes.\n2-for No.\n\nEnter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            CLEAR_SCREEN();
            Admin_Login();
            break;
        case 2:
        default:
            CLEAR_SCREEN();
            startTheSystem();
            break;
        }
    }
}
void adminMode(void)
{
    CLEAR_SCREEN();
    u32 choice1, choice2;
    std::cout << "*********************************************************************                          \n";
    std::cout << "*                      Admin Mode                                   *                          \n";
    std::cout << "*********************************************************************                          \n";

    std::cout << "Choose from these options:\n\n\
           1-Create New Account.\n\
           2-Open Existing Account.\n\
           3-Show Accounts Info.\n\
           4-Main Menu.\n\
           5-Exit .\n\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice1;

    switch (choice1)
    {
    case 1:
        CLEAR_SCREEN();
        createNewAccount();
        break;
    case 2:
        CLEAR_SCREEN();
        openExistingAccount();
        break;
    case 3:
        CLEAR_SCREEN();
        // Show_Accounts_Info();
        b.ShowAllAccounts();
        break;
    case 4:
        CLEAR_SCREEN();
        startTheSystem();
        break;
    case 5:
        CLEAR_SCREEN();
        exitTheSystem();
        break;
    default:
        CLEAR_SCREEN();
        std::cout << " \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ";
        std::cout << "\n\n\t\t\t\t\t     *      You entered invalid option     *";
        std::cout << "\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * *";

        std::cout << "\n\nDo you want to continue?\n1-for Yes.\n2-for No.\n\nEnter your choice: ";
        std::cin >> choice2;
        switch (choice2)
        {
        case 1:
            CLEAR_SCREEN();
            adminMode();
            break;

        default:
            CLEAR_SCREEN();
            startTheSystem();
            break;
        }
        break;
    }
}
void createNewAccount(void)
{
    string fname, lname, Address;
    u32 Age;
    f64 national_ID;
    u32 blnced;
    std::cout << "*********************************************************************                          \n";
    std::cout << "*                      Admin Mode                                   *                          \n";
    std::cout << "*********************************************************************                          \n";

    std::cout << "Enter First Name: ";
    std::cin >> fname;
    std::cout << "Enter Last Name: ";
    std::cin >> lname;
    std::cout << "Enter Address: ";
    std::cin >> Address;
    std::cout << "Enter National_ID: ";
    std::cin >> national_ID;
    std::cout << "Enter Age: ";
    std::cin >> Age;
    std::cout << "Enter Initial Balance: ";
    std::cin >> blnced;

    acc = b.Cl_Open_Account(fname, lname, Address, Age, national_ID, blnced);
    CLEAR_SCREEN();

    std::cout << " \n\n\n\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * ";
    std::cout << "\n\t\t     *      Registration process is Done Successfully!     *";
    std::cout << "\n\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * *";

    delay(3000);
    CLEAR_SCREEN();
    adminMode();
    std::cout << acc;
}
void openExistingAccount(void)
{
    CLEAR_SCREEN();
    cout << "*********************************************************************                          \n";
    cout << "*                      Admin Mode                                   *                          \n";
    cout << "*********************************************************************                          \n";

    long Clinet_Account_ID;

    u32 ID_exists1 = 0, choice = 0;
    cout << "Enter client bank account ID please: ";
    cin >> Clinet_Account_ID;
    ID_exists1 = b.Check_Accountss(Clinet_Account_ID);
    if (ID_exists1)
    {

        CLEAR_SCREEN();

        Opration_ON_Client(Clinet_Account_ID);
    }
    else
    {
        CLEAR_SCREEN();
        cout << " \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ";
        cout << "\n\n\t\t\t\t\t     *        This ID doesn't exist         *";
        cout << "\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ";
        delay(3000);
        CLEAR_SCREEN();
        adminMode();
    }
}
void Admin_changeAccountStatus(long userID)
{
    u32 ChoiceStatus;

    CLEAR_SCREEN();
    std::cout << "Choose from these options to enter the bank account status:\n\n\
            1- Set Account to Active State.\n\
            2- Set Account to Restricted State.\n\
            3- Set Account to Closed. \n\n";

    std::cout << "Enter your choice: ";
    std::cin >> ChoiceStatus;
    switch (ChoiceStatus)
    {
    case 1:
        b.ChangeAccountStatus(userID, ACTIVE);
        CLEAR_SCREEN();
        std::cout << " \n\n\n\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
        std::cout << "\n\t\t\t\t\t*      Changing the account status is Done Successfully!      *";
        std::cout << "\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
        delay(3000);
        break;
    case 2:
        b.ChangeAccountStatus(userID, RESTRICTED);

        CLEAR_SCREEN();

        std::cout << " \n\n\n\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
        std::cout << "\n\t\t\t\t\t*      Changing the account status is Done Successfully!      *";
        std::cout << "\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
        delay(3000);
        break;
    case 3:
        b.ChangeAccountStatus(userID, CLOSED);
        CLEAR_SCREEN();

        std::cout << " \n\n\n\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
        std::cout << "\n\t\t\t\t\t*      Changing the account status is Done Successfully!      *";
        std::cout << "\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
        delay(3000);
        break;

    default:
        std::cout << " \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
        std::cout << "\n\n\t\t\t\t\t     *          You entered invalid account status...              *";
        std::cout << "\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
        delay(3000);
        break;
    }

    CLEAR_SCREEN();
}
void Opration_ON_Client(long ClinetID)
{
    u32 choice = 0;
    u32 amt = 0;
    CLEAR_SCREEN();

    cout << "*********************************************************************                          \n";
    cout << "*                    This Account State is ACTIVE                   *                          \n";
    cout << "*********************************************************************                          \n";

    cout << "Choose from these options:\n\n\
               1- Make Transaction.\n\
               2- Change Account Status.\n\
               3- Get Cash.\n\
               4- Deposit in Account.\n\
               5- Return to main menu.\n\n";

    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        Make_Transaction(ClinetID);

        adminMode();
        break;
    case 2:
        CLEAR_SCREEN();
        Admin_changeAccountStatus(ClinetID);
        adminMode();
        break;

    case 3:
        CLEAR_SCREEN();

        cout << "Enter the amount" << endl;
        cin >> amt;
        // Get_Cash(ClinetID);
        b.Withdraw(ClinetID, amt);
        adminMode();
        break;

    case 4:
        CLEAR_SCREEN();
        cout << "Enter the amount" << endl;
        cin >> amt;
        b.Deposit(ClinetID, amt);
        // Deposit_InAccount(ClinetID);
        adminMode();
        break;
    case 5:
        CLEAR_SCREEN();
        adminMode();
        break;
    default:
        CLEAR_SCREEN();
        cout << " \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ";
        cout << "\n\n\t\t\t\t\t     *      You entered invalid option      *";
        cout << "\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ";
        delay(3000);
        CLEAR_SCREEN();
        Opration_ON_Client(ClinetID);

        break;
    }
}
void Make_Transaction(long SenderID)
{
    CLEAR_SCREEN();
    u32 money, ID_exists2, Status, Check;
    long receiverID;

    std::cout << "please Enter the Bank Account ID you want to transfer the money to: ";
    std::cin >> receiverID;
    ID_exists2 = b.Check_Accountss(receiverID);

    if (ID_exists2)
    {
        Status = b.Check_Status(receiverID, ACTIVE);

        if (Status)
        {
            std::cout << "please Enter amount of money: ";
            std::cin >> money;
            Check = b.Check_Balance(SenderID, money);
            if (Check)
            {
                b.Deposit(receiverID, money);
                b.Withdraw(SenderID, money);

                CLEAR_SCREEN();

                std::cout << " \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * ";
                std::cout << "\n\n\t\t\t\t\t     *      Transaction process is Done Successfully!      *";
                std::cout << "\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * *";

                delay(3000);
                CLEAR_SCREEN();
            }
            else
            {
                CLEAR_SCREEN();
                std::cout << " \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
                std::cout << "\n\n\t\t\t\t\t     *      Operation failed because there is no sufficient money!       *";
                std::cout << "\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
                delay(3000);
                CLEAR_SCREEN();
            }
        }
        else
        {
            CLEAR_SCREEN();
            std::cout << " \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
            std::cout << "\n\n\t\t\t\t\t     *      Operation failed because the user isn't an active user!      *";
            std::cout << "\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
            delay(3000);
            CLEAR_SCREEN();
        }
    }
    else
    {
        std::cout << " \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ";
        std::cout << "\n\n\t\t\t\t\t     *      This ID doesn't exist...       *";
        std::cout << "\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * *";
        delay(3000);
        CLEAR_SCREEN();
    }
}

//////////////////// Client Functions ///////////////////////////////

void Client_Mode(void)
{
    long Clinet_AccountID;
    u32 Password, Status;
    u32 passwordCorrect;
    u32 choice, ID_exists1 = 0;
    CLEAR_SCREEN();
    std::cout << "*********************************************************************                          \n";
    std::cout << "*                        Clint Mode                                 *                          \n";
    std::cout << "*********************************************************************                          \n";

    std::cout << "Enter client bank account ID please: ";
    std::cin >> Clinet_AccountID;
    ID_exists1 = b.Check_Accountss(Clinet_AccountID);

    if (ID_exists1)
    {
        std::cout << "Enter your Password please: ";
        std::cin >> Password;
        passwordCorrect = b.Check_password(Clinet_AccountID, Password);
        if (passwordCorrect)
        {
            CLEAR_SCREEN();
            Status = b.Check_Status(Clinet_AccountID, ACTIVE);
            if (Status)
            {
                Clint_Menu(Clinet_AccountID);
            }
            else
            {
                CLEAR_SCREEN();

                std::cout << " \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ";
                std::cout << "\n\n\t\t\t\t\t     *   This Account State is INACTIVE    *";
                std::cout << "\n\n\t\t\t\t\t     *     please call customer service    *";
                std::cout << "\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * *";

                std::cout << "\nDo you want to continue ?\n1-for Main Menu.\n2-for Exit.\n\nEnter your choice:: ";
                std::cin >> choice;
                switch (choice)
                {
                case 1:
                    CLEAR_SCREEN();
                    startTheSystem();
                    break;
                case 2:
                    CLEAR_SCREEN();
                    exitTheSystem();
                    break;
                default:
                    CLEAR_SCREEN();

                    std::cout << " \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ";
                    std::cout << "\n\n\t\t\t\t\t     *      You entered invalid option      *";
                    std::cout << "\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ";
                    delay(3000);

                    CLEAR_SCREEN();
                    startTheSystem();

                    break;
                }
            }
        }
        else
        {

            CLEAR_SCREEN();
            std::cout << " \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ";
            std::cout << "\n\n\t\t\t\t\t     *     You entered invalid password    *";
            std::cout << "\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * *";

            delay(3000);
            CLEAR_SCREEN();
            startTheSystem();
        }
    }
    else
    {

        CLEAR_SCREEN();
        std::cout << " \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ";
        std::cout << "\n\n\t\t\t\t\t     *         This ID doesn't exist       *";
        std::cout << "\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * *";

        delay(3000);
        CLEAR_SCREEN();

        startTheSystem();
    }
}
void Clint_Menu(long Clinet_ID)
{
    u32 choice, amt = 0;
    CLEAR_SCREEN();
    std::cout << "*********************************************************************                          \n";
    std::cout << "*                    This Account State is ACTIVE                   *                          \n";
    std::cout << "*********************************************************************                          \n";

    std::cout << "Choose from these options:\n\n\
    1- Make Transaction.\n\
    2- Change Account Password.\n\
    3- Get Cash.\n\
    4- Deposit in Account.\n\
    5- Show current balance.\n\
    6- Return to main menu.\n\n";

    std::cout << "Enter your choice: ";
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        CLEAR_SCREEN();
        Make_Transaction(Clinet_ID);

        Clint_Menu(Clinet_ID);
        break;
    case 2:
        CLEAR_SCREEN();
        Chang_Pass(Clinet_ID);
        Clint_Menu(Clinet_ID);
        break;
    case 3:
        CLEAR_SCREEN();

        cout << "Enter the amount" << endl;
        cin >> amt;
        // Get_Cash(ClinetID);
        b.Withdraw(Clinet_ID, amt);
        Clint_Menu(Clinet_ID);
        break;
    case 4:
        CLEAR_SCREEN();
        cout << "Enter the amount" << endl;
        cin >> amt;
        b.Deposit(Clinet_ID, amt);
        // Deposit_InAccount(Clinet_ID);
        Clint_Menu(Clinet_ID);
        break;
    case 5:
        CLEAR_SCREEN();
        Balance_Inquiry(Clinet_ID);
        Clint_Menu(Clinet_ID);
        break;
    case 6:
        CLEAR_SCREEN();
        startTheSystem();
        break;
    default:
        CLEAR_SCREEN();
        std::cout << " \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ";
        std::cout << "\n\n\t\t\t\t\t     *      You entered invalid option      *";
        std::cout << "\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ";
        delay(3000);
        Clint_Menu(Clinet_ID);
        break;
    }
}
void Chang_Pass(long bankAccountId)
{
    CLEAR_SCREEN();
    u32 oldPass, newPass, pswrd;
    std::cout << "Enter the old Password first: ";
    std::cin >> oldPass;
    pswrd = b.Check_password(bankAccountId, oldPass);
    if (pswrd)
    {
        std::cout << "Now, enter the new Password: ";
        std::cin >> newPass;

        b.Change_Password(bankAccountId, newPass);
        CLEAR_SCREEN();
        std::cout << " \n\n\n\n\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *";
        std::cout << "\n\n\t\t\t\t\t*      Changing the Password is Done Successfully!    *";
        std::cout << "\n\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *";

        delay(3000);
    }
    else
    {
        CLEAR_SCREEN();
        std::cout << " \n\n\n\n\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *";
        std::cout << "\n\n\t\t\t\t\t*      You entered the old password is invalid        *";
        std::cout << "\n\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *";
        delay(3000);
    }
}
void Balance_Inquiry(long Clinet_ID)
{
    u32 acc;
    CLEAR_SCREEN();
    std::cout << "********************************************************                          \n";
    std::cout << "*                    Balance Inquiry                   *                          \n";
    std::cout << "********************************************************                          \n";
    // acc=b.Cl_Balance_Enquiry(Clinet_ID);
    std::cout << "\n\tCurrent Balance        =     \n"
              << acc;

    u32 choice;
    std::cout << "\n\nDo you want to continue?\n1-for To Back \n2-for Go To Main Menue\n\nEnter your choice: ";
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        CLEAR_SCREEN();
        Clint_Menu(Clinet_ID);
        break;
    case 2:
        CLEAR_SCREEN();
        startTheSystem();
        break;
    default:
        CLEAR_SCREEN();
        startTheSystem();
        break;
    }
}

///////////////////////////////////////////////////////////////////////

Cl_Accounts::Cl_Accounts(std::string fname, std::string lname, std::string Address, u32 Age, f64 National_id, u32 client_balance)
{
    Nxt_Accnt_No++;
    Accnt_No = Nxt_Accnt_No;
    client_fname = fname;
    client_lname = lname;
    fullAddress = Address;
    client_age = Age;
    national_ID = National_id;
    this->client_balance = client_balance;
    accountStatus = ACTIVE;
    password;
}

void Cl_Accounts::Deposit(u32 amt)
{
    client_balance += amt;
    cout << "*********************************************************************                          \n";
    cout << "*        Deposit In Account is Done Successfully!                   *                          \n";
    cout << "*********************************************************************                          \n";
    delay(3000);
    CLEAR_SCREEN();
}

void Cl_Accounts::ChangeAccountStatus(AccountStatus_t statuss)
{
    accountStatus = statuss;
}

void Cl_Accounts::ChangePassword(u32 pass)
{
    password = pass;
}

void Cl_Accounts::Withdraw(u32 amt)
{
    if (client_balance >= amt)
    {

        client_balance -= amt;
        cout << "*********************************************************************                          \n";
        cout << "*        Getting the cash is Done Successfully!                     *                          \n";
        cout << "*********************************************************************                          \n";
        delay(3000);
        CLEAR_SCREEN();
    }
    else
    {
        cout << "*********************************************************************                          \n";
        cout << "*     Operation failed because there is no sufficient mone          *                          \n";
        cout << "*********************************************************************                          \n";
        delay(3000);
        CLEAR_SCREEN();
    }
}

void Cl_Accounts::setLstAccntNo(long Accnt_No)
{
    Nxt_Accnt_No = Accnt_No;
}

long Cl_Accounts::getLstAccntNo()
{
    return Nxt_Accnt_No;
}

ofstream &operator<<(ofstream &ofs, Cl_Accounts &acc)
{
    ofs << acc.Accnt_No << endl;
    ofs << acc.client_fname << endl;
    ofs << acc.client_lname << endl;
    ofs << acc.fullAddress << endl;
    ofs << acc.client_age << endl;
    ofs << acc.national_ID << endl;
    ofs << acc.client_balance << endl;
    ofs << acc.accountStatus << endl;
    ofs << acc.password << endl;
    ofs << "*********************************" << endl;

    return ofs;
}

ifstream &operator>>(ifstream &ifs, Cl_Accounts &acc)
{
    ifs >> acc.Accnt_No;
    ifs >> acc.client_fname;
    ifs >> acc.client_lname;
    ifs >> acc.fullAddress;
    ifs >> acc.client_age;
    ifs >> acc.national_ID;
    ifs >> acc.client_balance;
    // ifs >> acc.accountStatus;
    ifs >> acc.password;
    return ifs;
}

ostream &operator<<(ostream &os, Cl_Accounts &acc)
{
    os << "Account Number:" << acc.getAccNo() << endl;
    os << "First Name:" << acc.getFName() << endl;
    os << "Last Name:" << acc.getLName() << endl;
    os << "Address:" << acc.getAddress() << endl;
    os << "Age:" << acc.getAge() << endl;
    os << "National_ID:" << acc.getNational_id() << endl;
    os << "Balance:" << acc.getBlnce() << endl;
    os << "Account Status:" << acc.getStatus() << endl;
    os << "Password:" << acc.getPassword() << endl;
    os << "***********************************" << endl;

    return os;
}

////////////////////////////////////////////////////////////////////////

Bank::Bank()
{
    Cl_Accounts acnt;
    ifstream infile;
    infile.open("DataBase.text");
    if (!infile)
    {
        // cout<<"Error in Opening! File Not Found!!"<<endl;
        return;
    }
    while (!infile.eof())
    {
        infile >> acnt;
        accounts_cl.insert(pair<long, Cl_Accounts>(acnt.getAccNo(), acnt));
    }
    Cl_Accounts::setLstAccntNo(acnt.getAccNo());
    infile.close();
}

Cl_Accounts Bank::Cl_Open_Account(std::string fname, std::string lname, std::string Address, u32 Age, f64 National_id, u32 client_balance)
{

    ofstream outfile;
    Cl_Accounts acnt(fname, lname, Address, Age, National_id, client_balance);
    accounts_cl.insert(pair<long, Cl_Accounts>(acnt.getAccNo(), acnt));
    outfile.open("DataBase.text", ios::trunc);
    map<long, Cl_Accounts>::iterator itr;
    for (itr = accounts_cl.begin(); itr != accounts_cl.end(); itr++)
    {
        outfile << itr->second;
    }
    outfile.close();
    return acnt;
}

Cl_Accounts Bank::Cl_Balance_Enquiry(long Accnt_No)
{
    map<long, Cl_Accounts>::iterator itr = accounts_cl.find(Accnt_No);
    itr->second.getBlnce();
    return itr->second;
}

Cl_Accounts Bank::Deposit(long Accnt_No, u32 amt)
{
    map<long, Cl_Accounts>::iterator itr = accounts_cl.find(Accnt_No);
    itr->second.Deposit(amt);
    return itr->second;
}

Cl_Accounts Bank::Withdraw(long Accnt_No, u32 amt)
{
    map<long, Cl_Accounts>::iterator itr = accounts_cl.find(Accnt_No);
    itr->second.Withdraw(amt);
    return itr->second;
}

Cl_Accounts Bank::ChangeAccountStatus(long Account_no, AccountStatus_t stat)
{
    map<long, Cl_Accounts>::iterator itr = accounts_cl.find(Account_no);
    itr->second.ChangeAccountStatus(stat);
    return itr->second;
}

Cl_Accounts Bank::Change_Password(long Account_no, u32 passw)
{
    map<long, Cl_Accounts>::iterator itr = accounts_cl.find(Account_no);
    itr->second.ChangePassword(passw);
    return itr->second;
}

u32 Bank::Check_Balance(long Account_no, u32 monyy)
{
    u32 exist = 0;
    map<long, Cl_Accounts>::iterator itr = accounts_cl.find(Account_no);
    if ((itr->second.getBlnce()) >= monyy)
    {
        exist = 1;
    }
    return exist;
}

u32 Bank::Check_Accountss(long RecivID)
{
    u32 exist = 0;
    map<long, Cl_Accounts>::iterator itr;
    for (itr = accounts_cl.begin(); itr != accounts_cl.end(); itr++)
    {
        if ((itr->second.getAccNo()) == RecivID)
        {
            exist = 1;
            break;
        }
    }
    return exist;
}

u32 Bank::Check_password(long RecivID, u32 passworrd)
{
    u32 exist = 0;
    map<long, Cl_Accounts>::iterator itr;
    for (itr = accounts_cl.begin(); itr != accounts_cl.end(); itr++)
    {
        if (((itr->second.getAccNo()) == RecivID) && ((itr->second.getPassword()) == passworrd))
        {
            exist = 1;
            break;
        }
    }
    return exist;
}

u32 Bank::Check_Status(long RecivID, AccountStatus_t stat)
{
    u32 exist = 0;
    map<long, Cl_Accounts>::iterator itr;
    for (itr = accounts_cl.begin(); itr != accounts_cl.end(); itr++)
    {
        if (((itr->second.getAccNo()) == RecivID) && ((itr->second.getStatus()) == stat))
        {
            exist = 1;
            break;
        }
    }
    return exist;
}

void Bank::ShowAllAccounts()
{
    map<long, Cl_Accounts>::iterator itr;
    for (itr = accounts_cl.begin(); itr != accounts_cl.end(); itr++)
    {
        if ((itr->first) > 0)
        {
            cout << itr->first << endl
                 << itr->second << endl;
        }
        else
        {
            cout << "\n\n****************************************************************\n";
            cout << "*                     No account found                         *\n";
            cout << "****************************************************************\n";
        }
    }
    u32 choice;
    cout << "\n\nDo you want to continue?\n1-for To Back \n2-for Go To Main Menue\n\nEnter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        CLEAR_SCREEN();
        adminMode();
        break;

    default:
        CLEAR_SCREEN();
        startTheSystem();
        break;
    }
}

Bank::~Bank()
{
    ofstream outfile;
    outfile.open("DataBase.text", ios::trunc);
    map<long, Cl_Accounts>::iterator itr;
    for (itr = accounts_cl.begin(); itr != accounts_cl.end(); itr++)
    {
        outfile << itr->second;
    }
    outfile.close();
}
