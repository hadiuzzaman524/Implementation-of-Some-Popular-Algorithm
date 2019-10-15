#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string name; // Given
    int math;  // Marks in math (Given)
    int phy;   // Marks in Physics (Given)
    int che;   // Marks in Chemistry (Given)
    int total; // Total marks (To be filled)
    int rank;  // Rank of student (To be filled)
};

// Function for comparing two students according
// to given rules
bool compareTwoStudents(Student a, Student b)
{
    // If total marks are not same then
    // returns true for higher tot

    // If marks in Maths are not same then
    // returns true for higher marks
    if (a.che != b.che)
        return (a.che>b.che);
else if(a.phy !=b.phy)
    return (a.phy >b.phy);
else

return a.math>b.math;
}

// Driver code
int main()
{
    int n = 5;

    // array of structure objects
    Student a[n];

    // Details of Student 1
   // a[0].name = "Bryan" ;
    a[0].math = 8 ;
    a[0].phy = 5 ;
    a[0].che = 1980 ;

    // Details of Student 2
    a[1].name= "Kevin" ;
    a[1].math= 9 ;
    a[1].phy= 8 ;
    a[1].che= 1999 ;

    // Details of Student 3
    a[2].name = "Nick" ;
    a[2].math = 4 ;
    a[2].phy = 3;
    a[2].che = 1980 ;

    // Details of Student 4
    a[3].name = "AJ" ;
    a[3].math = 8 ;
    a[3].phy = 7 ;
    a[3].che = 2000 ;

    // Details of Student 5
   a[4].name = "Howie" ;
    a[4].math = 1 ;
    a[4].phy = 8 ;
    a[4].che = 1995 ;

  sort(a, a+5, compareTwoStudents);
    // Display details of Students
    for (int i=0; i<n; i++)
    {

        cout << a[i].math << "\t"
             << a[i].phy << "\t"
             << a[i].che << "\t\t";
             cout << a[i].name <<"   ";
        cout <<"\n";
    }

    return 0;
}
