// C++ Program to implement the to do list
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define Place class
class Place {
private:
    string name; // Place name
    string description; // Place description
    string date; // Place when you went
    bool goback; // Place completion status

public:
    // Constructor to initialize a Place
    Place(const string& name, const string& description,
        const string& date)
        : name(name)
        , description(description)
        , date(date)
        , goback(false)
    {
    }

    // Getter for Place name
    string getName() const { return name; }

    // Getter for Place description
    string getDescription() const { return description; }

    // Getter for Place when you went
    string getDate() const { return date; }

    // Getter for Place completion status
    bool isGoback() const { return goback; }

    // Setter for Place name
    void setName(const string& name) { this->name = name; }

    // Setter for Place description
    void setDescription(const string& description)
    {
        this->description = description;
    }

    // Setter for Place when you went
    void setDate(const string& date)
    {
        this->date = date;
    }

    // Mark the Place as goback
    void markGoback() { goback = true; }

    // Display Place details
    void displayPlace() const
    {
        cout << name << " ("
            << (goback ? "Goback" : "Pending")
            << ") - Due: " << date << endl
            << "   Description: " << description << endl;
    }
};

// Define ToDoList class
class ToDoList {
private:
    vector<Place> Places; // List of Places

public:
    // Display the menu
    void displayMenu()
    {
        cout
            << "\n---------- Places I Have Been -----------\n";
        cout << "1. Add Place\n";
        cout << "2. Delete Place\n";
        cout << "3. Display Places\n";
        cout << "4. Places to go back to\n";
        cout << "5. Edit Place\n";
        cout << "6. Exit\n";
        cout << "-----------------------------------------"
            "\n";
    }

    // Add a new Place
    void addPlace()
    {
        string name, description, date;
        cout << "Enter name of place: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter description of place: ";
        getline(cin, description);
        cout << "Enter date of visit (YYYY-MM-DD): ";
        getline(cin, date);

        Places.emplace_back(name, description, date);
        cout << "Place added successfully!" << endl;
    }

    // Delete a Place
    void deletePlace()
    {
        if (Places.empty()) {
            cout << "No Places to delete!" << endl;
            return;
        }
        cout << "Places:" << endl;
        for (int i = 0; i < Places.size(); ++i) {
            cout << i + 1 << ". " << Places[i].getName()
                << endl;
        }
        cout << "Enter the Place number to delete: ";
        int PlaceNumber;
        cin >> PlaceNumber;
        if (PlaceNumber >= 1 && PlaceNumber <= Places.size()) {
            Places.erase(Places.begin() + PlaceNumber - 1);
            cout << "Place deleted successfully!" << endl;
        }
        else {
            cout << "Invalid Place number!" << endl;
        }
    }

    // Display all Places
    void displayPlaces()
    {
        if (Places.empty()) {
            cout << "No Places to display!" << endl;
            return;
        }
        cout << "Places:" << endl;
        for (int i = 0; i < Places.size(); ++i) {
            cout << i + 1 << ". ";
            Places[i].displayPlace();
        }
    }

    // Mark a Place as goback
    void markPlaceGoback()
    {
        if (Places.empty()) {
            cout << "No Places to go back to!"
                << endl;
            return;
        }
        cout << "Places:" << endl;
        for (int i = 0; i < Places.size(); ++i) {
            cout << i + 1 << ". " << Places[i].getName()
                << endl;
        }
        cout << "Enter the Place number to mark as "
            "goback: ";
        int PlaceNumber;
        cin >> PlaceNumber;
        if (PlaceNumber >= 1 && PlaceNumber <= Places.size()) {
            Places[PlaceNumber - 1].markGoback();
            cout << "Place marked as goback!" << endl;
        }
        else {
            cout << "Invalid Place number!" << endl;
        }
    }

    // Edit a Place
    void editPlace()
    {
        if (Places.empty()) {
            cout << "No Places to edit!" << endl;
            return;
        }
        cout << "Places:" << endl;
        for (int i = 0; i < Places.size(); ++i) {
            cout << i + 1 << ". " << Places[i].getName()
                << endl;
        }
        cout << "Enter the Place number to edit: ";
        int PlaceNumber;
        cin >> PlaceNumber;
        if (PlaceNumber >= 1 && PlaceNumber <= Places.size()) {
            Place& Place = Places[PlaceNumber - 1];
            string name, description, date;
            cout << "Enter new Place name (current: "
                << Place.getName() << "): ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter new Place description (current: "
                << Place.getDescription() << "): ";
            getline(cin, description);
            cout << "Enter new date of visit (current: "
                << Place.getDate() << "): ";
            getline(cin, date);

            Place.setName(name);
            Place.setDescription(description);
            Place.setDate(date);
            cout << "Place updated successfully!" << endl;
        }
        else {
            cout << "Invalid Place number!" << endl;
        }
    }

    // Run the to-do list application
    void run()
    {
        int choice;
        do {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                addPlace();
                break;
            case 2:
                deletePlace();
                break;
            case 3:
                displayPlaces();
                break;
            case 4:
                markPlaceGoback();
                break;
            case 5:
                editPlace();
                break;
            case 6:
                cout << "Exiting program. Bye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again!"
                    << endl;
            }
        } while (choice != 6);
    }
};

// Main function
int main()
{
    // Create a ToDoList object and run the application
    ToDoList toDoList;
    toDoList.run();
    return 0;
}


