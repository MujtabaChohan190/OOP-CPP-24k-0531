/*5. A movie in a local theater is in great demand. To help a local charity, the theater owner has decided to
donate to the charity a portion of the gross amount generated from the movie. This example designs and
implements a program that prompts the user to input the movie name, adult ticket price, child ticket price,
number of adult tickets sold, number of child tickets sold, and percentage of the gross amount to be
donated to the charity. The output of the program is as follows.
-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
Movie Name: .................................... Journey to Mars
Number of Tickets Sold: .......................... 2650
Gross Amount: ......................................... $ 9150.00
Percentage of Gross Amount Donated: 10.00%
Amount Donated: ................................... $ 915.00
Net Sale: ................................................... $ 8235.00
Note that the strings, such as "Movie Name:" , in the first column are left-justified, the numbers in the
right column are right-justified, and the decimal numbers are output with two decimal places.
Input: The input to the program consists of the movie name, adult ticket price, child ticket price, number
of adult tickets sold, number of child tickets sold, and percentage of the gross amount to be donated to the
charity.
Output: The output is as shown above.*/



#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

    string movieName;
    int childTicketsSold, adultTicketsSold, totalTickets;
    float childTicketPrice, adultTicketPrice, grossRevenue, donationPercentage;

    // Input details
    cout << "Name: ";
    getline(cin, movieName);

    cout << "Number of child tickets: ";
    cin >> childTicketsSold;

    cout << "Number of adult tickets: ";
    cin >> adultTicketsSold;

    totalTickets = childTicketsSold + adultTicketsSold;

    cout << "Price of child ticket: ";
    cin >> childTicketPrice;

    cout << "Price of adult ticket: ";
    cin >> adultTicketPrice;

    grossRevenue = childTicketsSold * childTicketPrice + adultTicketsSold * adultTicketPrice;

    cout << "Percentage of Gross Amount Donated: ";
    cin >> donationPercentage;

    float donatedAmount = (donationPercentage / 100) * grossRevenue;
    float netRevenue = grossRevenue - donatedAmount;

    // Output details with modified formatting
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;

    // Movie Name output with correct alignment and dots
    cout << setw(40) << left << setfill('.') << "Movie Name: " 
         << setw(20) << right << movieName << endl;

    // Number of Tickets Sold output with correct alignment and dots
    cout << setw(40) << left << setfill('.') << "Number of Tickets Sold: " 
         << setw(20) << right << totalTickets << endl;

    // Gross Amount output with correct alignment, dots, and precision
    cout << setw(40) << left << setfill('.') << "Gross Amount: " 
         << setw(19) << right << fixed << setprecision(2) << grossRevenue << endl;

    // Percentage of Gross Amount Donated output with correct alignment and dots
    cout << setw(40) << left << setfill('.') << "Percentage of Gross Amount Donated: " 
         << setw(20) << right << fixed << setprecision(2) << donationPercentage << "%" << endl;

    // Amount Donated output with correct alignment, dots, and precision
    cout << setw(40) << left << setfill('.') << "Amount Donated: " 
         << setw(19) << right << donatedAmount << endl;

    // Net Sale output with correct alignment, dots, and precision
    cout << setw(40) << left << setfill('.') << "Net Sale: " 
         << setw(19) << right << netRevenue << endl;

    return 0;
}
