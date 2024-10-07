#include <iostream>
#include <string>

using namespace std;

// Car class definition
class Car {
private:

//internal details of a car that users should not be able to modify directly
    int carID;
    string model;
    bool isAvailable;
    double rentalRate;


//public data members  for operations like renting or returning car etc, mutators and accessors are also public
public:
    static int totalCars; 
    static double discountPercentage; 

    // Constructor
    Car(int carID, string model, bool isAvailable, double rentalRate) {
        setCarID(carID);
        setModel(model);
        setIsAvailable(isAvailable);
        setRentalRate(rentalRate);
        totalCars++;
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

    void returnCar() {
        if (!isAvailable) {
            isAvailable = true;
            cout << "Car " << model << " returned." << endl;
        } else {
            cout << "Car " << model << " was not rented." << endl;
        }
    }

    static double applyDiscount(double rate) {
        return rate * (1 - discountPercentage / 100);
    }

    // Method to display car details
    void displayDetails() const {
        cout << "Car ID: " << getCarID() << ", Model: " << getModel() << ", Availability: "
             << (getIsAvailable() ? "Yes" : "No") << endl;
    }
};

// Initialize static variables
int Car::totalCars = 0; 
double Car::discountPercentage = 11.0;