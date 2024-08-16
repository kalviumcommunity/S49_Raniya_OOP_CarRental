

# Car Rental System Simulation

## Project Title
**Car Rental System Simulation**

## Project Description
The Car Rental System Simulation is a simple console-based prototype that mimics a real-world car rental service. This project allows users to rent, return, and manage cars while tracking car availability, rental transactions, and user accounts. It effectively demonstrates key Object-Oriented Programming (OOP) concepts in a practical setting.

## Features

### Rent and Return Cars
- Browse available cars and choose one to rent.
- Updates car availability status once rented.
- Marks cars as available when returned.

### Manage Cars and User Accounts
- Maintains a list of cars with details such as model, type (SUV, Sedan), and availability.
- Tracks user information with unique IDs and their rental history.

### Track Rentals and Billing
- Logs each rental with details including the car rented, rental duration, and cost.
- Allows users to view their rental history.
- Calculates billing based on rental duration and car type.

## Programming Language
- **C++**

## OOP Concepts

### Classes & Objects
- **Car Class**: Represents individual cars in the system. Attributes include `carID`, `model`, `type`, `rentalRate`, and `isAvailable`.
- **Rental Class**: Manages rental transactions, including start date, end date, and associated car and user.
- **User Class**: Represents system users. Attributes include `userID`, `name`, `email`, and `rentalHistory`.

### This Pointer
- Used within the Rental class to manage references to the car being rented and the user renting the car. For example, `this->car` points to the car object associated with the current rental.

### Inheritance & Polymorphism
- The Car class can have derived classes such as **SUV** and **Sedan**. These classes inherit from the Car base class and may have additional attributes or methods specific to their type.
- Polymorphism allows the system to treat different car types (SUV, Sedan) uniformly when renting but enables specific behaviors based on the car type (e.g., different rental rates).

### Encapsulation & Abstraction
- **Encapsulation**: Hides the inner workings of the rental process, billing, and car management, exposing only the essential functions needed to interact with the system.
- **Abstraction**: Simplifies the car rental process by providing an easy-to-use interface, so users can rent and return cars without needing to understand the underlying complexities.

---
