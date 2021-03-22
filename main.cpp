#include <iostream>
#include <fstream>
#include <string>
#include "user.h"
#include "drink.h"

using namespace std;

int Read_User_Console(user& A) {
    user B;
    
    string str1, str2;
    int inpt;

    cout << "First name: ";
    cin >> str1;
    cout << "Last name: ";
    cin >> str2;
    B.set_name(str1, str2);
    cout << "Enter age: ";
    cin >> inpt;
    if (inpt < 18) {
        cout << "Can't make an account if you're underage\n";
        return 1;
    }
    B.set_age(inpt);
    cout << "(optional) Enter a link to a Facebook profile: \n";
    getline(cin, str1);
    getline(cin, str1);
    if( str1 != "" )
        B.set_fb(str1);
    cout << "(optional) Enter a link to a Instagram profile: \n";
    getline(cin, str1);
    if (str1 != "")
        B.set_insta(str1);

    A = B;
    return 0;
}

int main()
{
    user A;
    vector <user> V;
    int tmp;
    int error_code = 0;
    
    cout << "   Start using Drinkeer\n\n\n";
    cout << "First create your profile\n";
    error_code = Read_User_Console(A);

    /*while (error_code) {
        cout << "Bad input. Enter fields again\n";
        error_code = Read_User_Console(A);
    }*/

    if (error_code) return 0;

    cout << "\nGood, now make some accounts for ";
    cout << "your friends so you can start having fun\n";

    cout << "How many friends do you want to enter now?\n";
    cin >> tmp;
    for (int i = 0; i < tmp; ++i) {
        user tmp2;
        error_code = Read_User_Console(tmp2);
        V.push_back(tmp2);
    }

    cout << "\nOkay, so those are your friends\n";
    cout << "When do you want? ( dd-mm-yyyy, hh:mm ) \n";
    
    string date, time, str1;
    cin >> date >> time;
    cout << "Who do you want to invite for a sparkling water on that time?\n\n";

    getline(cin, str1);
    getline(cin, str1);
     
    bool found = false;
    for (int j = 0; j < V.size(); ++j)
        if (V[j].get_name() == str1 ) {
            A.send_notification(V[j], date, time);
            found = true;
            cout << "Notification sent!\n";
            break;
        }
    if (!found) cout << "Friend not found\n";

    return 0;
}
