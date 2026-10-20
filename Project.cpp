
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <cctype>

using namespace std;

// OOP: Encapsulation and Abstraction
class Vehicle {
private:
    int id;
    string model;
    double ratePerDay;
    bool available;

public:
    // Constructor
    Vehicle(int id, string model, double rate)
        : id(id), model(model), ratePerDay(rate), available(true) {}

    virtual ~Vehicle() = default;

    int getId() const { return id; }
    string getModel() const { return model; }
    double getRate() const { return ratePerDay; }
    bool isAvailable() const { return available; }

    void setAvailable(bool status) { available = status; }

    // Pure virtual functions: Abstraction
    virtual string getType() const = 0;
    virtual double calculateRentalCost(int days) const = 0;

    // Runtime polymorphism
    virtual void display() const {
        cout << left << setw(8) << id
             << setw(12) << getType()
             << setw(20) << model
             << "Rs. " << setw(10) << fixed << setprecision(2)
             << ratePerDay
             << (available ? "Available" : "Rented") << '\n';
    }
};

// Inheritance
class Car : public Vehicle {
public:
    Car(int id, string model, double rate)
        : Vehicle(id, model, rate) {}

    string getType() const override {
        return "Car";
    }

    double calculateRentalCost(int days) const override {
        return getRate() * days;
    }
};

class Bike : public Vehicle {
public:
    Bike(int id, string model, double rate)
        : Vehicle(id, model, rate) {}

    string getType() const override {
        return "Bike";
    }

    double calculateRentalCost(int days) const override {
        return getRate() * days;
    }
};

// Stores one rental transaction
struct RentalRecord {
    int vehicleId;
    string customer;
    string model;
    string type;
    int days;
    double cost;
};

class RentalSystem {
private:
    vector<unique_ptr<Vehicle>> vehicles;
    vector<RentalRecord> rentalHistory;

    // Function overloading: search by ID
    Vehicle* findVehicle(int id) {
        for (auto& v : vehicles) {
            if (v->getId() == id)
                return v.get();
        }
        return nullptr;
    }

    // Function overloading: search by type
    vector<Vehicle*> findVehicle(string type) {
        vector<Vehicle*> result;

        transform(type.begin(), type.end(), type.begin(),
                  [](unsigned char c) {
                      return static_cast<char>(tolower(c));
                  });

        for (auto& v : vehicles) {
            string current = v->getType();

            transform(current.begin(), current.end(),
                      current.begin(), [](unsigned char c) {
                          return static_cast<char>(tolower(c));
                      });

            if (current == type)
                result.push_back(v.get());
        }

        return result;
    }

    void addDefaultVehicles() {
        vehicles.push_back(make_unique<Car>(101, "Swift", 1500));
        vehicles.push_back(make_unique<Car>(102, "Creta", 2500));
        vehicles.push_back(make_unique<Bike>(201, "Activa", 500));
        vehicles.push_back(make_unique<Bike>(202, "Pulsar", 800));
    }

    // Load vehicle data from a text file
    void loadVehicles() {
        ifstream file("vehicles.txt");

        if (!file) {
            addDefaultVehicles();
            return;
        }

        string line;

        while (getline(file, line)) {
            stringstream ss(line);

            int id, status;
            double rate;
            string type, model;

            if (!(ss >> id >> type >> model >> rate >> status))
                continue;

            unique_ptr<Vehicle> v;

            if (type == "Car")
                v = make_unique<Car>(id, model, rate);
            else if (type == "Bike")
                v = make_unique<Bike>(id, model, rate);
            else
                continue;

            v->setAvailable(status == 1);
            vehicles.push_back(move(v));
        }

        if (vehicles.empty())
            addDefaultVehicles();
    }

    // Save vehicle data to a text file
    void saveVehicles() const {
        ofstream file("vehicles.txt");

        for (const auto& v : vehicles) {
            file << v->getId() << ' '
                 << v->getType() << ' '
                 << v->getModel() << ' '
                 << v->getRate() << ' '
                 << (v->isAvailable() ? 1 : 0)
                 << '\n';
        }
    }

    void showVehicleList(const vector<Vehicle*>& list) const {
        cout << left << setw(8) << "ID"
             << setw(12) << "Type"
             << setw(20) << "Model"
             << setw(16) << "Rate/Day"
             << "Status\n";

        cout << string(66, '-') << '\n';

        for (const auto* v : list)
            v->display();
    }

