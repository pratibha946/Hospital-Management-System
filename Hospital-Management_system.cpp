// Hospital Management System with Billing Functionality
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

struct patient_info {
    char name[20];
    char address[100];
    char contact[15];
    char age[5];
    char sex[8];
    char blood_gp[5];
    char disease_past[50];
    char id[15];
};

struct app {
    char symptom[500];
    char diagnosis[500];
    char medicine[500];
    char admission[30];
    char ward[15];
};

struct Billing {
    char patient_id[15];
    float treatment_cost;
    float room_charges;
    float other_charges;
    float total_cost;
};

int login();
void signUp();
void addBillingInfo();
void viewBillingInfo();

int main()
{
    char fname[20];
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Printing the welcome note
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
    cout << "\t\t\t\t\t@@|                                  WELCOME TO                                           |@@\n";
    cout << "\t\t\t\t\t@@|                           HOSPITAL MANAGEMENT SYSTEM                                  |@@\n";
    cout << "\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
    cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
    system("pause");
    system("cls");

    int choice;

    // Add option for Sign-Up and Login
    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\tHOSPITAL MANAGEMENT SYSTEM\n";
    cout << "\t\t\t\t\t---------------------------------\n";
    cout << "\t\t\t\t\t1. Login\n";
    cout << "\t\t\t\t\t2. Sign Up\n";
    cout << "\t\t\t\t\t---------------------------------\n";
    cout << "\t\t\t\t\tChoose an option: ";
    cin >> choice;
    system("cls");

    if (choice == 1) {
        if (!login()) {
            cout << "\nLogin Failed. Please try again.\n";
            system("pause");
            system("cls");
            main();
        }
    } else if (choice == 2) {
        signUp();
        system("pause");
        system("cls");
        main();
    } else {
        cout << "Invalid choice. Please try again.";
        system("pause");
        system("cls");
        main();
    }

    // Giving options to the user for hospital management system
    int i;
    b:
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM \n\n";
    cout << "\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
    cout << "\t\t\t\t\t\t _________________________________________________________________ \n";
    cout << "\t\t\t\t\t\t|             1  >> Add New Patient Record                        |\n";
    cout << "\t\t\t\t\t\t|             2  >> Add Diagnosis Information                     |\n";
    cout << "\t\t\t\t\t\t|             3  >> Full History of the Patient                   |\n";
    cout << "\t\t\t\t\t\t|             4  >> Information About the Hospital                |\n";
    cout << "\t\t\t\t\t\t|             5  >> Billing Information                           |\n";
    cout << "\t\t\t\t\t\t|             6  >> Exit the Program                              |\n";
    cout << "\t\t\t\t\t\t|_________________________________________________________________|\n\n";
    a:
    cout << "\t\t\t\t\t\tEnter your choice: ";
    cin >> i;

    if (i > 6 || i < 1) {
        cout << "\n\n\t\t\t\t\t\tInvalid Choice\n";
        cout << "\t\t\t\t\t\tTry again...........\n\n";
        goto a;
    }

    system("cls");

    // Displaying the information about the hospital........option 4
    if (i == 4) {
        ifstream file;
        file.open("hos.txt");
        if (!file) {
            cout << "\nError while opening the file\n";
            goto b;
        } else {
            cout << "\n\n\n\n\n\n\n\t\t\t\t\t   ...........................Information about the Hospital.............................\n\n";
            string line;
            while (getline(file, line)) {
                cout << line << "\n\t\t";
            }
            cout << "\n\n\t\t";
            system("pause");
            system("cls");
            goto b;
        }
    }

    // Adding the record of the new patient..................option 1
    if (i == 1) {
        time_t rawtime;
        struct tm *timeinfo;

        time(&rawtime);
        timeinfo = localtime(&rawtime);
        cout << "\n\n\t\t\t\t\t\t\t\t" << asctime(timeinfo);
        ofstream pat_file;
        cout << "\n\n\n\nEnter the patient's file name : ";
        cin.ignore();
        cin.getline(fname, 20);
        pat_file.open(fname);
        if (!pat_file) {
            cout << "\nError while opening the file\n";
            goto b;
        } else {
            patient_info ak;
            cout << "\n********************************************************************\n";
            pat_file << "\n********************************************************************\n\n";
            cout << "\nName : ";
            cin.getline(ak.name, 20);
            pat_file << "Name : " << ak.name << "\n";
            cout << "\nAddress : ";
            cin.getline(ak.address, 100);
            pat_file << "Address : " << ak.address << "\n";
            cout << "\nContact Number : ";
            cin.getline(ak.contact, 15);
            pat_file << "Contact Number : " << ak.contact << "\n";
            cout << "\nAge : ";
            cin.getline(ak.age, 5);
            pat_file << "Age : " << ak.age << "\n";
            cout << "\nSex : ";
            cin.getline(ak.sex, 8);
            pat_file << "Sex : " << ak.sex << "\n";
            cout << "\nBlood Group : ";
            cin.getline(ak.blood_gp, 5);
            pat_file << "Blood Group : " << ak.blood_gp << "\n";
            cout << "\nAny Major disease suffered earlier : ";
            cin.getline(ak.disease_past, 50);
            pat_file << "Any Major disease suffered earlier : " << ak.disease_past << "\n";
            cout << "\nPatient ID : ";
            cin.getline(ak.id, 15);
            pat_file << "Patient ID : " << ak.id << "\n";
            cout << "\n********************************************************************\n";
            pat_file << "\n********************************************************************\n\n";
            cout << "\nInformation Saved Successfully\n";
            pat_file.close();
        }
        system("pause");
        system("cls");
        goto b;
    }

    // Appending diagnosis information of patient datewise.................option 2
    if (i == 2) {
        fstream pat_file;
        cout << "\n\nEnter the patient's file name to be opened : ";
        cin.ignore();
        cin.getline(fname, 20);
        system("cls");
        pat_file.open(fname, ios::in);
        if (!pat_file) {
            cout << "\nError while opening the file\n";
            goto b;
        } else {
            cout << "\n\n\n\n\t\t\t\t........................................ Information about " << fname << " ........................................\n\n\n\n";
            string info;
            while (getline(pat_file, info)) {
                cout << info << "\n";
            }
            cout << "\n";
            pat_file.close();
            pat_file.open(fname, ios::out | ios::app);
            cout << "\n";
            time_t rawtime;
            struct tm *timeinfo;
            time(&rawtime);
            timeinfo = localtime(&rawtime);
            cout << "Adding more information in patient's file................on : " << asctime(timeinfo);
            pat_file << "Description on : " << asctime(timeinfo) << "\n";
            app add;
            cout << "\nSymptoms : ";
            cin.getline(add.symptom, 500);
            pat_file << "Symptoms : " << add.symptom << "\n";
            cout << "\nDiagnosis : ";
            cin.getline(add.diagnosis, 500);
            pat_file << "Diagnosis : " << add.diagnosis << "\n";
            cout << "\nMedicines : ";
            cin.getline(add.medicine, 500);
            pat_file << "Medicines : " << add.medicine << "\n";
            cout << "\nAdmission Required? : ";
            cin.getline(add.admission, 30);
            pat_file << "Admission Required? : " << add.admission << "\n";
            cout << "\nType of ward : ";
            cin.getline(add.ward, 15);
            pat_file << "Type of ward : " << add.ward << "\n";
            pat_file << "\n*************************************************************************\n";
            cout << "\n\n" << add.ward << " ward is alloted Successfully\n";
            pat_file.close();
            cout << "\n\n";
            system("pause");
            system("cls");
            goto b;
        }
    }

    // For displaying the full medical history of patient in that hospital............option 3
    if (i == 3) {
        fstream pat_file;
        cout << "\n\nEnter the patient's file name to be opened : ";
        cin.ignore();
        cin.getline(fname, 20);
        system("cls");
        pat_file.open(fname, ios::in);
        if (!pat_file) {
            cout << "\nError while opening the file\n";
            goto b;
        } else {
            cout << "\n\n\n\n\t\t\t\t........................................ Full Medical History of " << fname << " ........................................\n\n\n\n";
            string info;
            while (getline(pat_file, info)) {
                cout << info << "\n";
            }
            cout << "\n";
            pat_file.close();
        }
        system("pause");
        system("cls");
        goto b;
    }

    // Option 5: Billing Information
    if (i == 5) {
        int billing_choice;
        cout << "\n\nBilling Information Menu:\n";
        cout << "1. Add Billing Details\n";
        cout << "2. View Billing Details\n";
        cout << "Choose an option: ";
        cin >> billing_choice;

        if (billing_choice == 1) {
            addBillingInfo();  // Call function to add billing details
        } else if (billing_choice == 2) {
            viewBillingInfo();  // Call function to view billing details
        } else {
            cout << "Invalid choice. Returning to main menu.\n";
            system("pause");
        }
        goto b;
    }

    // Exiting Through the system with a Thank You note........................option 6
    if (i == 6) {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        cout << "\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
        cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
        cout << "\t\t\t\t\t@@|                               THANK YOU FOR USING                                     |@@\n";
        cout << "\t\t\t\t\t@@|                            HOSPITAL MANAGEMENT SYSTEM                                 |@@\n";
        cout << "\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
        cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
        return 0;
    }

    cout << "\n";

    return 0;
}

