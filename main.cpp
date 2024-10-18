#include <iostream>
#include <string>
#include "car.cpp"
#include "user.cpp"


int main() {
   // Creating instances of Car and User using dynamic memory allocation
    Car* car1 = new Car(101, "Toyota C", true, 50.0);
    User* user1 = new User(1, "John Doe");
    ElectricCar* eCar1 = new ElectricCar(902, "Tesla electric",  true, 100.0, 75.0);
    HybridCar* hCar1 = new HybridCar(103, "Toyota Prius hybrid", true, 120.0, 65.0, 50.0);

     // Displaying details
    car1->displayDetails();
   
    eCar1->displayDetails();
    user1->displayDetails();
    hCar1->displayDetails();
 

    //  renting and returning a car
    car1->rentCar();
    car1->displayDetails();
    car1->returnCar();
    car1->displayDetails();

    //  user registration and login
    user1->registerUser();
    user1->login();


     // Display the total number of cars and users
    cout << "Total Cars: " << Car::totalCars << endl;
    cout << "Total Users: " << User::totalUsers << endl;

    // Freeing allocated memory
    delete car1;
    delete user1;
    delete hCar1;
    delete eCar1;

   
    return 0;
}
