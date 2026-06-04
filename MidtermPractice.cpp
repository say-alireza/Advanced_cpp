#include <string>
#include <iostream>
using namespace std;

class HugeInt
{

private:
    int number[50];
    static const short MaxDigits = 50;

public:

    HugeInt(string str = "");
    ~HugeInt();
    int Digit() const ;
    HugeInt operator++(int) ;
    friend ostream& operator<<(ostream& out, const HugeInt& h);

};

HugeInt::HugeInt(string str = "")
{
    for (int i = 0; i < 50; i++)
        number[i] = 0;
    if (str == "")
        return;


    for (int i = 0; i < str.length(); i++)
        number[i] = str[i] - '0';
    
};
int HugeInt::Digit() const
{
    for(int i = MaxDigits -1 ; i<= 0 ; i--)
    {
        if (number[i] != 0)
            return i + 1 ; 

    };


}
ostream& operator<<(ostream& out, const HugeInt& h) {
    int digits = h.Digit();
    for (int i = 0; i < digits; i++) {
        out << h.number[i];
    }
    return out;
}

HugeInt::~HugeInt() {
    cout << "number is destructed!" << endl;
}

// * can you tell whats the diffrence between ++i , i++

//int i = 10;
// cout << ++i;  
// cout << i;  

// int j = 10;
// cout << j++;  
// cout << j;   
  