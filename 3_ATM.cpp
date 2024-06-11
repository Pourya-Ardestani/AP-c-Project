#include<iostream>
using namespace std;

#define PASSWORD  1234
#define FIRST_CREDIT 1240500 // tooman

int o_o(float &, int );


void witchBill(float );

class Card
{
  private:
    int password;
    float credit;
  public: 
    Card();
    void reduceMoney(float n); // preffer how to exchange money 
    void addMoney(float);
	void printCredit();
    int getPassword();
    float getCredit();
};


class ATM
{
  private:
    Card card ;

  public:
    ATM();
    void exchangCashMoney() ;// preffer how to exchange money 
    void transferMoney();
    void mojody();
};


int main()
{
    ATM machine;
}

// functions definition :
int o_o(float &cash , int amount)
{
    int count = 0;
    while(cash >= amount)
    {
        cash -= amount ;
        count ++;
    }
    return count ;
}


void witchBill(float cash)
{
    cout << "here is " << cash <<" in these bills :\n";
    
	int count = o_o(cash,200000);
    cout << "the "<<count << " of 200000"<< endl ;

    count = o_o(cash,100000);
    cout << "the "<<count << " of 100000"<< endl ;

    count = o_o(cash,50000);
    cout << "the "<<count << " of 50000"<< endl ;

    count = o_o(cash,10000);
    cout << "the "<<count << " of 10000"<< endl ;

    count = o_o(cash,5000);
    cout << "the "<<count << " of 5000"<< endl ;
}  

//class card mthods definition :
Card::Card()
{
    password = PASSWORD ;
    credit = FIRST_CREDIT;
}
void Card::reduceMoney(float n) // preffer how to exchange money 
{
    credit -= n ;
}
void Card::addMoney(float n)
{
    credit += n ;
}
void Card::printCredit()
{
    cout << "credit: "<< credit << " tooman \n";
}
int Card::getPassword()
{
    return password ;
}
float Card::getCredit()
{
    return credit ;
}
 
 
//class ATM mtheods definitions :


ATM::ATM()
{
    int h , i = 0 , password; 
    bool end = false ;
    cout << "hi welcome \nPlease Enter your password: ";
    cin >> password ;
    while(!end)
    {
        
        if (password != card.getPassword())
        {
        	cout << "\nInccorect password!\nPlease Enter your password again: ";
			cin >> password ;
		}
        else 
        {
            cout << "\nwhat operation do you want to do? \n1.withdrawal cash\n2.transfer money to another bank card \n3.show account balance \n4.Exit \nchoose one: ";
            cin >> h ;
            switch(h)
            {
                case 1 : exchangCashMoney();break;
                case 2 : transferMoney();break;
                case 3 : mojody();break;
                case 4 : end = true;cout << "Goodbye";break;
                default: cout <<"INVALID inpute" ;
            }  
			cout<<"\n----------------------------------------------------------"; 
        } 
    }
    
}
void ATM::exchangCashMoney() // preffer how to exchange money 
{
    float t_cash;
    cout << "Please Enter how much money do you want to cash withdrawal: ";
    cin >> t_cash ;
    if (t_cash > card.getCredit())
    {
        cout << "there is not enough money in you account to withdrawal " ;
    }
    else
    {
        witchBill(t_cash);  
        cout<< "the amount has reduced from your credit !  ";
        card.reduceMoney(t_cash);            
    }
}


void ATM::transferMoney()
{
	long long int cardNumber ;
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
    cout << "transfer successfuly done! \n";
}

void ATM::mojody()
{
	card.printCredit();

}