    static int readInt(const string& prompt) {
        int value;

        while (true) {
            cout << prompt;

            if (cin >> value) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }

            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

public:
    RentalSystem() {
        loadVehicles();
    }

    ~RentalSystem() {
        saveVehicles();
    }

    void showAllVehicles() const {
        cout << "\n--- ALL VEHICLES ---\n";

        vector<Vehicle*> list;

        for (const auto& v : vehicles)
            list.push_back(v.get());

        showVehicleList(list);
    }

    void searchMenu() {
        cout << "\n1. Search by vehicle ID\n";
        cout << "2. Search by vehicle type\n";

        int choice = readInt("Enter choice: ");

        if (choice == 1) {
            int id = readInt("Enter vehicle ID: ");
            Vehicle* v = findVehicle(id);

            if (v)
                v->display();
            else
                cout << "Vehicle not found.\n";
        }
        else if (choice == 2) {
            string type;

            cout << "Enter type (Car/Bike): ";
            getline(cin, type);

            auto results = findVehicle(type);

            if (results.empty())
                cout << "No matching vehicles found.\n";
            else
                showVehicleList(results);
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    void rentVehicle() {
        cout << "\n--- RENT A VEHICLE ---\n";

        vector<Vehicle*> available;

        for (const auto& v : vehicles) {
            if (v->isAvailable())
                available.push_back(v.get());
        }

        if (available.empty()) {
            cout << "No vehicles are currently available.\n";
            return;
        }

        showVehicleList(available);

        int id = readInt("Enter vehicle ID: ");
        Vehicle* v = findVehicle(id);

        if (!v) {
            cout << "Vehicle not found.\n";
            return;
        }

        if (!v->isAvailable()) {
            cout << "This vehicle is already rented.\n";
            return;
        }

        string customer;

        cout << "Enter customer name: ";
        getline(cin, customer);

        if (customer.find_first_not_of(" \t") == string::npos) {
            cout << "Customer name cannot be empty.\n";
            return;
        }

        int days = readInt("Enter number of rental days: ");

        if (days <= 0 || days > 365) {
            cout << "Days must be between 1 and 365.\n";
            return;
        }

        double cost = v->calculateRentalCost(days);

        v->setAvailable(false);

        rentalHistory.push_back({
            id, customer, v->getModel(),
            v->getType(), days, cost
        });

        saveVehicles();

        cout << fixed << setprecision(2);
        cout << "\nRental successful!\n";
        cout << "Customer: " << customer << '\n';
        cout << "Vehicle: " << v->getModel() << '\n';
        cout << "Duration: " << days << " day(s)\n";
        cout << "Total rent: Rs. " << cost << '\n';
    }

    void returnVehicle() {
        cout << "\n--- RETURN A VEHICLE ---\n";

        int id = readInt("Enter vehicle ID: ");
        Vehicle* v = findVehicle(id);

        if (!v) {
            cout << "Vehicle not found.\n";
            return;
        }

        if (v->isAvailable()) {
            cout << "This vehicle is not currently rented.\n";
            return;
        }

        v->setAvailable(true);
        saveVehicles();

        cout << v->getModel()
             << " returned successfully!\n";
    }

    void showRentalHistory() const {
        cout << "\n--- RENTAL HISTORY (CURRENT SESSION) ---\n";

        if (rentalHistory.empty()) {
            cout << "No rentals recorded in this session.\n";
            return;
        }

        double total = 0;

        cout << fixed << setprecision(2);

        for (const auto& r : rentalHistory) {
            cout << "\nVehicle ID: " << r.vehicleId
                 << "\nCustomer: " << r.customer
                 << "\nVehicle: " << r.type << " " << r.model
                 << "\nDays: " << r.days
                 << "\nCost: Rs. " << r.cost << '\n';

            total += r.cost;
        }

        cout << "\nTotal rental value: Rs. " << total << '\n';
    }

    void run() {
        int choice;

        do {
            cout << "\n==============================\n";
            cout << " VEHICLE RENTAL MANAGEMENT\n";
            cout << "==============================\n";
            cout << "1. View all vehicles\n";
            cout << "2. Search vehicles\n";
            cout << "3. Rent a vehicle\n";
            cout << "4. Return a vehicle\n";
            cout << "5. View rental history\n";
            cout << "0. Exit\n";

            choice = readInt("Enter your choice: ");

            switch (choice) {
                case 1:
                    showAllVehicles();
                    break;
                case 2:
                    searchMenu();
                    break;
                case 3:
                    rentVehicle();
                    break;
                case 4:
                    returnVehicle();
                    break;
                case 5:
                    showRentalHistory();
                    break;
                case 0:
                    saveVehicles();
                    cout << "Thank you for using the system!\n";
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 0);
    }
};

int main() {
    RentalSystem system;
    system.run();
    return 0;
}
