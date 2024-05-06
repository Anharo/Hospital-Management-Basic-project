#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

class Management
{
public:
    int ortho()
    {
        char ort;
        cout << "Dr Sahil Thakur." << endl << "MBBS and MD Specialization in Orthology" << endl;
        cout << "Charges: $100 per Appointment" << endl;
        cout << "Press Y to proceed or N to return to the main menu" << endl;
        cin >> ort;
       if (ort == 'Y' || ort == 'y'){
            cout << "Thank you. Your appointment has been fixed with Dr Sahil on the following Wednesday. Please proceed for payment for confirmation." << endl;
        return 1;
        }
        else{
            cout << "Returning back to the main menu..." << endl;
            return 0;
        }
    }

    int cardio()
    {
        char crt;
        cout << "Dr Manish Singh." << endl << "MBBS and MD Specialization in Cardiology" << endl;
        cout << "Charges: $150 per Appointment" << endl;
        cout << "Press Y to proceed or N to return to the main menu" << endl;
        cin >> crt;
        if (crt == 'Y' || crt == 'y'){
            cout << "Thank you. Your appointment has been fixed with Dr Manish on the following Monday. Please proceed for payment for confirmation." << endl;
        return 1;
        }
        else{
            cout << "Returning back to the main menu..." << endl;
            return 0;
        }
    }

    int ent()
    {
        char ent;
        cout << "Dr Sarthak Thakur." << endl << "MBBS and MS Specialization in ENT" << endl;
        cout << "Charges: $120 per Appointment" << endl;
        cout << "Press Y to proceed or N to return to the main menu" << endl;
        cin >> ent;
        if (ent == 'Y' || ent == 'y'){
            cout << "Thank you. Your appointment has been fixed with Dr Sarthak on the following Tuesday. Please proceed for payment for confirmation." << endl;
        return 1;
        }
        else{
            cout << "Returning back to the main menu..." << endl;
            return 0;
        }
            
    }

    int neurology()
    {
        char neuro;
        cout << "Dr Vanshika." << endl << "MBBS and MD Specialization in Neurology" << endl;
        cout << "Charges: $200 per Appointment" << endl;
        cout << "Press Y to proceed or N to return to the main menu" << endl;
        cin >> neuro;
        if (neuro == 'Y' || neuro == 'y'){
            cout << "Thank you. Your appointment has been fixed with Dr Vanshika on the following Saturday. Please proceed for payment for confirmation." << endl;
        return 1;
        }
        else{
            cout << "Returning back to the main menu..." << endl;
            return 0;
        }
    }
    
};

class PatientDetails : public Management
{
protected:
    char id[20];
    char name[20];
    int age;
    char department[20];
    float billingAmount;
    bool paymentStatus;
    char paymentMethod[20];


public:
    int addPatient()
    {
        
        cout<<"Enter The Name of The Paitent to be Admitted: "<<endl;
        cin.ignore();
        cin.getline(name,sizeof(name));
        cout<<"Enter Id For Proof: "<<endl;
        cin.ignore();
        cin.getline(id,sizeof(id));
        cout<<"Enter age: "<<endl;
        cin>>age;
        cin.ignore();
        int k = 0;
    char departmentChoice;
    cout << "Choose Department (Enter the corresponding number): " << endl;
    cout << "1. Ortho" << endl;
    cout << "2. Cardio" << endl;
    cout << "3. ENT" << endl;
    cout << "4. Neurology" << endl;
    cin >> departmentChoice;

    switch (departmentChoice) {
        case '1':
            strcpy(department, "ortho");
            k = ortho();
            break;
        case '2':
            strcpy(department, "cardio");
            k = cardio();
            break;
        case '3':
            strcpy(department, "ent");
            k = ent();
            break;
        case '4':
            strcpy(department, "neurology");
            k = neurology();
            break;
        default:
            cout << "Invalid department choice!" << endl;
            return 0;
    }
            return k;
       
    }
    void calculateBilling() {
    float totalBilling = 0.0;

    if (strcmp(department, "ortho") == 0 || strcmp(department, "Ortho") == 0) {
        totalBilling += 100.0;  
    } else if (strcmp(department, "cardio") == 0 || strcmp(department, "Cardio") == 0) {
        totalBilling += 150.0;  
    } else if (strcmp(department, "ent") == 0 || strcmp(department, "ENT") == 0) {
        totalBilling += 120.0;  
    } else if (strcmp(department, "neurology") == 0 || strcmp(department, "Neurology") == 0) {
        totalBilling += 200.0;  
    } else {
        cout << "Department not recognized. Cannot calculate billing." << endl;
        return;
    }
    billingAmount = totalBilling;
}
void makePayment(float amount, const char* method) {
    if (!paymentStatus) {
        billingAmount -= amount; 
        paymentStatus = true;    
        strcpy(paymentMethod, method); 
        cout << "Payment of $" << amount << " successfully made via " << method << endl;
    } else {
        cout << "Payment already made for this patient!" << endl;
    }
}


    void displayPatients()
    {
      cout<<"NAME: "<<name<<endl;
      cout<<"ID: "<<id<<endl;
      cout<<"Age: "<<age<<endl;
      cout<<"Department: "<<department<<endl;
      cout << "Billing Amount Remaining: $" << billingAmount << endl;
      cout << "Payment Status: " << (paymentStatus ? "Paid" : "Pending") << endl;
      cout << "Payment Method: " << paymentMethod << endl;
    }
    friend class PatientRecords;
};

class PatientRecords : public PatientDetails {
public:
    void writeToFile(PatientDetails md) {
        ofstream outFile("patient_records.txt", ios::app| ios::out| ios::in);
         if (outFile.is_open()) {
            outFile << "Name: " << md.name << endl;
            outFile << "ID: " << md.id << endl;
            outFile << "Age: " << md.age << endl;
            outFile << "Department: " << md.department << endl;
            outFile << "---------------------------" << endl;
            
            cout << "Patient details written to file successfully!" << endl;
        }
        else {
            cout << "Error opening the file!" << endl;
        }

        outFile.close(); 
    }
    

};
int main()
{
    cout<<"-------------------------------"<<endl;
    cout<<"WELCOME TO ANHARO HOSPITAL :) "<<endl;
    cout<<"-------------------------------"<<endl;
    int y;
    cout<<"Enter number of records you want to enter:"<<endl;
    cin>>y;

    PatientRecords records[y];
    int o=0;
    while(o==0)
    {
    int l,op=0;
    l=records[op].addPatient();

    if(l==1)
    {
      records[op].writeToFile(records[op]);
    }
    else{
        cout<<"WE THANK YOU FOR YOU INFO WE HAVE NOW REMOVED YOUR INFORMATION FROM OUR DATABASE.."<<endl;
    }
    records[op].calculateBilling();
    int am=0;
    cout<<"Enter Amount to be paid for appointment.."<<endl;
    cin>>am;
    float paymentAmount = am;
    const char* paymentMethod = "Credit Card";
    records[op].makePayment(paymentAmount, paymentMethod);
    records[op].displayPatients();
    op++;
    if(op<y){
    cout<<"Should We Stop? 1 to 'Stop' 0 to 'Continue': "<<endl;
    cin>>o;
    }
    else{
    cout<<"\nThankyou Entered total " << op << " entries.."<<endl;
    o=1;
    }
 }
    
    cout<<"Thankyou for having us hope your speedy recovery";
    return 0;
}