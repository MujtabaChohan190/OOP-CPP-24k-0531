/*Task - 03:
Create A class called Invoice that a hardware store might use to represent an invoice for an item sold at the
store. An Invoice should include four pieces of information as instance variables - a part number (type String), a
part description (type String), a quantity of the item being purchased (type int) and a price per item (double).

Your class should have a constructor that initialize the four instance variables. In addition, provide a method
named getInvoiceAmount that calculates the invoice amount (i.e., multiples the quantity by the price per item),
then returns the amount as a double value. If the quantity is not positive, it should be set to 0. If the price per
item is not positive, it should be set to 0.0.*/


#include<iostream>
using namespace std;
class Invoice{
   string number;
   string description;
   int quantity;
   double price;
   public:
   Invoice(string num,string des,int quan,double pr):number(num),description(des),quantity(quan),price(pr){
    if (quantity<0)
    {
        quantity=0;
    }
    if (price<0)
    {
       price=0.0;
    }
   }
double getInvoiceAmount(){
   return price*quantity; 
}
void display() {
    cout << "Part Number: " << number << endl;
    cout << "Description: " << description << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Price Per Item: $" << price << endl;
    cout << "Total Invoice Amount: $" << getInvoiceAmount() << endl;
}
};
int main() {
    Invoice item("111C", "Hammer", 5, 10.50);
    item.display();

    Invoice invalidItem("5678B", "Wrench", -3, -15.75);
    invalidItem.display();

    return 0;
}
