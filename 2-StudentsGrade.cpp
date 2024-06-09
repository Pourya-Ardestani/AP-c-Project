#include<iostream>
#include<vector>
using namespace std;


void sort(vector<float> & );
void printVector(vector<float> &);

class Student
{
    private:
        float grade;
        string name;
    public:
        Student(string, float );
        void setGrade(float);
        float getGrade();
};

int main()
{
    int numberOfStudents ;
    cout<< "please enter quantity of Student in class:";
    cin >> numberOfStudents; 
    string new_name;
    float new_grade ;
    vector<float> grades ;
    for (int i = 0; i < numberOfStudents; i++)
    {
        cout << i+1 <<". student: "<< endl; 
        cout << "Enter his/her name: ";
        cin >> new_name ;
        cout << "Enter grade: ";
        cin >> new_grade;
        Student a(new_name, new_grade);
        cout << endl;
        grades.push_back(new_grade) ;
    }
    sort(grades);
    printVector(grades);

    return 0;
}

void Student::setGrade(float n )
{
    grade = n ; 
}
float Student::getGrade()
{
    return grade;
}
Student::Student(string s, float g)
{
    grade = g ;
    name = s ;
}


void sort(vector<float> & grades)
{
    int len = grades.size() ;
    for(int j = 0 ; j < len ; j++)
    {
        for(int i = len-2  ; i>=0 ; i--)
        {
            if (grades.at(i) > grades.at(i+1))
            {
                int temp = grades.at(i) ; 
                grades.at(i) = grades.at(i+1);
                grades.at(i+1) = temp ;
            }
        }
    }
}
void printVector(vector<float> &vec)
{
    cout << "sorted grades are: ";
    for (int i=0;  i < vec.size();  i++)
    {
        cout<<vec.at(i)<<" ";
    }
    cout<<endl;
}