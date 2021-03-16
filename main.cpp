#include <bits/stdc++.h>

using namespace std;

class type_of_drink {
    public:
        string name;
        int alcohol_percent;
        int volume;           // in ml
        double usual_price;   // in local currency
        type_of_drink() {
            name = "";
            alcohol_percent = volume = usual_price = 0;
        }
        type_of_drink( string A ) {
            name = A;
            alcohol_percent = volume = usual_price = 0;
        }
};


class user
{
    private:
        string firstname;
        string lastname;
        string location;
        int age;
        char gender;   // M, F, or O
        string description;
        string link_to_facebook;
        string link_to_instagram;
        vector <type_of_drink> interested_in;
    public:
        user() {
            firstname = lastname = location = "";
            age = 18;
            gender = "";
            description = link_to_facebook = link_to_instagram = "";
            interested_in.clear();
        }
        user( string f, string l ) {
            firstname = f;
            lastname = l;
            location = "";
            age = 18;
            gender = "";
            description = link_to_facebook = link_to_instagram = "";
            interested_in.clear();
        }
        user( string f, string l, int _age ) {
            firstname = f;
            lastname = l;
            location = "";
            age = _age;
            gender = "";
            description = link_to_facebook = link_to_instagram = "";
            interested_in.clear();
        }
        void add_drink( type_of_drink A ) {
            interested_in.push_back( A );
        }
        string get_fname() {
            return firstname;
        }
        void set_fname( string A ) {
            firstname = A;
        }
        string get_lname() {
            return lastname;
        }
        void set_lname( string A ) {
            lastname = A;
        }
        int get_age() {
            return age;
        }
        int set_age( int a ) {
            if( a < 18 ) return -1; // error code

            age = a;
            return 0;
        }
};

class place {
    public:
        string name;
        string street;
        string city;
        vector <type_of_drink> drinks_served;
        place() {
            name = street = city = "";
            drinks_served.clear();
        }
        place( string A ) {
            name = A;
            street = city = "";
            drinks_served.clear();
        }
        bool check_if_user_banned( user A ) {
            return  banned_list.find( A ) == banned_list.end();
        }
    private:
        unordered_map <user, bool> frequent_users;
        unordered_map <user> banned_list;

};

class personal_home : public place {
    private:
        string owner;
};

class bar : public place {

};

int main()
{

    return 0;
}