int login() {
    string username, password, stored_user, stored_pass;

    cout << "\n\n\n\n\n\n\n\t\t\t\t\tHOSPITAL MANAGEMENT SYSTEM \n\n";
    cout << "\t\t\t\t\t------------------------------";
    cout << "\n\t\t\t\t\t\t     LOGIN \n";
    cout << "\t\t\t\t\t------------------------------\n\n";
    cout << "\t\t\t\t\tEnter Username: ";
    cin >> username;

    cout << "\t\t\t\t\tEnter Password: ";
    cin >> password;  // Password will be entered normally

    // Open credentials file to check username and password
    ifstream infile("credentials.txt");
    bool loginSuccess = false;
    while (infile >> stored_user >> stored_pass) {
        if (stored_user == username && stored_pass == password) {
            loginSuccess = true;
            break;
        }
    }
    infile.close();

    if (loginSuccess) {
        cout << "\n\n\t\t\t\t\tAccess Granted! \n";
        system("PAUSE");
        system("CLS");
        return 1;
    } else {
        cout << "\n\n\t\t\t\t\tAccess Denied...\n\t\t\t\t\tPlease Try Again\n\n";
        return 0;
    }
}

// Function to handle user sign-up
void signUp() {
    string username, password;

    cout << "\n\n\n\n\n\n\n\t\t\t\t\tHOSPITAL MANAGEMENT SYSTEM \n\n";
    cout << "\t\t\t\t\t------------------------------";
    cout << "\n\t\t\t\t\t\t     SIGN UP \n";
    cout << "\t\t\t\t\t------------------------------\n\n";
    cout << "\t\t\t\t\tEnter Username: ";
    cin >> username;

    cout << "\t\t\t\t\tEnter Password: ";
    cin >> password;  // Password will be entered normally

    // Append new credentials to the file
    ofstream outfile("credentials.txt", ios::app);
    outfile << username << " " << password << endl;
    outfile.close();

    cout << "\n\n\t\t\t\t\tSign-Up Successful! You can now login.\n";
}

