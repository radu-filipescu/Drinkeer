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

int Read_User_File( ifstream& fin, user& A) {
    user B;

    string str1, str2;
    int inpt;

    fin >> str1;
    fin >> str2;

    B.set_name(str1, str2);
 
    fin >> inpt;
    if (inpt < 18)
        return 1;
    B.set_age(inpt);


    getline(fin, str1);
    getline(fin, str1);
    if (str1 != "")
        B.set_fb(str1);
    getline(fin, str1);
    if (str1 != "")
        B.set_insta(str1);

    A = B;
    return 0;
}

int main()
{
    ifstream fin("user_database.txt");

    int nr_of_users;
    vector <user> users;

    fin >> nr_of_users;

    for (int i = 1; i <= nr_of_users; ++i) {
        user tmp;

        Read_User_File(fin, tmp);

        int nr_of_drinks;
        string inpt;

        fin >> nr_of_drinks;
        for (int i = 1; i <= nr_of_drinks; ++i) {
            fin >> inpt;

            tmp.add_fav_drink(drink(inpt));
        }

        users.push_back(tmp);
    }

    cout << "Enter a drink:\n";
    string inpt;
    cin >> inpt;

    cout << "The users who like " << inpt << " are: \n";
    for (int i = 0; i < (int)users.size(); ++i)
        if (users[i].check_if_drink(inpt))
            cout << users[i].get_name() << "\n";

    // if two users share a common favourite drink,
    // they'll be friends ( aka. edges in graph )

    for( int i = 0; i < (int)users.size(); ++i )
        for( int j = i + 1; j < (int)users.size(); ++j ) {
            vector <drink> v1, v2;

            v1 = users[i].get_fav_drinks();
            v2 = users[j].get_fav_drinks();

            for( int i2 = 0; i2 < (int)v1.size(); ++i2 )
                for( int j2 = 0; j2 < (int)v2.size(); ++j2 )
                    if (v1[i2] == v2[j2]) {
                        users[i].add_friend( users[j] );
                        users[j].add_friend( users[i] );
                        break;
                    }
        }

    cout << "\n\nName one of the users: ";
    getline( cin, inpt );
    getline( cin, inpt );
    cout << "Those are his friends: \n";

    int p = 0;
    for (int i = 0; i < (int)users.size(); ++i )
        if (users[i].get_name() == inpt) {
            p = i;
            break;
        }

    for (int i = 0; i < (int)users.size(); ++i)
        if (p != i && users[p].check_if_friend(users[i]))
            cout << users[i].get_name() << '\n';

    return 0;
}
