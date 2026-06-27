#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

class Student
{
public:
    int rollNo;
    string name;
    int m1, m2, m3;
    int total;
    float percentage;
    int rank;

    void calculate()
    {
        total = m1 + m2 + m3;
        percentage = total / 3.0;
    }
};

bool compare(Student a, Student b)
{
    return a.total > b.total;
}

int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    Student s[n];

    for(int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << endl;

        cout << "Roll Number: ";
        cin >> s[i].rollNo;

        cout << "Name: ";
        cin >> s[i].name;

        cout << "Marks in Subject 1: ";
        cin >> s[i].m1;

        cout << "Marks in Subject 2: ";
        cin >> s[i].m2;

        cout << "Marks in Subject 3: ";
        cin >> s[i].m3;

        s[i].calculate();
    }

    sort(s, s + n, compare);

    for(int i = 0; i < n; i++)
    {
        s[i].rank = i + 1;
    }

    cout << "\n---------------- STUDENT RANK LIST ----------------\n";

    cout << left
         << setw(6) << "Rank"
         << setw(8) << "Roll"
         << setw(15) << "Name"
         << setw(10) << "Total"
         << setw(12) << "Percentage" << endl;

    for(int i = 0; i < n; i++)
    {
        cout << left
             << setw(6) << s[i].rank
             << setw(8) << s[i].rollNo
             << setw(15) << s[i].name
             << setw(10) << s[i].total
             << fixed << setprecision(2)
             << setw(12) << s[i].percentage
             << endl;
    }

    return 0;
}