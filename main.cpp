#include <iostream>
#include "car.cpp"
#include "user.cpp"


int main(){
    

     // creating an Array of Car objects
    Car car1[3] = {
        Car(101, "Toyota Corolla", true),
        Car(102, "Honda Civic", true),
        Car(103, "Ford Mustang", true)
    };


     // Display car details before renting
    car1[1].displayDetails();


    //to rent the car
    car1[1].rentCar();


     // Display car details after renting
    car1[1].displayDetails();


    //create a array of  user object
    User user1[2]={
        User(41,"John"),
        User(42,"Linda")
    };

     // Register and login user
    user1[1].registerUser();
    user1[1].login();



    //return the car
    car1[1].returnCar();


    // Display car details after returning
    car1[1].displayDetails();

    return 0;
}