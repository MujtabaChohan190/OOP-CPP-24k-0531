/*3. Write a program in C++ to calculate and print the Electricity bill of a given customer. The customer id,
name and unit consumed by the user should be taken from the keyboard and display the total amount to
pay to the customer. The charges are as follow:

If bill exceeds Rs. 18000 then a surcharge of 15% will be charged on top of the bill.
Test Input:
1001 //Customer ID
James //Customer Name
800 //Units Consumed
Expected Output:
Customer ID :1001
Customer Name: James
Units Consumed :800
Amount Charges @Rs. 35.90 per unit: 28720
Surcharge Amount: 4308
Net Amount Paid by the Customer: 33028.*/


#include<iostream>
using namespace std;

int main(){
    int id , UnitsConsumed;
    string CustomerName;

    //Taking the inputs

    cout<<"Enter the customer ID: ";
    cin>>id;

    cout << "Enter your name: ";
    cin>>CustomerName;

    cout<<"Enter units consumed: ";
    cin>>UnitsConsumed;

    //Set conditions
    double charge = 0;
    if(UnitsConsumed <=199){
        charge = 16.20;
    }
    if(UnitsConsumed >=200 && UnitsConsumed<300){
        charge = 20.10;        
    }
    if(UnitsConsumed>=300 && UnitsConsumed<500){
        charge = 27.10;
    }
    if(UnitsConsumed>=500){
        charge = 35.9;
    }

    //Calculating amount charge
    double AmountCharge = 0;
    AmountCharge = charge * UnitsConsumed;
    cout<<"@Rs "<<charge<<"per unit: "<<AmountCharge<<endl;

    double SurchargeAmount = 0;
    if(AmountCharge>18000){
        SurchargeAmount = AmountCharge * (15.0/100.0); //Using 15.0 and 100.0 for float division
        cout<<"Surcharge Amount: "<<SurchargeAmount<<endl;
    }
    double NetAmount=0;
    NetAmount = AmountCharge + SurchargeAmount;
    cout<<"The net amount paid by the customer is: "<<NetAmount;
    return 0;
}