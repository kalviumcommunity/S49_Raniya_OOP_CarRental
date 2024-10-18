class User {

//user should not be able to modify them directly hence they are private 
private:
    int userID;
    string name;


//all action functions like register , login  accessors and mutators to control how user data is accessed and modified. 
public:
    static int totalUsers; 

    //default constructor
    User() {
        userID = 0;
        name = "default";
      
    }

    // parameterized Constructor
    User(int userID, string name) {
        setUserID(userID);
        setName(name);
        totalUsers++;
    }

    // Destructor
    ~User() {        
        totalUsers--;
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
int User::totalUsers = 0;