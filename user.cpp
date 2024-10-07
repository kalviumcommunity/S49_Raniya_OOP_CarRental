class User {
private:
    int userID;
    string name;

public:
    static int totalUsers; // Declaration

    // Constructor
    User(int userID, string name) {
        setUserID(userID);
        setName(name);
        totalUsers++;
    }

    // Accessor methods
    int getUserID() const {
        return userID;
    }

    string getName() const {
        return name;
    }

    // Mutator methods
    void setUserID(int id) {
        userID = id;
    }

    void setName(const string& nm) {
        name = nm;
    }

    // Method to register the user
    void registerUser() {
        cout << "User " << name << " registered." << endl;
    }

    // Method to login the user
    void login() {
        cout << "User " << name << " logged in." << endl;
    }

    // Method to display user details
    void displayDetails() const {
        cout << "User ID: " << getUserID() << ", Name: " << getName() << endl;
    }
};

// Initialize static variables
int User::totalUsers = 0; // Definition