// Function to add billing information
void addBillingInfo() {
    Billing bill;
    char fname[20];

    cout << "\n\nEnter the patient's file name for billing: ";
    cin.ignore();
    cin.getline(fname, 20);

    ofstream billing_file(fname, ios::app);  // Open the patient's file in append mode
    if (!billing_file) {
        cout << "\nError while opening the file.\n";
        return;
    }

    // Input billing details
    cout << "\nEnter Patient ID: ";
    cin.getline(bill.patient_id, 15);

    cout << "Enter Treatment Cost: $";
    cin >> bill.treatment_cost;

    cout << "Enter Room Charges: $";
    cin >> bill.room_charges;

    cout << "Enter Other Charges: $";
    cin >> bill.other_charges;

    // Calculate total cost
    bill.total_cost = bill.treatment_cost + bill.room_charges + bill.other_charges;

    // Write billing details to file
    billing_file << "\n\n--- Billing Information ---\n";
    billing_file << "Patient ID: " << bill.patient_id << "\n";
    billing_file << "Treatment Cost: $" << fixed << setprecision(2) << bill.treatment_cost << "\n";
    billing_file << "Room Charges: $" << fixed << setprecision(2) << bill.room_charges << "\n";
    billing_file << "Other Charges: $" << fixed << setprecision(2) << bill.other_charges << "\n";
    billing_file << "Total Cost: $" << fixed << setprecision(2) << bill.total_cost << "\n";
    billing_file << "--------------------------------------------\n";

    billing_file.close();
    cout << "\nBilling information added successfully!\n";
    system("pause");
    system("cls");
}

// Function to view billing information
void viewBillingInfo() {
    char fname[20];
    cout << "\n\nEnter the patient's file name to view billing: ";
    cin.ignore();
    cin.getline(fname, 20);

    ifstream billing_file(fname);  // Open the patient's file for reading
    if (!billing_file) {
        cout << "\nError while opening the file.\n";
        return;
    }

    cout << "\n\n**** Billing Details ****\n\n";
    string line;
    bool billingSection = false;
    while (getline(billing_file, line)) {
        if (line.find("--- Billing Information ---") != string::npos) {
            billingSection = true;
        }
        if (billingSection) {
            cout << line << "\n";
            if (line.find("--------------------------------------------") != string::npos) {
                billingSection = false;
            }
        }
    }

    billing_file.close();
    cout << "\n\nEnd of billing details.\n";
    system("pause");
    system("cls");
}
M