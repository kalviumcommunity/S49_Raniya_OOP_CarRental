#include <iostream>
#include <string>

using namespace std;

//car class
class Car{
    public:
        int carID;
        string model;
        bool isAvailable;
        static int totalCars; // Static variable to keep track of the total number of cars

        
        

   //constructor
   Car(int id, string model, bool isAvailable);

    //these member methods cant be static as they need to modify the objects state (isAvailable) which is not possible with static functions
    void  rentCar();    
    void  returnCar();
    void displayDetails();

};

//initializing static variable outside the class
int Car::totalCars=0;

//constructor implementation 
Car::Car(int carID, string model, bool isAvailable){
    //this->carID refers to the member variable
    this->carID = carID;//refers to constructor's parameter
    this->model =model;
    this->isAvailable=isAvailable;
    totalCars++;
}

//member method to rent the car
void Car::rentCar(){
    if (isAvailable) {
            isAvailable = false;
            cout << "Car " << model << " rented." << endl;
        } else {
            cout << "Car " << model << " is already rented." << endl;
        }
}

void Car::returnCar(){
    if (!isAvailable) {
            isAvailable = true;
            cout << "Car " << model << " returned." << endl;
        } else {
            cout << "Car " << model << " was not rented." << endl;
        }
}

// Method to display car details
void Car::displayDetails() {
    //to access the member variable of the current object.
    cout << "Car ID: " << this->carID << ", Model: " << this->model << ", Availability: " << (this->isAvailable ? "Yes" : "No") << endl;
}