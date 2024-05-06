#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Define a Patient struct to store patient information
struct Patient {
    string name;
    string severity;
    int arrivalTime;

    // Custom comparison operator for priority queue (higher severity has higher priority)
    bool operator<(const Patient& other) const {
        if (severity != other.severity) {
            return (severity == "Serious"); // Serious has highest priority
        } else {
            return (arrivalTime > other.arrivalTime); // For same severity, earlier arrival has higher priority
        }
    }
};

int main() {
    priority_queue<Patient> patientQueue; // Priority queue to hold patients

    patientQueue.push({"Alice", "Serious", 0});
    patientQueue.push({"Bob", "Non-serious", 15});
    patientQueue.push({"Charlie", "General Checkup", 30});
    patientQueue.push({"David", "Serious", 45}); // Another Serious patient for testing

    cout << "Patients waiting (priority order):\n";
    while (!patientQueue.empty()) {
        Patient currentPatient = patientQueue.top();
        patientQueue.pop();

        cout << "Name: " << currentPatient.name << ", Severity: " << currentPatient.severity
             << ", Arrival Time: " << currentPatient.arrivalTime << endl;
    }
    return 0;
}
