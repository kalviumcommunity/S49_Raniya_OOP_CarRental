#include <iostream>

using namespace std;

// Car class
class Car
{
public:
    int carID;
    string model;
    bool isAvailable;
    static int totalCars; // Static variable to keep track of the total number of cars
    double rentalRate;

    static double discountPercentage;

    // Constructor
   Car(int carID, string model, bool isAvailable, double rentalRate) {
    this->carID = carID;
    this->model = model;
    this->isAvailable = isAvailable;
    this->rentalRate = rentalRate;
    totalCars++;
}

void rentCar()
    {
        if (isAvailable)
        {
            double discountedRate = applyDiscount(rentalRate);
            isAvailable = false;
            cout << "Car " << model << " rented at discounted price of $" 
                 << discountedRate << " per day." << endl;
        }
        else
        {
            cout << "Car " << model << " is already rented." << endl;
        }
    }


    void returnCar()
    {
        if (!isAvailable)
        {
            isAvailable = true;
            cout << "Car " << model << " returned." << endl;
        }
        else
        {
            cout << "Car " << model << " was not rented." << endl;
        }
    }

    static double applyDiscount(double rate)
    {
        return rate * (1 - discountPercentage / 100);
    }

    // Method to display car details
    void displayDetails()
    {
        // to access the member variable of the current object.
        cout << "Car ID: " << this->carID << ", Model: " << 
        this->model << ", Availability: " << 
        (this->isAvailable ? "Yes" : "No") << endl;
    }
};

// Initializing static variables outside the class
int Car::totalCars = 0;
double Car::discountPercentage = 10.0; // Default discount of 10%

// User class
class User
{
public:
    int userID;
    string name;
    static int totalUsers;

    // Constructor
    User(int id, string nm)
        : userID(id), name(nm) {
        totalUsers++;
    }

    // Method to register the user
    void registerUser() {
        cout << "User " << this->name << " registered." << endl;
    }

    // Method to login the user
    void login() {
        cout << "User " << this->name << " logged in." << endl;
    }

    // Method to display user details
    void displayDetails() {
        cout << "User ID: " << this->userID << ", Name: " << this->name << endl;
    }
};

// Initializing static variables outside the class
int User::totalUsers = 0;

int main()
{
    // Creating an array of Car objects using dynamic memory allocation
    Car* car1 = new Car[3]{
        Car(101, "Toyota Corolla", true, 50.0),
        Car(102, "Honda Civic", true, 60.0),
        Car(103, "Ford Mustang", true, 80.0)
    };

    // Display car details before renting
    car1[1].displayDetails();

    // Using static function to apply discount
    double discountedRate = Car::applyDiscount(car1[1].rentalRate);
    cout << "Discounted Rental Rate for " << car1[1].model << ": $" << discountedRate << " per day" << endl;

    // Rent the car
    car1[1].rentCar();

    // Display car details after renting
    car1[1].displayDetails();

    // Creating an array of User objects using dynamic memory allocation
    User* user1 = new User[3]{
        User(41, "John"),
        User(42, "Linda"),
        User(43, "Alice")
    };

    // Register and login user
    user1[1].registerUser();
    user1[1].login();

    // Return the car
    car1[1].returnCar();

    // Display car details after returning
    car1[1].displayDetails();

    // Display the total number of cars and users
    cout << "Total Cars : " << Car::totalCars << endl;
    cout << "Total Users : " << User::totalUsers << endl;

    // Free up memory for car1 and user1 to avoid memory leaks
    delete[] car1;
    delete[] user1;
   

    return 0;
}
