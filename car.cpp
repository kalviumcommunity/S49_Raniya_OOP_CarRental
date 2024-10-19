#include <iostream>
#include <string>

using namespace std;

// SRP: The Car class is responsible only for car-related data and actions.

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
        totalCars++; 
    }

    // Parameterized constructor (with carID and model only)
    Car(int carID, string model) {
        this->carID = carID;
        this->model = model;
        this->isAvailable = true; // Default to available
        this->rentalRate = 0.0;   // Default rental rate
        totalCars++;
    }

    // Full parameterized constructor
    Car(int carID, string model, bool isAvailable, double rentalRate) {
        setCarID(carID);
        setModel(model);
        setIsAvailable(isAvailable);
        setRentalRate(rentalRate);
        totalCars++;
    }

    // Destructor
    virtual ~Car() {
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

   // SRP: This method only focuses on renting a car.
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

        // SRP: This method handles returning the car and updating its availability.

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

    // Declare displayDetails as a pure virtual function
    virtual void displayDetails() const = 0; // Pure virtual function
};

// Initialize static variables
int Car::totalCars = 0;
double Car::discountPercentage = 11.0;

// ElectricCar class inherits Car (Single Inheritance)
// SRP: ElectricCar class extends Car, focusing on electric cars specifically.
class ElectricCar : public Car {
private:
    double batteryCapacity;

public:
    // Default constructor
    ElectricCar() : Car() {
        batteryCapacity = 0.0; // Default battery capacity
    }

    // Constructor with model and battery capacity
    ElectricCar(int carID, string model, double batteryCapacity)
        : Car(carID, model) {  // Calls the constructor of Car with carID and model
        this->batteryCapacity = batteryCapacity;
    }

    // Full parameterized constructor
    ElectricCar(int carID, string model, bool isAvailable, double rentalRate, double batteryCapacity)
        : Car(carID, model, isAvailable, rentalRate) {
        this->batteryCapacity = batteryCapacity;
    }

    // Override the pure virtual function from Car
    void displayDetails() const override {
        cout << "Car ID: " << getCarID() << ", Model: " << getModel() << ", Availability: "
             << (getIsAvailable() ? "Yes" : "No") << ", Rental Rate: $" << getRentalRate() << endl;
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};

// HybridCar class inherits from ElectricCar (Multilevel Inheritance)
// SRP: HybridCar extends ElectricCar, focusing on hybrid cars with fuel efficiency.

class HybridCar : public ElectricCar {
private:
    double fuelEfficiency; // Additional attribute for hybrid cars

public:
    // Default constructor
    HybridCar() : ElectricCar() {
        fuelEfficiency = 0.0; // Default fuel efficiency
    }

    // Constructor with model, battery capacity, and fuel efficiency
    HybridCar(int carID, string model, double batteryCapacity, double fuelEfficiency)
        : ElectricCar(carID, model, batteryCapacity) { // Calls the constructor of ElectricCar
        this->fuelEfficiency = fuelEfficiency;
    }

    // Full parameterized constructor
    HybridCar(int carID, string model, bool isAvailable, double rentalRate, double batteryCapacity, double fuelEfficiency)
        : ElectricCar(carID, model, isAvailable, rentalRate, batteryCapacity) {
        this->fuelEfficiency = fuelEfficiency;
    }

    // Override the pure virtual function from Car
    void displayDetails() const override {
        ElectricCar::displayDetails(); // Display details from ElectricCar
        cout << "Fuel Efficiency: " << fuelEfficiency << " miles per gallon (mpg)" << endl;
    }
}; 