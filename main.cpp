#include <iostream>
#include <string>
#include "car.cpp"
#include "user.cpp"
// Forward declarations of Car and User classes
class Car; // Forward declaration
class User; // Forward declaration

int main() {
   // Creating instances of Car and User using dynamic memory allocation
    Car* car1 = new Car(101, "Toyota Corolla", true, 50.0);
    User* user1 = new User(1, "John Doe");

    //usiing default constructor
     Car* car2 = new Car(); 
     User* user2 = new User();

     // Displaying details
    car1->displayDetails();
    car2->displayDetails();
    user1->displayDetails();
    user2->displayDetails();

    // Demonstrating renting and returning a car
    car1->rentCar();
    car1->displayDetails();
    car1->returnCar();
    car1->displayDetails();

    // Demonstrating user registration and login
    user1->registerUser();
    user1->login();


     // Display the total number of cars and users
    cout << "Total Cars: " << Car::totalCars << endl;
    cout << "Total Users: " << User::totalUsers << endl;

    // Freeing allocated memory
    delete car1;
    delete user1;

    delete car2;
    delete user2;

    return 0;

   

    

    return 0;
}
