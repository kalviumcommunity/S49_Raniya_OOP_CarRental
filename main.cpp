#include <iostream>
#include <string>
#include "car.cpp"
#include "user.cpp"


int main() {
   
//     User* user1 = new User(1, "John Doe");


//       // Creating instances of Car using different constructors
//     Car car1;  // Default constructor
//     Car car2(101, "Toyota Corolla");  // Parameterized constructor (carID and model)
//     Car car3(102, "Honda Civic", true, 45.0);  // Full parameterized constructor

//     // Creating instances of ElectricCar
//     ElectricCar electricCar1;  // Default constructor
//     ElectricCar electricCar2(201, "Tesla Model S", 100.0);  // Constructor with model and battery capacity
//     ElectricCar electricCar3(202, "Nissan Leaf", false, 50.0, 40.0);  // Full parameterized constructor

//     // Creating instances of HybridCar
//     HybridCar hybridCar1;  // Default constructor
//     HybridCar hybridCar2(301, "Toyota Prius", 60.0, 50.0);  // Constructor with model, battery capacity, and fuel efficiency
//     HybridCar hybridCar3(302, "Honda Clarity", true, 55.0, 50.0, 48.0);  // Full parameterized constructor
    


//     user1->displayDetails();


//     // Displaying details of all cars
//     cout << "Car Details:\n";
//     car1.displayDetails();
//     car2.displayDetails();
//     car3.displayDetails();

//     cout << "\nElectric Car Details:\n";
//     electricCar1.displayDetails();
//     electricCar2.displayDetails();
//     electricCar3.displayDetails();

//     cout << "\nHybrid Car Details:\n";
//     hybridCar1.displayDetails();
//     hybridCar2.displayDetails();
//     hybridCar3.displayDetails();

   

//     //  user registration and login
//     user1->registerUser();
//     user1->login();



//  // Renting and returning a car
//     car2.rentCar();
//     car2.displayDetails();
//     car2.returnCar();
//     car2.displayDetails();


//      // Display the total number of cars and users
//     cout << "Total Cars: " << Car::totalCars << endl;
//     cout << "Total Users: " << User::totalUsers << endl;



// Create an ElectricCar object
    ElectricCar eCar(101, "Tesla Model 3", true, 120.0, 75.0);
    
    // Create a HybridCar object
    HybridCar hCar(202, "Toyota Prius", true, 100.0, 60.0, 50.0);

    // Polymorphism in action
    Car* carPtr;

    // Pointing to ElectricCar
    carPtr = &eCar;
    cout << "Electric Car details:" << endl;
    carPtr->displayDetails();  // Calls ElectricCar's displayDetails

    // Pointing to HybridCar
    carPtr = &hCar;
    cout << "\nHybrid Car details:" << endl;
    carPtr->displayDetails();  // Calls HybridCar's displayDetails



   
    return 0;
}
