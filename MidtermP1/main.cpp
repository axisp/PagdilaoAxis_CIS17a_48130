

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct check{
    int account;
    float balance;
    float totlChecks;
    float totlDeposit;
};

struct statsResult
{
    float avg;
    float median;
    int *mode;   //array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};

void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
//
//Problem 1 functions
void errorAccount(int&);    //validates user input for account number
void getChecks(float&, int&);
void getDeposits(float&, int&);

int main() {

    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    
    return 0;
}

void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
    cout<<"In problem # 1"<<endl<<endl;
    check customer;
    float monthlyChecks;    //total of checks written in 1 month
    float monthlyDeposits;  //total of deposits made in a month
    int accChecks;      //accumulator to count the number of checks
    int accDeposits;    //accumulator to count the number of deposits
    float balanceNew;   //New account balance after checks and deposits
    //
    //Customer enters account number
    cout << "Enter your 5 digit account number: ";
    cin >> customer.account;
    //
    //input validation for customer account number
    errorAccount(customer.account);     
    //
    //Customer enters current monthly balance
    cout << "Enter your balance from the beginning of the month: ";
    cin >> customer.balance;
    
    getChecks(monthlyChecks, accChecks);
    customer.totlChecks = monthlyChecks;
    
    getDeposits(monthlyDeposits, accDeposits);
    customer.totlDeposit = monthlyDeposits;
    
    balanceNew = (customer.balance - customer.totlChecks)
                  + customer.totlDeposit;
    cout << setprecision(2) << showpoint << fixed;
    if(balanceNew < 0){
        cout << "Your balance is overdrawn, and $12.00 fee will be applied.\n";
        cout << "Balance: $" << balanceNew - 12 << endl << endl;
    }
    else
        cout << "\n\nYour current balance is: $" << balanceNew << endl <<endl;
    
    
}

void problem2(){
        cout<<"In problem # 2"<<endl<<endl;
}

void problem3(){
        cout<<"In problem # 3"<<endl<<endl;
}

void problem4(){
        cout<<"In problem # 4"<<endl<<endl;
}

void problem5(){
        cout<<"In problem # 5"<<endl<<endl;
}

void problem6(){
        cout<<"In problem # 6"<<endl<<endl;
        //
        //Output for all binary, octal, hex conversions
        cout << "a)\n";
        cout << "2.125: \n";
        cout << "\tBase 2: 10.001\n";
        cout << "\tBase 8: 2.1\n";
        cout << "\tBase 16: 2.2\n\n";
        cout << ".06640625: \n";
        cout << "\tBase 2: .00010001\n";
        cout << "\tBase 8: .042\n";
        cout << "\tBase 16: .11\n\n";
        //
        //Output displays float representation conversions
        cout << "-2.125: \n";
        cout << "\tFloat: 11000000000010000000000000000000\n";
        cout << "\tHex: C0080000\n\n";
        cout << ".006640625: \n";
        cout << "\tFloat: 00111111000010000000000000000000\n";
        cout << "\tHex: 3C880000\n\n";
        //
        //Output displays float Hex to decimal conversions
        cout << "b)\n";
        cout << "46666601: \n";
        cout << "\tDecimal: 14745.501\n";
        cout << "4666602: \n";
        cout << "\tDecimal: 14745.502\n";
        cout << "B9999AFE: \n";
        cout << "\tDecimal: -0.0002929791226\n\n";
        
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

void errorAccount(int &c){
    while(c > 99999 || c < 10000){
        cout << "Error! \n\nPlease re-enter your 5 digit account number: ";
        cin >> c;
    }
}

void getChecks(float &a, int &b){
    float checks;       //User inputs check value
    char again;         //loop control variable
    a=0;                //Accumulator for checks written
    b = 1;              //counts the number of checks written
    cout << "Enter all checks written this month.\n\n";
    do{
        cout << "Check# " << b++ << ": $";
        cin >> checks;
        a += checks;    //check is added to previous checks
        cout << "Would you like to enter another? (y/n)";
        cin >> again;   //Program asks if another check is to be written
    }while(again == 'Y' || again == 'y');
}

void getDeposits(float &d, int &e){
    float deposits; //variable stores user's deposits
    char again;     //Loop control variable
    d=0;            //Deposit accumulator
    e = 1;          //counts the number of deposits
    cout << "\n\nEnter all deposits made this month.\n\n";
    do{
        cout << "Deposit# " << e++ << ": $";
        cin >> deposits;
        d += deposits;       //Deposit is added to overall value
        cout << "Would you like to enter another? (y/n)";
        cin >> again;        //Program asks if another 
                             //deposit needs to be made
    }while(again == 'Y' || again == 'y');
}