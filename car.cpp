#include <iostream>
#include <string>

using namespace std;

//car class
class Car{
    public:
        int carID;
        string model;
        bool isAvailable;

   //constructor
   Car(int id, string model, bool isAvailable);

    //these member methods cant be static as they need to modify the objects state (isAvailable) which is not possible with static functions
    void  rentCar();    
    void  returnCar();

};

//constructor implementation 
Car::Car(int carID, string model, bool isAvailable){
    this->carID = carID;
    this->model =model;
    this->isAvailable=isAvailable;
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

