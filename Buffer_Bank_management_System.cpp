#include<iostream>
#include<string>
#include<limits>
#include<cstdlib>
#include<time.h>
#include<algorithm>
#include<stdlib.h>
#include<conio.h>

using namespace std;
// Creating Node
class Node;
Node *head=NULL;
class Node
{
private:
    string Name;
    string middleName;
    string surname;                     // for storing name of account holder
    string gender;                    // for storing account holder's gender
    string adhaar_no;
    string account_type;              // for storing account type i.e saving account or current account
    long int account_number;          // for storing account number
    int pin;                          // for storing account holder's pin number
    float balance;                      // for storing balance
    string phone_number;
    Node *left,*right;

public:
    void create_acccount();
    void add_account();
    void Delete_Account();
    void ShowListOfAllAccounts();
    void depositAmount();
    void searchAccount();
    void atmService();
    void withdrawAmount();
    void EditAccountInformation();
    void account_Transaction();
    void show_account(Node*);
    void loan();
};

void Node:: create_acccount()
{
    cout<<endl<<endl<<endl<<"********************************************************* Create Account *********************************************************"<<endl<<endl;
    cout<<"         Enter your name : ";
    cin>>Name;
    cout<<"\n";
    transform(Name.begin(),Name.end(),Name.begin(),::toupper);

    cout<<"         Enter your middle name : "<<" ";
    cin>>middleName;
    transform(middleName.begin(),middleName.end(),middleName.begin(),::toupper);
    cout<<endl;

    cout<<"         Enter your surname : "<<" ";
    cin>>surname;
    transform(surname.begin(),surname.end(),surname.begin(),::toupper);
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<endl;

    cout<<"         Enter your Gender (Male/Female/other) : "<<" ";
    getline(cin,gender);
    transform(gender.begin(),gender.end(),gender.begin(),::tolower);
    while(gender!="male" && gender!="female" && gender!="other")
    {
        cout<<"         Invalid information , enter your gender again : "<<" ";
        getline(cin,gender);
        transform(gender.begin(),gender.end(),gender.begin(),::tolower);
    }
    cout<<endl;

    cout<<"         Enter your Adhaar Number : "<<" ";
    getline(cin,adhaar_no);
    while(adhaar_no.length()!=12)
    {
        cout<<"         Invalid Adhaar Number , Enter your adhaar number again : "<<" ";
        getline(cin,adhaar_no);
    }
    cout<<endl;

    cout<<"         Enter your phone Number : "<<" ";
    cout<<"+91 ";
    cin>>phone_number;
    while(phone_number.length()!=10)
    {
        cout<<"         Invalid phone Number , Enter your phone number again : "<<" ";
        cout<<"+91 ";
        cin>>phone_number;
    }
    cout<<endl;

    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"         Enter a type of account you want to create (saving or current): "<<" ";
    getline(cin,account_type);
    transform(account_type.begin(),account_type.end(),account_type.begin(),::tolower);
    while(account_type!="saving" && account_type!="current")
    {
        cout<<"         Invalid account type , enter your account type again : "<<" ";
        getline(cin,account_type);
        transform(account_type.begin(),account_type.end(),account_type.begin(),::tolower);
    }
    cout<<endl;

    cout<<"         Enter a balance (minimum 500 amount for saving account and minimum 1000 amount for current account) : "<<" ";
    cin>>balance;
    if(account_type=="saving")
    {
        while(balance<500)
        {
            cout<<"         Balance should be more than 500 , deposit  minimum cash 500 : "<<" ";
            cin>>balance;
        }
    }
    else
    {
        while(balance<1000)
        {
            cout<<"         Balance should be more than 1000 , deposit  minimum cash 1000 : "<<" ";
            cin>>balance;
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<endl;

    srand(time(0));
    long int randMax=70000000,randMin=60000000;
    account_number=rand() % (randMax-randMin)+randMin;
    cout<<"         Your account number : "<<account_number<<endl;
    cout<<endl;

    srand(time(0));
    int pinMax=9999,pinMin=1000;
    pin=rand() % (pinMax-pinMin)+pinMin;
    cout<<"         Your Pin : "<<pin<<endl;
    cout<<endl;

    add_account();
}

void Node:: add_account()
{
    Node *n=new Node();
    n->right=NULL;
    n->left=NULL;
    n->Name=Name;
    n->middleName=middleName;
    n->surname=surname;
    n->account_number=account_number;
    n->account_type=account_type;
    n->pin=pin;
    n->adhaar_no=adhaar_no;
    n->balance=balance;
    n->gender=gender;
    n->phone_number=phone_number;
    Node *temp=head;
    if(temp==NULL)
    {
        head=n;
    }
    else
    {
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        temp->right=n;
        n->left=temp;
    }
    cout<<"   Account created successfully !!"<<endl;
    cout<<endl;
}

void Node:: ShowListOfAllAccounts()
{
    cout<<endl<<endl<<endl<<"********************************************************* List Of All Accounts *********************************************************"<<endl<<endl;
    Node* temp=head;
    cout<<"         ======================================================================================================================================================================================"<<endl;
    cout<<"            "<<"Name "<<"         "<<"Middle Name "<<"          "<<"Surname"<<"          "<<"Account Number"<<"          "<<"Account Type"<<"          "<<"Balance"<<"          "<<"Gender"<<"         "<<"Adhaar Number"<<"        "<<"Phone Number"<<"        "<<endl;
    cout<<"         ======================================================================================================================================================================================="<<endl;
    cout<<endl;
    while(temp!=NULL)
    {
        cout<<"            "<<temp->Name<<"          "<<temp->middleName<<"             "<<temp->surname<<"             "<<temp->account_number<<"              "<<temp->account_type<<"                "<<temp->balance<<"            "<<temp->gender<<"          "<<temp->adhaar_no<<"        "<<temp->phone_number<<endl;
        cout<<"         ____________________________________________________________________________________________________________________________________________________________________________________________"<<endl;
        cout<<endl;
        temp=temp->right;
    }
}

void Node:: Delete_Account()
{
    cout<<endl<<endl<<endl<<"********************************************************* Delete Account *********************************************************"<<endl<<endl;
    Node* temp=head;
    Node* temp1;
    int c=0;
    int val;
    cout<<"         Enter account number to delete your account : ";
    cin>>val;
    cout<<endl;
    if(val==temp->account_number)
    {
        if(temp->right==NULL)
        {
            head=NULL;
            delete(temp);
            cout<<"         Account deleted successfully !!"<<endl;
            cout<<endl;
            return;
        }
        head=temp->right;
        temp->right->left=NULL;
        temp->right=NULL;
        delete(temp);
        cout<<"         Account deleted successfully !!"<<endl;
        cout<<endl;
        return;
    }
    else
    {

        while(temp!=NULL)
        {
            if(temp->right==NULL)
            {
                if(val==temp->account_number)
                {
                    temp1=temp->left;
                    temp1->right=NULL;
                    temp->left=NULL;
                    delete temp;
                    cout<<"         Account deleted successfully !!"<<endl;
                    cout<<endl;
                    return ;
                }
            }
            if(val==temp->account_number)
            {
                temp1=temp->left;
                temp1->right=temp->right;
                temp->right->left=temp1;
                temp->left=NULL;
                temp->right=NULL;
                delete temp;
                cout<<"         Account deleted successfully !! "<<endl;
                cout<<endl;
                return;
            }
            temp=temp->right;
        }
    }
    cout<<"         Invalid account Number "<<endl;
}

void Node:: show_account(Node *temp)
{
    cout<<"         ==========================================================================================================================================================================="<<endl;
    cout<<"            "<<"Name "<<"         "<<"Middle Name "<<"          "<<"Surname"<<"          "<<"Account Number"<<"          "<<"Account Type"<<"          "<<"Balance"<<"          "<<"Gender"<<"         "<<"Adhaar Number"<<"          "<<"Phone Number"<< endl;
    cout<<"         ==========================================================================================================================================================================="<<endl;
    cout<<endl;
    cout<<"            "<<temp->Name<<"          "<<temp->middleName<<"             "<<temp->surname<<"             "<<temp->account_number<<"              "<<temp->account_type<<"                "<<temp->balance<<"            "<<temp->gender<<"          "<<temp->adhaar_no<<"         "<<temp->phone_number<<endl;
    cout<<"         ___________________________________________________________________________________________________________________________________________________________________________"<<endl;
    cout<<endl<<endl;
}

void Node::depositAmount()
{
    cout<<endl<<endl<<endl<<"********************************************************* Deposit Amount *********************************************************"<<endl<<endl;
    Node* temp=head;
    long int account_number1;
    int pin1,amount;
    cout<<"         Enter your account number : "<<" ";
    cin>>account_number1;
    cout<<endl;
    while(temp!=NULL)
    {
        if(account_number1==temp->account_number)
        {
            cout<<"         Account Found !! "<<endl;
            cout<<"         Enter your pin : "<<" ";
            cin>>pin1;
            cout<<endl;
            if(pin1==temp->pin)
            {
                cout<<"         How much amount do you want to deposit : "<<" ";
                cin>>amount;
                cout<<endl;
                cout<<"                                                         Status BEFORE Deposit Amount in ACCOUNT                                             "<<endl<<endl;
                show_account(temp);
                temp->balance=(temp->balance) + amount;
                cout<<"                                                         Status AFTER Deposit Amount in ACCOUNT                                             "<<endl<<endl;
                show_account(temp);
//cout<<"New balance:"<<temp->balance<<endl ;
                cout<<"         Amount "<<amount<<" has been Deposited in account number "<<temp->account_number<<" ."<<endl<<endl;
                cout<<"         Successfully deposited !! "<<endl<<endl;
                return;
            }
        }
        temp=temp->right;
    }
    cout<<"         Invalid account information , please try again !! "<<endl;
    cout<<endl;
}
void Node :: withdrawAmount()
{
    cout<<endl<<endl<<endl<<"********************************************************* Withdraw Amount *********************************************************"<<endl<<endl;
    Node* temp=head;
    long int account_number1;
    int pin1,amount;

    cout<<"         Enter your account number : "<<" ";
    cin>>account_number1;
    cout<<endl;
    while (temp!=NULL)
    {
        if(account_number1==temp->account_number)
        {
            cout<<"         Account found!!"<<endl;
            cout<<"         Enter your pin number : "<<" ";
            cin>>pin1;
            cout<<endl;
            if(pin1==temp->pin)
            {
                cout<<"         Enter the amount to be withdraw : "<<" ";
                cin>>amount;
                cout<<endl;
                cout<<"                                                         Status BEFORE Withdraw Amount from ACCOUNT                                             "<<endl<<endl;
                show_account(temp);
                temp->balance=(temp->balance)-amount;

                if(temp-> balance>=500 && temp->account_type=="saving")
                {
                    cout<<"                                                         Status AFTER Withdraw Amount from ACCOUNT                                             "<<endl<<endl;
                    show_account(temp);
                    cout<<"         Amount "<<amount<<" has been withdraw from account number "<<temp->account_number<<" ."<<endl<<endl;
                    //cout<<"New Balance : "<<temp->balance<<endl;
                    cout<<"         Amount withdraw succesfully!!"<<endl;
                    return;
                }
                else if(temp-> balance>=1000 && temp->account_type=="current")
                {
                    cout<<"                                                         Status AFTER Withdraw Amount from ACCOUNT                                             "<<endl<<endl;
                    show_account(temp);
                    cout<<"         Amount "<<amount<<" has been withdraw from account number "<<temp->account_number<<" ."<<endl<<endl;
                    //cout<<"New Balance : "<<temp->balance<<endl;
                    cout<<"         Amount withdraw successfully!!"<<endl;
                    return;
                }

                else
                {
                    cout<<"         You can not withdraw this much amount , Withdrawal of amount failed ."<<endl;
                    temp->balance=(temp->balance)+amount;
                    return;
                }
            }
            else
            {
                cout<<"         Invalid pin number , try again "<<endl;
                return;
            }
        }
        temp=temp->right;
    }

    cout<<"         Account does not exit !! "<<endl<<endl;
}


void Node::searchAccount()
{
    cout<<endl<<endl<<endl<<"********************************************************* Search Account *********************************************************"<<endl<<endl;
    Node *temp=head;
    long int account_number1;
    cout<<"         Enter your account number : "<<" ";
    cin>>account_number1;
    cout<<endl;
    while(temp!=NULL)
    {
        if(account_number1==temp->account_number)
        {
            cout<<"         Account found successfully !! "<<endl<<endl;
            cout<<"         ================================================================================================================================================================================"<<endl;
            cout<<"            "<<"Name "<<"         "<<"Middle Name "<<"          "<<"Surname"<<"          "<<"Account Number"<<"          "<<"Account Type"<<"          "<<"Balance"<<"          "<<"Gender"<<"         "<<"Adhaar Number"<<"        "<<"Phone Number"<<"         "<<endl;
            cout<<"         ================================================================================================================================================================================"<<endl;
            cout<<endl;
            cout<<"            "<<temp->Name<<"          "<<temp->middleName<<"             "<<temp->surname<<"             "<<temp->account_number<<"              "<<temp->account_type<<"                "<<temp->balance<<"            "<<temp->gender<<"          "<<temp->adhaar_no<<"         "<<temp->phone_number<<endl<<endl;
            cout<<"         ________________________________________________________________________________________________________________________________________________________________________________"<<endl;
            return ;
        }
        temp=temp->right ;
    }
    cout<<"         Invalid account number , please try again !! "<<endl<<endl;
}
void Node::EditAccountInformation()
{
    cout<<endl<<endl<<endl<<"********************************************************* Edit Account Information *********************************************************"<<endl<<endl;
    Node *temp=head;
    long int account_number1;
    int pin1;
    cout<<"         Enter your account number to edit information : ";
    cin>>account_number1;
    cout<<endl;
    while(temp!=NULL)
    {
        if(account_number1==temp->account_number)
        {
            cout<<"         Enter your pin number : "<<" ";
            cin>>pin1;
            cout<<endl;
            if(pin1==temp->pin)
            {
                cout<<"         Enter your name : ";
                cin>>temp->Name;
                cout<<"\n";
                transform(temp->Name.begin(),temp->Name.end(),temp->Name.begin(),::toupper);

                cout<<"         Enter your middle name : "<<" ";
                cin>>temp->middleName;
                transform(temp->middleName.begin(),temp->middleName.end(),temp->middleName.begin(),::toupper);
                cout<<endl;

                cout<<"         Enter your surname : "<<" ";
                cin>>temp->surname;
                transform(temp->surname.begin(),temp->surname.end(),temp->surname.begin(),::toupper);
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<endl;

                cout<<"         Enter your Gender (Male/Female/other) : "<<" ";
                getline(cin,temp->gender);
                transform(temp->gender.begin(),temp->gender.end(),temp->gender.begin(),::tolower);
                while(temp->gender!="male" && temp->gender!="female" && temp->gender!="other")
                {
                    cout<<"         Invalid information , enter your gender again : "<<" ";
                    getline(cin,temp->gender);
                    transform(temp->gender.begin(),temp->gender.end(),temp->gender.begin(),::tolower);
                }
                cout<<endl;

                cout<<"         Enter your Adhaar Number : "<<" ";
                getline(cin,temp->adhaar_no);
                while(temp->adhaar_no.length()!=12)
                {
                    cout<<"         Invalid Adhaar Number , Enter your adhaar number again : "<<" ";
                    getline(cin,temp->adhaar_no);
                }
                cout<<endl;

                cout<<"         Enter your phone Number : "<<" ";
                cout<<"+91 ";
                cin>>temp->phone_number;
                while(temp->phone_number.length()!=10)
                {
                    cout<<"         Invalid Adhaar Number , Enter your phone number again : "<<" ";
                    cout<<"+91 ";
                    cin>>temp->phone_number;
                }
                cout<<endl;

                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"         Enter a type of account you want to create (saving or current): "<<" ";
                getline(cin,temp->account_type);
                transform(temp->account_type.begin(),temp->account_type.end(),temp->account_type.begin(),::tolower);
                while(temp->account_type!="saving" && temp->account_type!="current")
                {
                    cout<<"         Invalid account type , enter your account type again : "<<" ";
                    getline(cin,temp->account_type);
                    transform(temp->account_type.begin(),temp->account_type.end(),temp->account_type.begin(),::tolower);
                }
                cout<<endl;
                cout<<"         Account information edited successfully !! "<<endl;
                return;
            }
            else
            {
                cout<<"         Invalid pin number "<<endl;
            }
        }
        temp=temp->right;
    }
    cout<<"         Account does not exit "<<endl;
}
void Node::atmService()
{
    Node* temp=head,n1;
    int choice,pin_no,amount;
    cout<<endl<<endl<<endl<<"*********************************************** ATM Service ***********************************************"<<endl<<endl;

    cout<<"         Enter your pin : "<<" ";
    cin>>pin_no;
    cout<<endl;

    while(temp!=NULL)
    {
        if(pin_no==temp->pin)
        {
            cout<<"               _______________________________"<<endl;
            cout<<"              |                               |"<<endl;
            cout<<"              |     1.Deposit                 |"<<endl;
            cout<<"              |     2.Withdrawal              |"<<endl;
            cout<<"              |     3.Check current balance   |"<<endl;
            cout<<"              |     4.Cancel                  |"<<endl;
            cout<<"              |                               |"<<endl;
            cout<<"              |_______________________________|"<<endl<<endl;
            cout<<"         Enter the choice : "<<" ";
            cin>>choice;
            cout<<endl;

            if(choice==1)
            {
                cout<<"         How much amount do you want to deposit : "<<" ";
                cin>>amount;
                cout<<endl;
                temp->balance=(temp->balance) + amount;
                cout<<"         New balance:"<<temp->balance<<endl<<endl ;
                cout<<"         Successfully deposited !! "<<endl<<endl;
                getch();
                return;
            }
            else if(choice==2)
            {
                cout<<"         Enter the amount to be withdraw : "<<" ";
                cin>>amount;
                cout<<endl;
                temp->balance=(temp->balance)-amount;
                if(temp-> balance>=500 && temp->account_type=="saving")
                {
                    cout<<"         New Balance : "<<temp->balance<<endl<<endl;
                    cout<<"         Amount withdraw successfully!!"<<endl;
                    getch();
                    return;
                }
                else if(temp-> balance>=1000 && temp->account_type=="current")
                {
                    cout<<"         New Balance : "<<temp->balance<<endl<<endl;
                    cout<<"         Amount withdraw successfully!!"<<endl;
                    getch();
                    return;
                }
                else
                {

                    cout<<endl<<"         You can not withdraw this much amount , Withdrawal of amount failed"<<endl;
                    temp->balance=(temp->balance)+amount;
                    getch();
                    return;
                }
            }
            else if(choice==3)
            {
                cout<<"         Current Balance : "<<temp->balance<<endl;
                getch();
                return ;
            }
            else if(choice==4)
            {
                return ;
            }
            else
            {
                cout<<"         Invalid choice "<<endl;
                getch();
                return;
            }
        }
        temp=temp->right;
    }
    cout<<"         Invalid Pin , try again ! "<<endl;
    getch();
}

void Node:: account_Transaction()
{
    cout<<endl<<endl<<endl<<"********************************************************* Amount Transaction *********************************************************"<<endl<<endl;
    long int account_number1,account_number2;
    int pin1,pin2,amount;
    cout<<"         Enter your account number : "<<" ";
    cin>>account_number1;
    cout<<endl;
    Node *temp=head;
    Node *temp2=head;
    while(temp!=nullptr)
    {
        if(account_number1==temp->account_number)
        {
            cout<<"         In which account You want to transfer your money : "<<" ";
            cin>>account_number2;
            cout<<endl;
            while(temp2!=nullptr)
            {
                if(account_number2==temp2->account_number)
                {
                    cout<<"         Enter Your pin number : "<<" ";
                    cin>>pin1;
                    cout<<endl;
                    if(pin1==temp->pin)
                    {
                        cout<<"         How much amount do you want to transfer : "<<" ";
                        cin>>amount;
                        cout<<endl;
                        if(temp->account_type=="saving" && temp->balance<500)
                        {
                            cout<<"         You can't transfer money , your balance is "<<temp->balance<<endl<<endl;
                            return ;
                        }
                        if(temp->account_type=="current" && temp->balance<1000)
                        {
                            cout<<"         You can't transfer money , your balance is "<<temp->balance<<endl<<endl;
                            return ;
                        }
                        temp->balance=(temp->balance) - amount;
                        if(temp->balance < 1000 && temp->account_type=="current")
                        {
                            cout<<"         Transaction Failed !!"<<endl<<endl;
                            temp->balance=(temp->balance) + amount;
                            return;
                        }
                        if(temp->balance < 500 && temp->account_type=="saving")
                        {
                            cout<<"         Transaction Failed !!"<<endl<<endl;
                            temp->balance=(temp->balance) + amount;
                            return;

                        }
                        temp2->balance=(temp2->balance) + amount;
                        cout<<"         Your New balance:"<<temp->balance<<endl<<endl;
                        cout<<"         Transferred Money Successfully !! "<<endl<<endl;
                        return;

                    }
                    cout<<"         Invalid pin number , try again "<<endl<<endl;
                    return;
                }
                temp2=temp2->right;
            }
        }
        temp=temp->right;
    }
    cout<<"         Invalid Account Information , try again "<<endl<<endl;
    return;

}

void Node :: loan()
{
    cout<<endl<<endl<<endl<<"********************************************************* Loan Service *********************************************************"<<endl<<endl;
    Node *temp=head;
    long int account_number1;
    cout<<"         Enter your account number : "<<" ";
    cin>>account_number1;
    cout<<endl;
    while(temp!=NULL)
    {
        if(account_number1==temp->account_number)
        {
            float rate,r,loan_rate;
            int count=0;
            float temp3 =temp->balance;
            float loan;
            cout<<"         Enter the loan amount Rs. : ";
            cin>>loan;
            cout<<endl;
            cout<<"         Enter the loan interest rate ( % ) : ";
            cin>>loan_rate;
            cout<<endl;
            loan=loan+((loan*loan_rate)/100);
            float x=loan;
            cout<<"         Total amount has to be paid (loan with rate % of "<<loan_rate<<" on it )"<<" is : "<<loan<<endl;
            if((temp3-loan)<=500)
            {
                cout<<"         Amount deduction can not be possible ! "<<endl;
                return;
            }
            cout<<"         Enter the rate at which amount will be deducted per month ( % ) : ";
            cin>>rate;
            cout<<endl;
            r=(loan*rate)/100;
            while(loan>0)
            {

                loan=loan-r;
                if(loan<r)
                {
                    count++;
                    cout<<endl<<"         Amount deducted in month "<<count<<endl;
                    {
                        if(loan>0)
                        {
                            cout<<"         Loan amount remaining after successfully deduction in month "<<count<<" is : Rs. "<<loan<<endl;
                        }

                        else
                        {
                            cout<<"         Loan amount remaining after successfully deduction in month "<<count<<" is : Rs. "<<"0"<<endl;
                        }
                    }
                }
                else
                {
                    count++;
                    cout<<endl<<"         Amount deducted in month "<<count<<endl;
                    cout<<"         Loan amount remaining after successfully deduction in month "<<count<<" is : Rs. "<<loan<<endl;
                }
            }
            cout<<endl<<"         You have paid off Rs. "<<x<<" in "<<count<<" months "<<endl;
            return;
        }
        temp=temp->right;
    }
    cout<<"         Account does not exit !! Try again later "<<endl<<endl;
}

int main__Menu()
{
    int ch1;
    cout<<endl<<endl;
    cout<<"                           ************************************ MAIN MENU *************************************"<<endl;
    cout<<"                           ***                                                                              ***"<<endl;
    cout<<"                           ***                             Press 1 for Customer Panel                       ***"<<endl;
    cout<<"                           ***                             Press 2 for Staff Panel                          ***"<<endl;
    cout<<"                           ***                             Press 3 for ATM Service                          ***"<<endl;
    cout<<"                           ***                             Press 4 for Exit                                 ***"<<endl;
    cout<<"                           ***                                                                              ***"<<endl;
    cout<<"                           ************************************************************************************"<<endl<<endl;
    cout<<"         Enter your choice : ";
    cin>>ch1;
    return ch1;
}

int menu1()
{
    int choice,opt;
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                 ****************************** Customer Panel ******************************"<<endl;
    cout<<"                                 ***                                                                      ***"<<endl;
    cout<<"                                 ***                        Press 1 to Create Account                     ***"<<endl;
    cout<<"                                 ***                        Press 2 to Delete account                     ***"<<endl;
    cout<<"                                 ***                        Press 3 to Search account                     ***"<<endl;
    cout<<"                                 ***                        Press 4 to Edit account information           ***"<<endl;
    cout<<"                                 ***                        press 5 to go back to main menu               ***"<<endl;
    cout<<"                                 ***                                                                      ***"<<endl;
    cout<<"                                 ****************************************************************************"<<endl<<endl;
    cout<<"         Enter an option : "<<" ";
    cin>>choice;
    cout<<endl;
    return choice;
}

int menu2()
{
    int ch2;
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                 ****************************** Staff Panel ******************************"<<endl;
    cout<<"                                 ***                                                                   ***"<<endl;
    cout<<"                                 ***                 Press 1 to Show list of all accounts              ***"<<endl;
    cout<<"                                 ***                 Press 2 to Deposit Amount                         ***"<<endl;
    cout<<"                                 ***                 Press 3 to Withdraw Amount                        ***"<<endl;
    cout<<"                                 ***                 Press 4 to Transfer money to another account      ***"<<endl;
    cout<<"                                 ***                 Press 5 to Use Loan Service                       ***"<<endl;
    cout<<"                                 ***                 Press 6 to go back to main menu                   ***"<<endl;
    cout<<"                                 ***                                                                   ***"<<endl;
    cout<<"                                 *************************************************************************"<<endl<<endl;
    cout<<"         Enter an option : ";
    cin>>ch2;
    return ch2;
}

int main()
{
    Node n1;
    int ch;
    cout<<endl<<endl<<endl<<endl<<endl<<"                                                             WELCOME TO OUR BANK"<<endl<<endl;

jump:
    while(1)
    {
        switch(main__Menu())
        {
        case 1 :
        {
            system("CLS");
            while(1)
            {
                system("CLS");
                switch(menu1())
                {
                case 1 :
                    system("CLS");
                    n1.create_acccount();
                    getch();
                    system("CLS");
                    break;
                case 2 :
                    system("CLS");
                    n1.Delete_Account();
                    getch();
                    system("CLS");
                    break;
                case 3 :
                    system("CLS");
                    n1.searchAccount();
                    getch();
                    system("CLS");
                    break;
                case 4 :
                    system("CLS");
                    n1.EditAccountInformation();
                    getch();
                    system("CLS");
                    break;
                case 5 :
                    system("CLS");
                    goto jump;
                    break;
                default:
                    cout<<"         Invalid  choice , Try again "<<endl;
                    getch();
                    break;
                }
            }
        }
        break;

        case 2 :
        {
            system("CLS");
            while(1)
            {
                system("CLS");
                switch(menu2())
                {
                case 1 :
                    system("CLS");
                    n1.ShowListOfAllAccounts();
                    getch();
                    system("CLS");
                    break;

                case 2 :
                    system("CLS");
                    n1.depositAmount();
                    getch();
                    system("CLS");
                    break;

                case 3 :
                    system("CLS");
                    n1.withdrawAmount();
                    getch();
                    system("CLS");
                    break;

                case 4 :
                    system("CLS");
                    n1.account_Transaction();
                    getch();
                    system("CLS");
                    break;

                case 5 :
                    system("CLS");
                    n1.loan();
                    getch();
                    system("CLS");
                    break;

                case 6 :
                    system("CLS");
                    goto jump;
                    break;

                default:
                    cout<<"         Invalid  choice , Try again "<<endl;
                    getch();
                    break;
                }
            }
        }
        break;

        case 3 :
        {
            system("CLS");
            n1.atmService();
            system("CLS");
            goto jump;
        }
        break;
        case 4 :
        {
            cout<<endl<<"                  Thank You for using our bank service !! "<<endl<<endl;
            cout<<"                               press any key to exit "<<endl;
            getch();
            exit(0);
        }
        break;

        default :
            cout<<"         Invalid Option"<<endl<<"         Please try again"<<endl;
            getch();
            system("CLS");
            goto jump;
            break;

        }

    }
    return 0;
}
