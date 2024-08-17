#include <iostream>
#include <string>

using namespace std;

//user class
class User{
    public:
        int userID;
        string name;

    //constructor
    User(int userID,string name){
        this->userID=userID;
        this->name=name;
    }    


    // Method to register the user
    void registerUser() {
        cout << "User " << name << " registered." << endl;
    }

    // Method to login the user
    void login() {
        cout << "User " << name << " logged in." << endl;
    }

};