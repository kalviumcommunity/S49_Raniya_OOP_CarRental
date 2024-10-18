#include <iostream>
#include <string>

using namespace std;

// Car class definition
class Car {
private:
    int carID;
    string model;
    bool isAvailable;
    double rentalRate;

public:
    static int totalCars;
    static double discountPercentage;

    // Default constructor
    Car() {
        carID = 0;
        model = "default";
        isAvailable = true;
        rentalRate = 0.0;
    }

    // Parameterized constructor
    Car(int carID, string model, bool isAvailable, double rentalRate) {
        setCarID(carID);
        setModel(model);
        setIsAvailable(isAvailable);
        setRentalRate(rentalRate);
        totalCars++;
    }

    // Destructor
    ~Car() {
        totalCars--;
    }

    // Accessor methods
    int getCarID() const {
        return carID;
    }

    string getModel() const {
        return model;
    }

    bool getIsAvailable() const {
        return isAvailable;
    }

    double getRentalRate() const {
        return rentalRate;
    }

    // Mutator methods
    void setCarID(int id) {
        carID = id;
    }

    void setModel(string mdl) {
        model = mdl;
    }

    void setIsAvailable(bool available) {
        isAvailable = available;
    }

    void setRentalRate(double rate) {
        rentalRate = rate;
    }

    // Rent the car
    void rentCar() {
        if (isAvailable) {
            double discountedRate = applyDiscount(rentalRate);
            isAvailable = false;
            cout << "Car " << model << " rented at the discounted price of $"
                 << discountedRate << " per day." << endl;
        } else {
            cout << "Car " << model << " is already rented." << endl;
        }
    }

    // Return the car
    void returnCar() {
        if (!isAvailable) {
            isAvailable = true;
            cout << "Car " << model << " returned." << endl;
        } else {
            cout << "Car " << model << " was not rented." << endl;
        }
    }

    // Static method to apply discount
    static double applyDiscount(double rate) {
        return rate * (1 - discountPercentage / 100);
    }

    // Method to display car details
    void displayDetails() const {
        cout << "Car ID: " << getCarID() << ", Model: " << getModel() << ", Availability: "
             << (getIsAvailable() ? "Yes" : "No") << ", Rental Rate: $" << getRentalRate() << endl;
    }
};

// Initialize static variables
int Car::totalCars = 0;
double Car::discountPercentage = 11.0;

// ElectricCar class inherits Car (Single Inheritance)
class ElectricCar : public Car {
private:
    double batteryCapacity;

public:
    // Constructor
    ElectricCar(int carID, string model, bool isAvailable, double rentalRate, double batteryCapacity)
    : Car(carID, model, isAvailable, rentalRate) {  
    this->batteryCapacity = batteryCapacity;
}


    // to display electric car details
    void displayDetails() const {
        Car::displayDetails();  // Call the base class method to display car details
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};



// HybridCar class inherits from ElectricCar (Multilevel Inheritance)
class HybridCar : public ElectricCar {
private:
    double fuelEfficiency; // Additional attribute for hybrid cars

public:
    // Constructor
    HybridCar(int carID, string model, bool isAvailable, double rentalRate, double batteryCapacity, double fuelEfficiency)
        : ElectricCar(carID, model, isAvailable, rentalRate, batteryCapacity) {
        this->fuelEfficiency = fuelEfficiency;
    }

    //display hybrid car details
    void displayDetails() const {
        ElectricCar::displayDetails();  // Call the base class method to display electric car details
        cout << "Fuel Efficiency: " << fuelEfficiency << " miles per gallon (mpg)" << endl;
    }
};