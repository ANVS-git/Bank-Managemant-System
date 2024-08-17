/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


//Online Banking System Project 
//using classes, vectors, switch case, dowhile loop
#include <bits/stdc++.h>

using namespace std;


class BankAccount{
    public: 
     string Name; 
     int AccountNumber; 
     double Balance;
     
     BankAccount(string s,int ac,double bal){
         Name=s; 
         AccountNumber=ac; 
         Balance=bal; 
     }
     
     string getName(){
         return Name; 
     }
     int getAccNum(){
         return AccountNumber; 
     }
     double getBalance(){
         return Balance; 
     }
     
     void Deposit(double amount){
         Balance=Balance+amount; 
     }
     
     void Withdraw(double amount){
         if(amount<=Balance){
             Balance=Balance-amount; 
             cout<<"Amount Withdrawn Successfully....."<<endl<<endl; ; 
         }
         else {
             cout<<"Insufficient Balance..."<<endl<<endl; 
         }
     }
     
     void Account_Details(){
         cout<<"Name: "<< Name<<" "; 
         cout<<"Account number: "<<AccountNumber<<" "; 
         cout<<"Balance: "<<Balance <<endl; 
     }
}; 

class BankManagement  {
    private: 
      vector <BankAccount> accounts; 
    public: 
       void AddAccount(string s,int ac,double bal){
           accounts.push_back(BankAccount(s,ac,bal)); 
       }
       void Viewallaccounts(){
           cout<<endl; 
           cout<<"----- All Account Holders -----"<<endl<<endl; 
           if(accounts.empty()){
               cout<<"No Accounts."<<endl; 
           }
           for(int i=0;i<accounts.size();i++){
               cout<<"Name: " <<accounts[i].getName()<<endl<<"Account Number: "<<accounts[i].getAccNum()<<endl<<" Balance: "<<accounts[i].getBalance()<<endl<<endl; 
           }
           cout<<endl; 
       }
       void Account_Details(int accountnumber){
           for(int i=0;i<accounts.size();i++){
               if(accounts[i].AccountNumber==accountnumber){
                   cout<<"Account Details"<<endl; 
                   accounts[i].Account_Details(); 
               }
           }
           cout<<endl; 
       }
       BankAccount* findAccount(int accountnumber){
            for(int i=0;i<accounts.size();i++){
                if(accounts[i].getAccNum()==accountnumber){
                    return &accounts[i]; 
                }
            }
            return NULL; 
       }
};



int main()
{
     BankAccount b("vasu",12345,5000); 
     b.Account_Details(); 
     cout<<endl<<endl; 
     BankManagement MYBANK; 
     string choice;
     int option;
     do{
     system("cls");    
     cout<<"********* Welcome to MYBANK *********"<<endl<<endl;
     cout<<"Options. "<<endl; 
     cout<<"1.Create Account. "<<endl; 
     cout<<"2.Deposit"<<endl; 
     cout<<"3.Withdraw"<<endl; 
     cout<<"4.View all accounts."<<endl;
     cout<<"5.Account details"<<endl; 
     cout<<"6.Exit"<<endl<<endl; 
     cout<<"Enter the option: "; 
     cin >>option;
     switch(option){
         case 1:{
             string name; 
             int accnum; 
             double balance; 
             cout<<"Enter the Name: "; 
             cin >>name;
           //  getline(cin,name);
             cout<<"Enter the Account Number: ";
             cin >>accnum; 
             cout<<"Enter the Initial Balance: ";
             cin >>balance;
             MYBANK.AddAccount(name,accnum,balance);
             cout<<"Account Created Successfully."<<endl<<endl;
         }break;
         case 2:{
             int accountnum;
             cout<<"Enter the Account Number in which money is to be deposited: "; 
             cin >>accountnum; 
             BankAccount* account=MYBANK.findAccount(accountnum); 
             if(account!=NULL){
                 double amount;
                 cout<<"Enter the amount to be deposited: "; 
                 cin >>amount; 
                 account->Deposit(amount); 
                 cout<<"Amount deposited successfully."<<endl; 
             }
             else {
                 cout<<"Account Not Found."<<endl; 
             }
         }break; 
         case 3:{
             int accountnum; 
             double amount; 
             cout<<"Enter the Account number from which money is to be withdrawn: "; 
             cin >>accountnum; 
             BankAccount* account=MYBANK.findAccount(accountnum); 
             if(account!=NULL){
                 cout<<"Enter the amount to be withdrawn: "; 
                 cin >>amount; 
                 account->Withdraw(amount); 
             }
             else {
                 cout<<"Account Not Found."<<endl; 
             }
         }break; 
         case 4:{
             MYBANK.Viewallaccounts(); 
         }
         break; 
         case 5:{
             int accountnum; 
             cout<<"Enter the Account number: "; 
             cin >>accountnum; 
             MYBANK.Account_Details(accountnum); 
             cout<<endl; 
         }break; 
     }
     cout<<"Do you want to continue: "<<endl; 
     cout<<"If yes type yes or Yes or YES, If no type anything: "; 
     cin >>choice; 
     }while(choice=="yes" || choice=="YES" || choice=="Yes"); 
    return 0;
}


