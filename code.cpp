#include <iostream>
#include <string>
using namespace std;

//  Hospital Class

class Hospital
{
private:
    string name;
    string address;
    string contactNumber;

public:
    Hospital(string name, string address, string contractNumber)

    {
        this->name = name;
        this->address = address;
        this->contactNumber = contactNumber;
    }

    void displayInfo()
    {
        cout << "Hospital Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Contact Number: " << contactNumber << endl;
    }
};

// Patient Class

class Patient
{
public:
    int patientID;
    string name;
    int age;
    string gender;
    string contactInfo;

    Patient(int patientID, string name, int age, string gender, string contactInfo)
    {
        this->patientID = patientID;
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->contactInfo = contactInfo;
    }

    void displayInfo()
    {
        cout << "Patient ID: " << patientID << ", Name: " << name
             << ", Age: " << age << ", Gender: " << gender
             << ", Contact: " << contactInfo << endl;
    }
};

//  Doctor Class

class Doctor
{
public:
    int doctorID;
    string name;
    string specialization;
    string contactInfo;
    bool availability;

    Doctor(int doctorID, string name, string specialization, string contactInfo, bool availability)
    {
        this->doctorID = doctorID;
        this->name = name;
        this->specialization = specialization;
        this->contactInfo = contactInfo;
        this->availability = availability;
    }

    void displayInfo()
    {
        cout << "Doctor ID: " << doctorID << ", Name: " << name
             << ", Specialization: " << specialization
             << ", Contact: " << contactInfo
             << ", Availability: " << (availability ? "Yes" : "No") << endl;
    }
};

// Appointment Class

class Appointment
{
public:
    int appointmentID;
    int patientID;
    int doctorID;
    string date;
    string time;
    string status;

    Appointment(int appointmentID, int patientID, int doctorID, string date, string time, string status)
    {
        this->appointmentID = appointmentID;
        this->patientID = patientID;
        this->doctorID = doctorID;
        this->date = date;
        this->time = time;
        this->status = status;
    }

    void displayInfo()
    {
        cout << "Appointment ID: " << appointmentID
             << ", Patient ID: " << patientID
             << ", Doctor ID: " << doctorID
             << ", Date: " << date
             << ", Time: " << time
             << ", Status: " << status << endl;
    }
};

// MedicalRecord Class

class MedicalRecord
{
public:
    int recordID;
    int patientID;
    string diagnosis;
    string treatment;
    string notes;

    MedicalRecord(int recordID, int patientID, string diagnosis, string treatment, string notes)
    {
        this->recordID = recordID;
        this->patientID = patientID;
        this->diagnosis = diagnosis;
        this->treatment = treatment;
        this->notes = notes;
    }

    void displayInfo()
    {
        cout << "Record ID: " << recordID << ", Patient ID: " << patientID
             << ", Diagnosis: " << diagnosis << ", Treatment: " << treatment
             << ", Notes: " << notes << endl;
    }
};

// Linked List for Patients

class PatientList
{
private:
    struct Node
    {
        Patient *data;
        Node *next;

        Node(Patient *data)
        {
            this->data = data;
            this->next = nullptr;
        }
    };

    Node *head;

public:
    PatientList()
    {
        head = nullptr;
    }
    void addPatient(Patient *p)
    {
        Node *newNode = new Node(p);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void displayPatients()
    {
        if (!head)
        {
            cout << "No patients available.\n";
            return;
        }

        Node *temp = head;
        cout << "Patient List:\n";
        while (temp!=NULL)
        {
            temp->data->displayInfo();
            temp = temp->next;
        }
    }

    void removePatient(int id)
    {
        if (!head)
        {
            cout << "No patients to remove.\n";
            return;
        }

        Node *temp = head;
        Node *prev = nullptr;

        while (temp && temp->data->patientID != id)
        {
            prev = temp;
            temp = temp->next;
        }

        if (!temp)
        {
            cout << "Patient not found.\n";
            return;
        }

        if (!prev)
        {
            head = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }

        delete temp->data;
        delete temp;
        cout << "Patient removed successfully.\n";
    }
};

// Stack for Medical Records

class MedicalRecordStack
{
private:
    struct Node
    {
        MedicalRecord *data;
        Node *next;

        Node(MedicalRecord *data)
        {
            this->data = data;
            this->next = nullptr;
        }
    };

    Node *top;

public:
    MedicalRecordStack()
    {
        this->top = nullptr;
    }

    void push(MedicalRecord *r)
    {
        Node *newNode = new Node(r);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (!top)
        {
            cout << "No medical records to remove.\n";
            return;
        }

        Node *temp = top;
        top = top->next;

        delete temp->data;
        delete temp;

        cout << "Record removed successfully.\n";
    }

    void displayRecords()
    {
        if (!top)
        {
            cout << "No medical records available.\n";
            return;
        }

        Node *temp = top;
        cout << "Medical Records:\n";
        while (temp)
        {
            temp->data->displayInfo();
            temp = temp->next;
        }
    }
};

// Queue for Appointments

class AppointmentQueue
{
private:
    struct Node
    {
        Appointment *data;
        Node *next;

