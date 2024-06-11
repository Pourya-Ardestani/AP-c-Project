#include<iostream>
using namespace std;

#define PASSWORD  1234
#define FIRST_CREDIT 1,240,500 // tooman

int o_o(float &cash , int amount)
{
    int count = 0;
    while(cash > amount)
    {
        cash -= amount ;
        count ++;
    }
    return count ;
}


void witchBill(float cash)
{
    cout << "here is " << cash <<" in these bills :\n";
    int count = o_o(cash,100000);
    cout << "the "<<count << "of 100000"<< endl ;

    count = o_o(cash,200000);
    cout << "the "<<count << "of 200000"<< endl ;

    count = o_o(cash,50000);
    cout << "the "<<count << "of 50000"<< endl ;

    count = o_o(cash,10000);
    cout << "the "<<count << "of 10000"<< endl ;

    count = o_o(cash,5000);
    cout << "the "<<count << "of 5000"<< endl ;
}  

class Card
{
  private:
    int password;
    float credit;
  public: 
    Card()
    {
        password = PASSWORD ;
        credit = FIRST_CREDIT;
    }
    void reduceMoney(float n) // preffer how to exchange money 
    {
        credit -= n ;
    }
    void addMoney(float n)
    {
        credit += n ;
    }
    void printCredit()
    {
        cout << "credit: "<< credit ;
    }
    int getPassword()
    {
        return password ;
    }
    float getCredit()
    {
        return credit ;
    }



};


class ATM
{
  private:
    Card card ;

  public:
    ATM()
    {
        int h , i = 0 , password; 
        while(i<3)
        {
            cout << "hi welcome \nPlease Enter your password: ";
            cin >> password ;
            if (password == card.getPassword())
            {
                cout << "what operation do you want to do? \n1.exchange money\n2.transfer money to another bank card \n3.show account balance";
                cin >> h ;
                switch(h)
                {
                    case 1 : exchangCashMoney();
                    case 2 : transferMoney();
                    case 3 : mojody();
                }
            }


        }

        
    }
    void exchangCashMoney() // preffer how to exchange money 
    {
        float t_cash;
        cout << "Please Enter how much money do you want to cash withdrawal ";
        cin >> t_cash ;
        if (t_cash > card.getCredit())
        {
            cout << "there is not enough money in you account to withdrawal" ;
        }
        else
        {
            witchBill(t_cash);  
            cout<< "the amount has reduced from your credit ! \n here is your bill in cash ";
            card.reduceMoney(t_cash);            
        }
    }
    
    
    void transferMoney()
    {
    	long int cardNumber ;
        float amount ;
        cout << "Please enter card_number that you want to transfer to: " ;
        cin >> cardNumber ;
        Card secondCard ;
        cout << "Please enter amount that you want to transfer: " ;
        cin >> amount ;
        while (card.getCredit() < amount)
        {
            cout << "amount is more than your credit please try again:\n ";
            cin >> amount ;
        }
        card.reduceMoney(amount);
        secondCard.addMoney(amount);
	}
	
    void mojody()
    {
    	card.printCredit();
	}

};


int main()
{
    ATM machine_1;

}