#include <iostream>

using namespace std;

int main()
{
    struct regperson
    {
        char name[75];
        int id;
        int birthdate;
        char sex;
        char profession[75];
        char educlevel[20];
    };
    
    struct regperson person1;
    person1.id = 22;
    person1.name = "Daniel";
    cout << person1.id;
}