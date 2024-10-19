#include <iostream>
#include <string>
#include "car.cpp"
#include "user.cpp"


int main() {
    // Create an ElectricCar object
    ElectricCar eCar(101, "Tesla Model 3", true, 120.0, 75.0);
    
    // Create a HybridCar object
    HybridCar hCar(202, "Toyota Prius", true, 100.0, 60.0, 50.0);

    // Polymorphism following the Liskov Substitution Principle (LSP)
    Car* carPtr;

    // LSP: Substituting base class pointer with ElectricCar instance
    carPtr = &eCar;
    cout << "Electric Car details:" << endl;
    carPtr->displayDetails();  // Calls ElectricCar's displayDetails method 

    // LSP: Substituting base class pointer with HybridCar instance
    carPtr = &hCar;
    cout << "\nHybrid Car details:" << endl;
    carPtr->displayDetails();  // Calls HybridCar's displayDetails method 

    return 0;
}
