#include <iostream>
#include <string>
using namespace std;

class Patient {
private:
    int patientId;
    string patientName;
    int age;
    float consultationCharge;

public:
        Patient(int id, string name, int a) {
        patientId = id;
        patientName = name;
        age = a;
        consultationCharge = 500;
    }

   
    void registerPatient() {
        cout << "Patient registered successfully!" << endl;
    }

    
    void calculateCharges() {
        consultationCharge = 500;

        if (age >= 60) {
            consultationCharge = 400;
        }
    }

   
    void displayPatient() {
        cout << "\nPatient ID: " << patientId << endl;
        cout << "Patient Name: " << patientName << endl;
        cout << "Age: " << age << endl;
        cout << "Consultation Charges: Rs. " << consultationCharge << endl;
    }
};

int main() {
    
    Patient p1(101, "Rahul", 65);

    p1.registerPatient();
    p1.calculateCharges();
    p1.displayPatient();

    return 0;
}