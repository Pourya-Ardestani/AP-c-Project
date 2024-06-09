#include <iostream>
using namespace std;

class Star
{
    private:
        int numberOfStar ;

    public:
        Star(int n)
        {
            numberOfStar = n;
        }
        void print_star()
        {
            for(int i = 0 ; i < numberOfStar ; i++)
            {
                cout << "* " ; 
            }
            cout << endl ;
        }
};

int main()
{
    Star first(4);
    Star second(3);
    Star third(2);
    Star forth(1);
	
	Star *listOfInstances[] = {&first, &second, &third, &forth};
	Star* p ;
	p = listOfInstances[0] ;
	for(int i = 0 ; i < 4; i++)
	{
		p->print_star();
		p = listOfInstances[i+1] ;
	}
     

    return 0;
}