        Node(Appointment *data)
        {
            this->data = data;
            this->next = nullptr;
        }
    };

    Node *front;
    Node *rear;

public:
    AppointmentQueue()
    {
        this->front = nullptr;
        this->rear = nullptr;
    }

    void enqueue(Appointment *a)
    {
        Node *newNode = new Node(a);
        if (!rear)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Appointment scheduled successfully.\n";
    }

    void dequeue()
    {
        if (!front)
        {
            cout << "No appointments to remove.\n";
            return;
        }

        Node *temp = front;
        front = front->next;

        if (!front)
        {
            rear = nullptr;
        }

        delete temp->data;
        delete temp;

        cout << "Appointment removed successfully.\n";
    }

    void displayAppointments()
    {
        if (!front)
        {
            cout << "No appointments available.\n";
            return;
        }

        Node *temp = front;
        cout << "Appointments:\n";
        while (temp)
        {
            temp->data->displayInfo();
            temp = temp->next;
        }
    }
};
class Bill
{
public:
    int billID;
    int patientID;
    double amount;
    string details;

    Bill(int billID, int patientID, double amount, string details)
    {
        this->billID = billID;
        this->patientID = patientID;
        this->amount = amount;
        this->details = details;
    }

    void displayInfo()
    {
        cout << "Bill ID: " << billID
             << ", Patient ID: " << patientID
             << ", Amount: $" << amount
             << ", Details: " << details << endl;
    }
};

// BillList Class Linked List
class BillList
{
private:
    struct Node
    {
        Bill *data;
        Node *next;

        Node(Bill *data)
        {
            this->data = data;
            this->next = nullptr;
        }
    };

    Node *head;

public:
    BillList()
    {
        head = nullptr;
    }

    void addBill(Bill *b)
    {
        Node *newNode = new Node(b);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next!=nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Bill added successfully.\n";
    }

    void displayBills()
    {
        if (!head)
        {
            cout << "No bills available.\n";
            return;
        }

        Node *temp = head;
        cout << "Bills:\n";
        while (temp!=nullptr)
        {
            temp->data->displayInfo();
            temp = temp->next;
        }
    }
};

int main()
{
    PatientList patientList;
    MedicalRecordStack medicalRecords;
    AppointmentQueue appointments;
    BillList bills;

    int choice;

    while (true)
    {
        cout << "\n--- Hospital Management System ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Remove Patient\n";
        cout << "4. Add Medical Record\n";
        cout << "5. Display Medical Records\n";
        cout << "6. Schedule Appointment\n";
        cout << "7. Display Appointments\n";
        cout << "8. Generate Bill\n";
        cout << "9. Display Bills\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 10)
            break;

        switch (choice)
        {
        case 1:
        {
            int id, age;
            string name, gender, contact;
            cout << "Enter Patient ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Gender: ";
            cin.ignore();
            getline(cin, gender);
            cout << "Enter Contact Info: ";
            getline(cin, contact);
            patientList.addPatient(new Patient(id, name, age, gender, contact));
            break;
        }
        case 2:
            patientList.displayPatients();
            break;

        case 3:
        {
            int id;
            cout << "Enter Patient ID to remove: ";
            cin >> id;
            patientList.removePatient(id);
            break;
        }
        case 4:
        {
            int recordID, patientID;
            string diagnosis, treatment, notes;
            cout << "Enter Record ID: ";
            cin >> recordID;
            cout << "Enter Patient ID: ";
            cin >> patientID;
            cout << "Enter Diagnosis: ";
            cin.ignore();
            getline(cin, diagnosis);
            cout << "Enter Treatment: ";
            getline(cin, treatment);
            cout << "Enter Notes: ";
            getline(cin, notes);
            medicalRecords.push(new MedicalRecord(recordID, patientID, diagnosis, treatment, notes));
            break;
        }
        case 5:
            medicalRecords.displayRecords();
            break;

        case 6:
        {
            int appointmentID, patientID, doctorID;
            string date, time, status;
            cout << "Enter Appointment ID: ";
            cin >> appointmentID;
            cout << "Enter Patient ID: ";
            cin >> patientID;
            cout << "Enter Doctor ID: ";
            cin >> doctorID;
            cout << "Enter Date (YYYY-MM-DD): ";
            cin.ignore();
            getline(cin, date);
            cout << "Enter Time (HH:MM): ";
            getline(cin, time);
            status = "Scheduled";
            appointments.enqueue(new Appointment(appointmentID, patientID, doctorID, date, time, status));
            break;
        }
        case 7:
            appointments.displayAppointments();
            break;

        case 8:
        {
            int billID, patientID;
            double amount;
            string details;
            cout << "Enter Bill ID: ";
            cin >> billID;
            cout << "Enter Patient ID: ";
            cin >> patientID;
            cout << "Enter Amount: ";
            cin >> amount;
            cout << "Enter Bill Details: ";
            cin.ignore();
            getline(cin, details);
            bills.addBill(new Bill(billID, patientID, amount, details));
            break;
        }
        case 9:
            bills.displayBills();
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    system("Pause");
    return 0;
}
