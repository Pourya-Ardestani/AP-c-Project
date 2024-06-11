#include<iostream>
#include<vector>
using namespace std;


void sort(vector<float> & );

class Student
{
    private:
        float grade;
        string name;
    public:
        Student(string, float );
        void setGrade(float);
        float getGrade();
        string getName();
};


class ClassLesson
{
    private:
        vector<Student> listofStudents ;
        vector<float> grades ;
        int countofStudents ;
    public:
        ClassLesson(int);
        void setStudents();
        void sortStudents();
        void printStudentsName();
        void printStudentGrade();
        void printGrade(vector<float> &);
        void printNames(vector<Student> &);

};

int main()
{
    int numberOfStudents ;
    cout<< "please enter quantity of Student in class:";
    cin >> numberOfStudents; 
    ClassLesson fizic(numberOfStudents);
    cout << endl ;
    fizic.printStudentGrade();
    cout << endl ;
    fizic.printStudentsName();

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

void ClassLesson::printGrade(vector<float> &vec)
{
    for (int i=0; i < vec.size();  i++)
    {
        cout << vec.at(i) <<" ";
    }
    cout<<endl;
}

void ClassLesson::printNames(vector<Student> & vec)
{
    for (int i=0; i < vec.size();  i++)
    {
        cout << vec.at(i).getName() <<" ";
    }
    cout<<endl;
	
}

string Student::getName()
{
	return name;
}


//ClassLesson methods: 

ClassLesson::ClassLesson(int c)
{
    countofStudents = c ;
    setStudents();
}
void ClassLesson::setStudents()
{
    string new_name;
    float new_grade ;
    for (int i = 0; i < countofStudents; i++)
    {
        cout << i+1 <<". student: "<< endl; 
        cout << "Enter his/her name: ";
        cin >> new_name ;
        cout << "Enter grade: ";
        cin >> new_grade;
        Student a(new_name, new_grade);
        listofStudents.push_back(a);
        cout << endl;
        grades.push_back(new_grade) ;
    }
}

void ClassLesson::sortStudents()
{
    for(int i=countofStudents-1 ; i > 0 ; i--)
    {
        for(int j = 0 ; j < countofStudents-1 ; j++ )
        {
            if(listofStudents.at(j).getGrade() > listofStudents.at(j+1).getGrade() )// should be aware of encapsulation
            {
                Student temp = listofStudents.at(j) ;
                listofStudents.at(j) = listofStudents.at(j+1);
                listofStudents.at(j+1) = temp ;
            }
        }
    }   
}
    
void ClassLesson::printStudentsName()
{
    cout << "Here is the student list witch sorted by their grades :\n";
    sortStudents();
    printNames(listofStudents);
}
	
void ClassLesson::printStudentGrade()
{
    cout << "Here is their Sorted grades:\n";
    sort(grades);
    printGrade(grades);       
}