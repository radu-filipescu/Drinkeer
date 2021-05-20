#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "user.h"
#include "drink.h"
#include "bar.h"
#include "place_factory.h"
#include <ctime>

using namespace std;

// this template function can compare users, places or drinks
// using the fact that all those classes have the same name getter

template <class T>
bool CompareName(T a, T b) {
    if (a.get_name() < b.get_name()) return -1;
    if (a.get_name() == b.get_name()) return 0;
    return 1;
}

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
        throw std::out_of_range("Can't make an account if you're underage\n");
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
    
    try {
        if (inpt < 18)
            throw 18;
    }
    catch(int age){
        cout << "Sorry, you need to be at least 18 to use this app.\n";
        cout << "Your age is " << age << '\n';
    }

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

    cout << "\n\n";
    // Demonstration of the virtual function "generate_invite()"

    place* ptr;
    bar *ptr2;
    bar IrishPub;

    IrishPub.set_name("Irish Pub");
    IrishPub.set_location("Old Town, Bucharest");
    
    IrishPub.add_bar_game("Darts");
    IrishPub.add_bar_game("Beerpong");
    IrishPub.add_bar_game("Pinball");

    ptr = &IrishPub;
    ptr2 = &IrishPub;
    
    cout << ptr -> generate_invite() << '\n';
    cout << ptr2 -> generate_invite() << '\n';

    shared_ptr<notification> smart_ptr(new notification( "21.04.2021", "20:00"));

    cout << '\n';
    cout << smart_ptr->print_notification() << "\n\n";

    /// we'll get the first user ( alphabetically ) using the template function

    user first_user = users[0];

    for (int i = 1; i < (int)users.size(); ++i)
        if (CompareName(first_user, users[i]) == 1 )
            first_user = users[i];
    
    cout << "First user alphabetically is:\n" << first_user.get_name() << '\n';
    cout << "His is " << first_user.get_age() << " years old\n\n";
    
    // using the 'Factory' design pattern
    // for making places of a few types

    place_factory Fact;

    place JazzBarLounge = Fact.Jazz_lounge( "JazzBarLounge" );
    place HopHooligans = Fact.Hipster_bar("Hop Hooligans");

    srand((int)time(0));

    bool already_set[105] = { 0 };
    for (int i = 1; i <= 5; ++i) {
        int R = rand() % (int)users.size();

        //if (0 <= R && R < (int)users.size())
        if (!already_set[R]) {
            HopHooligans.add_usual_user(&users[R]);
            already_set[R] = true;
        }
    }

    cout << "And the guys who like fancy beer are: \n";

    for (int i = 0; i < (int)HopHooligans.usual_users.size(); ++i)
        cout << HopHooligans.usual_users[i]->get_name() << '\n';

    return 0;
}
