

#include <iostream>
#include <string>
#include "car.cpp"
#include "user.cpp"


int main() {  


// Create an ElectricCar object
    ElectricCar eCar(101, "Tesla Model 3", true, 120.0, 75.0);
    
    // Create a HybridCar object
    HybridCar hCar(202, "Toyota Prius", true, 100.0, 60.0, 50.0);

    
    cout << "Electric Car details:" << endl;
    eCar.displayDetails();  // Calls ElectricCar's displayDetails

    
    cout << "\nHybrid Car details:" << endl;
    hCar.displayDetails();  // Calls HybridCar's displayDetails

   
    return 0;
}

