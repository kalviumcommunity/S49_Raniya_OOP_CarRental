#include <iostream>
#include "car.cpp"
#include "user.cpp"


int main(){
    //Create a car object
    Car car1(101,"Toyota", true);


     // Display car details before renting
    car1.displayDetails();


    //to rent the car
    car1.rentCar();


     // Display car details after renting
    car1.displayDetails();


    //create a user object
    User user1(1,"John");

     // Register and login user
    user1.registerUser();
    user1.login();



    //return the car
    car1.returnCar();


    // Display car details after returning
    car1.displayDetails();

    return 0;
}