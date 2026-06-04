//why we Need classes  ?

// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     int sumber = 12 ; 
//     // dry -> dont repeat yourself 
// }


// How to delcare a class ?
// class Car
// {
//     int plate;
// };

// constructor   ( using this , intialization list)
// class Car
// {
//     int plate;
//     Car(int plate)
//     {
//         this-> plate = plate;
//     }
//     Car(int number) : plate(number) {}

// };

// method , memeber 
// declare a method inside and outside a class 
// class Car
// {
//     int plate;
//     // Car(int plate)
//     // {
//         //     this-> plate = plate;
//         // }
//         // Car(int number) : plate(number) {}
//     public : 
//         int void();
//     // {
//     //     cout<<"the value of the plate  is " <<plate<<endl
//     // }
// };
// int Car::void(int)
// {
//     cout<<"the value of the plate  is "<<plate<<endl;
// }




// encapsulation 
// The meaning of Encapsulation, is to make sure that "sensitive" data is hidden from users.


// class Car
// {
// private:
//     int plate;
  
// public : 
//     Car(int plate)
//     {
//         this-> plate = plate;
//     }
//     void Setplate(int number)
//     {
//         plate = number;
//     }
//     int Getplate()
//     {
//         return plate;
//     }
// };

// int main()
// {
//     Car obj(16);
//     obj.Setplate(13);
//     cout<<obj.Getplate(); 
// }











// 1. Class definition, access specifiers, and object creation
// Question: Create a class called "BankAccount" with private member variables (accountNumber, balance)
// and public methods to deposit and withdraw. Then create an object of this class in main().

// class BankAccount
// {
// private:
//     int accountNumber;
//     int balance;
// public :
//     BankAccount(int accountNumber,int balance)
//     {
//         this->balance = balance;
//     if(accountNumber >= 1000000000 && accountNumber<= 9999999999)
//         this->accountNumber = accountNumber;
//     }
//     void setBalance(int );
//     int  getBalance();
//     void setaccountnumber(int );
//     void deposit(int );
//     void withdraw(int );
//     int getaccountnumber();


// };
// void BankAccount::setBalance(int number)
// {
//     balance = number;
// }
// int BankAccount::getBalance()
// {
//     return balance;
// }
// void BankAccount::setaccountnumber(int number)
// {
//     if(number >= 1000000000 && number<= 9999999999)
//         accountNumber = number;
// }
// int BankAccount::getaccountnumber()
// {
//     return accountNumber;
// }
// void BankAccount::withdraw(int num)
// {
//     if(balance-num >= 0)
//         balance -= num;
//     else
//         cout<<"you do not have enough money";
    
// }
// void BankAccount::deposit(int num)
// {
//     balance +=num; 
// }

// int main()
// {
//     BankAccount acc1(1000000000,50);
//     // acc1.setaccountnumber(1000000000)
//     cout<<acc1.getaccountnumber();
// }
// 2. Setter functions
// Question: Add a setter method for balance that only allows setting the balance if the new value is non-negative.
// Also add a setter for accountNumber that only allows setting if the number has exactly 10 digits.



// 3. Getter functions
// Question: Add getter methods for balance and accountNumber. The balance getter should return a double.
// The accountNumber getter should return the number as a string. Mark both getters as const.


// 4. Constructor with validation
// Question: Add a constructor to BankAccount that takes accountNumber and initialBalance as parameters.
// The constructor should validate that accountNumber has exactly 10 digits and initialBalance is non-negative.
// If validation fails, set default values (accountNumber = "0000000000", balance = 0.0).



// 5. Destructor
// Question: Add a destructor to BankAccount that prints a message: "Account [accountNumber] is being closed".
// Create an object in main() and observe when the destructor is called.

// #include <iostream>
// using namespace std;
// class Tracker
// {
//     private: 
//     static int peakcount;
//     int id;
//     static int nextId;
//     public:
//         Tracker(int id,int nextId)
//         {
//             this->id = id;
//             this->nextId = nextId;
//         }
//        int  peak() const
//        {
//             peakcount++;
//             return id;
//        }
//        static int getNextId()
//        {
//             return nextId;
    
//        }
//        static int getpeakcount()
//        {
//         return peakcount;
//        }
// };
// int Tracker::peakcount = 0;
// int main()
// {
//     const Tracker obj(1,3);
//     obj.peak();
//     obj.peak();
//     cout<<Tracker::getpeakcount();
// }
