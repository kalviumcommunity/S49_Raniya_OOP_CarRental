#include <iostream>
#include "car.cpp"
#include "user.cpp"


int main(){
    

     // creating an Array of Car objects  using dynamic memory allocation
    Car* car1 = new Car[3] {
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


    //create a array of  user object using dynamic memory allocation
    User* user1 = new User[2]{
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


    //freee up memory for user1 and car1 to avoid memory leaks
    delete[] car1;
    delete[] user1;

    return 0;
}