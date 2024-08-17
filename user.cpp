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
        cout << "User " << this->name << " registered." << endl;
    }

    // Method to login the user
    void login() {
        cout << "User " << this->name << " logged in." << endl;
    }

    // Method to display user details
    void displayDetails() {
        cout << "User ID: " << this->userID << ", Name: " << this->name << endl;
    }

};