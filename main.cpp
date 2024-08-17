#include <iostream>
#include "car.cpp"
#include "user.cpp"


int main(){
    //Create a car object
    Car car1(101,"Toyota", true);

    //to rent the car
    car1.rentCar();


    //create a user object
    User user1(1,"John");

     // Register and login user
    user1.registerUser();
    user1.login();



    //return the car
    car1.returnCar();

    return 0;
}