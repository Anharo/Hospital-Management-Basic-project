Hospital Management System Readme
Overview
This Hospital Management System is a basic console application written in C++. It allows users to manage patient records, schedule appointments with different departments, calculate billing amounts, make payments, and store patient information in a text file.

Features
Patient Management
Add patient details (name, ID, age, department).
Schedule appointments with different medical departments (Ortho, Cardio, ENT, Neurology).
Calculate billing amount based on the selected department.
Billing and Payment
Calculate billing amount based on the department chosen during appointment scheduling.
Allow payments using a credit card.
Data Storage
Store patient records in a text file (patient_records.txt).
Usage
Compilation
Compile the code using a C++ compiler (e.g., g++).
Copy code
g++ hospital_management_system.cpp -o hospital_management_system
Execution
Run the compiled executable.
bash
Copy code
./hospital_management_system
Functionality
Enter the number of patient records you want to add.
Input patient details such as name, ID, age, and select the department for the appointment.
Calculate billing amount and make payment for the appointment.
Patient details will be stored in patient_records.txt.
File Structure
hospital_management_system.cpp: Contains the C++ code for the Hospital Management System.
patient_records.txt: Text file to store patient records.
Classes
Management
Handles appointment scheduling for different medical departments.
PatientDetails
Inherits from Management class and manages patient information, billing, payments, and display functions.
PatientRecords
Inherits from PatientDetails and handles writing patient details to the text file.
Additional Notes
The system currently supports four medical departments: Ortho, Cardio, ENT, and Neurology, with corresponding appointment charges.
Payment is simulated using a credit card and updates the payment status and method in the patient records.
The program loops to add multiple patient records until the user chooses to stop.
Example Run
yaml
Copy code
-------------------------------
WELCOME TO ANHARO HOSPITAL :)
-------------------------------
Enter number of records you want to enter:
2
Enter The Name of The Patient to be Admitted:
John Doe
Enter Id For Proof:
JD1234
Enter age:
35
Choose Department (Enter the corresponding number):
1. Ortho
2. Cardio
3. ENT
4. Neurology
1
Thank you. Your appointment has been fixed with Dr Sahil on the following Wednesday. Please proceed for payment for confirmation.
Enter Amount to be paid for appointment..
100
Payment of $100 successfully made via Credit Card
NAME: John Doe
ID: JD1234
Age: 35
Department: ortho
Billing Amount Remaining: $0
Payment Status: Paid
Payment Method: Credit Card
Should We Stop? 1 to 'Stop' 0 to 'Continue':
0
Enter The Name of The Patient to be Admitted:
Jane Smith
Enter Id For Proof:
JS5678
Enter age:
45
Choose Department (Enter the corresponding number):
1. Ortho
2. Cardio
3. ENT
4. Neurology
3
Thank you. Your appointment has been fixed with Dr Sarthak on the following Tuesday. Please proceed for payment for confirmation.
Enter Amount to be paid for appointment..
120
Payment of $120 successfully made via Credit Card
NAME: Jane Smith
ID: JS5678
Age: 45
Department: ent
Billing Amount Remaining: $0
Payment Status: Paid
Payment Method: Credit Card

Thankyou Entered total 2 entries..

Thank you for having us hope your speedy recovery
