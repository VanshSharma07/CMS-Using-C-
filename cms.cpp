#include <iostream>
using namespace std;

const int MAX_CUSTOMERS = 100;
const int MAX_CONTACTS = 100;
const int MAX_LEADS = 100;
const int MAX_TASKS = 100;

// Forward Declaration
class Customer;
class Contact;
class Lead;
class Task;

class Customer {
private:
    string name;
    string email;
    string phone;

public:
    Customer() {
        name = "";
        email = "";
        phone = "";
    }

    Customer(const string& name, const string& email, const string& phone) {
        this->name = name;
        this->email = email;
        this->phone = phone;
    }

    string getName() const {
        return name;
    }

    void updateInformation(const string& name, const string& email, const string& phone) {
        this->name = name;
        this->email = email;
        this->phone = phone;
    }

    void displayInformation() const {
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl;
    }
};

class Contact {
private:
    string name;
    string email;
    string phone;

public:
    Contact() {
        name = "";
        email = "";
        phone = "";
    }

    Contact(const string& name, const string& email, const string& phone) {
        this->name = name;
        this->email = email;
        this->phone = phone;
    }

    string getName() const {
        return name;
    }

    void updateInformation(const string& name, const string& email, const string& phone) {
        this->name = name;
        this->email = email;
        this->phone = phone;
    }

    void displayInformation() const {
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl;
    }
};

class Lead {
private:
    string name;
    string email;
    string phone;
    bool converted;

public:
    Lead() {
        name = "";
        email = "";
        phone = "";
    }

    Lead(const string& name, const string& email, const string& phone) {
        this->name = name;
        this->email = email;
        this->phone = phone;
    }

    void convertLead() {
        if (converted) {
            cout << "This lead is already converted." << endl;
        } else {
            converted = true;
            cout << "Lead converted to customer!" << endl;
        }
    }

    string getName() const {
        return name;
    }

    void trackLeadStatus() const {
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl;
        if (converted) {
            cout << "Lead status: Converted to customer" << endl;
        } else {
            cout << "Lead status: Potential customer" << endl;
        }
    }

    void displayInformation() const {
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl;
    }
};

class Task {
private:
    string description;
    string dueDate;
    bool completed;

public:
    Task() {
        description = "";
        dueDate = "";
        completed = false;
    }

    Task(const string& description, const string& dueDate) {
        this->description = description;
        this->dueDate = dueDate;
        completed = false;
    }

    string getDescription() const {
        return description;
    }

    void updateDescription(const string& description) {
        this->description = description;
    }

    void updateDueDate(const string& dueDate) {
        this->dueDate = dueDate;
    }

    void markAsComplete() {
        completed = true;
    }

    void displayInformation() const {
        cout << "Description: " << description << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "Status: " << (completed ? "Completed" : "Incomplete") << endl;
    }
};

void displayAllCustomers(const Customer customers[], int numCustomers);
void displayAllContacts(const Contact contacts[], int numContacts);
void displayAllLeads(const Lead leads[], int numLeads);
void displayAllTasks(const Task tasks[], int numTasks);

int main() {
    Customer customers[MAX_CUSTOMERS];
    int numCustomers = 0;

    Contact contacts[MAX_CONTACTS];
    int numContacts = 0;

    Lead leads[MAX_LEADS];
    int numLeads = 0;

    Task tasks[MAX_TASKS];
    int numTasks = 0;

    string option;
    char option_2;
    char option_3;
    char option_4;

    string email, phone, name, description, dueDate;

    do {
        cout << "                        Welcome to my  " << endl;
        cout << "           Customer Relationship Management System" << endl;
        cout << "              *** Developed by VANSH ***" << endl << endl;

        cout << "1. Customer Functions" << endl;
        cout << "2. Contact Functions" << endl;
        cout << "3. Lead Functions" << endl;
        cout << "4. Task Functions" << endl << endl;

        cout << "If you want to exit, please type 'Exit' ..." << endl << endl;
        cout << "Dear user, please enter the option number you want to use/test = ";
        cin >> option;

        if (option == "1") {
            do {
                cout << endl << endl;
                cout << "Dear user, you are now in the CUSTOMER FUNCTIONS TAB" << endl << endl;
                cout << "1. Add a new customer" << endl;
                cout << "2. Update an existing customer" << endl;
                cout << "3. Delete a customer" << endl;
                cout << "4. Display all the customers" << endl << endl;

                cout << "If you want to go to the previous screen, just press 'P' ..." << endl;
                cout << "Please enter the option number you want to use = ";
                cin >> option_2;

                switch (option_2) {
                    case '1':
                        if (numCustomers < MAX_CUSTOMERS) {
                            cout << "Enter the name of the customer: ";
                            cin.ignore();
                            getline(cin, name);

                            cout << "Enter the email of the customer: ";
                            getline(cin, email);

                            cout << "Enter the phone number of the customer: ";
                            getline(cin, phone);

                            customers[numCustomers] = Customer(name, email, phone);
                            numCustomers++;

                            cout << "Customer added." << endl;
                        } else {
                            cout << "Maximum number of customers reached." << endl;
                        }
                        break;

                    case '2':
                        cout << "Enter the name of the customer to update: ";
cin.ignore();
                        getline(cin, name);

                        // Find the customer with the given name
                        for (int i = 0; i < numCustomers; i++) {
                            if (customers[i].getName() == name) {
                                cout << "Enter the updated name of the customer: ";
                                getline(cin, name);

                                cout << "Enter the updated email of the customer: ";
                                getline(cin, email);

                                cout << "Enter the updated phone number of the customer: ";
                                getline(cin, phone);

                                // Update customer information using the updateInformation function
                                customers[i].updateInformation(name, email, phone);
                                cout << "Customer updated." << endl;
                                break;
                            }
                        }
                        break;

                    case '3':
                        cout << "Enter the name of the customer to delete: ";
                        cin.ignore();
                        getline(cin, name);

                        // Find the customer with the given name
                        for (int i = 0; i < numCustomers; i++) {
                            if (customers[i].getName() == name) {
                                // Shift the remaining customers to fill the gap
                                for (int j = i; j < numCustomers - 1; j++) {
                                    customers[j] = customers[j + 1];
                                }
                                numCustomers--;

                                cout << "Customer deleted." << endl;
                                break;
                            }
                        }
                        break;

                    case '4':
                        displayAllCustomers(customers, numCustomers);
                        break;

                    case 'P':
                    case 'p':
                        break;

                    default:
                        cout << "Invalid option. Please try again." << endl;
                }
            } while (option_2 != 'P' && option_2 != 'p');
        } else if (option == "2") {
            do {
                cout << endl << endl;
                cout << "Dear user, you are now in the CONTACT FUNCTIONS TAB" << endl << endl;
                cout << "1. Add a new contact" << endl;
                cout << "2. Update an existing contact" << endl;
                cout << "3. Delete a contact" << endl;
                cout << "4. Display all the contacts" << endl << endl;

                cout << "If you want to go to the previous screen, just press 'P' ..." << endl;
                cout << "Please enter the option number you want to use = ";
                cin >> option_3;

                switch (option_3) {
                    case '1':
                        if (numContacts < MAX_CONTACTS) {
                            cout << "Enter the name of the contact: ";
                            cin.ignore();
                            getline(cin, name);

                            cout << "Enter the email of the contact: ";
                            getline(cin, email);

                            cout << "Enter the phone number of the contact: ";
                            getline(cin, phone);

                            contacts[numContacts] = Contact(name, email, phone);
                            numContacts++;

                            cout << "Contact added." << endl;
                        } else {
                            cout << "Maximum number of contacts reached." << endl;
                        }
                        break;

                    case '2':
                        cout << "Enter the name of the contact to update: ";
                        cin.ignore();
                        getline(cin, name);

                        // Find the contact with the given name
                        for (int i = 0; i < numContacts; i++) {
                            if (contacts[i].getName() == name) {
                                cout << "Enter the updated name of the contact: ";
                                getline(cin, name);

                                cout << "Enter the updated email of the contact: ";
                                getline(cin, email);

                                cout << "Enter the updated phone number of the contact: ";
                                getline(cin, phone);

                                // Update contact information using the updateInformation function
                                contacts[i].updateInformation(name, email, phone);
                                cout << "Contact updated." << endl;
                                break;
                            }
                        }
                        break;

                    case '3':
                        cout << "Enter the name of the contact to delete: ";
                        cin.ignore();
                        getline(cin, name);

                        // Find the contact with the given name
                        for (int i = 0; i < numContacts; i++) {
                            if (contacts[i].getName() == name) {
                                // Shift the remaining contacts to fill the gap
                                for (int j = i; j < numContacts - 1; j++) {
                                    contacts[j] = contacts[j + 1];
                                }
                                numContacts--;

                                cout << "Contact deleted." << endl;
                                break;
                            }
                        }
                        break;

                    case '4':
                        displayAllContacts(contacts, numContacts);
                        break;

                    case 'P':
                    case 'p':
                        break;

                    default:
                        cout << "Invalid option. Please try again." << endl;
                }
            } while (option_3 != 'P' && option_3 != 'p');
        } else if (option == "3") {
            do {
                cout << endl << endl;
                cout << "Dear user, you are now in the LEAD FUNCTIONS TAB" << endl << endl;
                cout << "1. Add a new lead" << endl;
                cout << "2. Convert a Lead" << endl;
                cout << "3. Track Lead status" << endl << endl;

                cout << "If you want to go to the previous screen, just press 'P' ..." << endl;
                cout << "Please enter the option number you want to use = ";
                cin >> option_4;

                switch (option_4) {
                    case '1':
                        if (numLeads < MAX_LEADS) {
                            cout << "Enter the name of the lead: ";
                            cin.ignore();
                            getline(cin, name);

                            cout << "Enter the email of the lead: ";
                            getline(cin, email);

                            cout << "Enter the phone number of the lead: ";
                            getline(cin, phone);

                            leads[numLeads] = Lead(name, email, phone);
                            numLeads++;

                            cout << "Lead added." << endl;
                        } else {
                            cout << "Maximum number of leads reached." << endl;
                        }
                        break;

                    case '2':
                        cout << "Enter the name of the lead to convert: ";
                        cin.ignore();
                        getline(cin, name);

                        // Find the lead with the given name
                        for (int i = 0; i < numLeads; i++) {
                            if (leads[i].getName() == name) {
                                leads[i].convertLead();
                                cout << "Lead converted." << endl;
                                break;
                            }
                        }
                        break;

                    case '3':
                        cout << "Enter the name of the lead to track: ";
                        cin.ignore();
                        getline(cin, name);

                        // Find the lead with the given name
                        for (int i = 0; i < numLeads; i++) {
                            if (leads[i].getName() == name) {
                                leads[i].trackLeadStatus();
                                break;
                            }
                        }
                        break;

                    case 'P':
                    case 'p':
                        break;

                    default:
                        cout << "Invalid option. Please try again." << endl;
                }
            } while (option_4 != 'P' && option_4 != 'p');
        } else if (option == "4") {
            // Task Functions
            // ...
        } else if (option == "Exit" || option == "exit"){
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    } while (option != "Exit" && option != "exit");

    return 0;
}

void displayAllCustomers(const Customer customers[], int numCustomers) {
    cout << "All Customers: " << endl;
    for (int i = 0; i < numCustomers; i++) {
        customers[i].displayInformation();
        cout << endl;
    }
}

void displayAllContacts(const Contact contacts[], int numContacts) {
    cout << "All Contacts: " << endl;
    for (int i = 0; i < numContacts; i++) {
        contacts[i].displayInformation();
        cout << endl;
    }
}

void displayAllLeads(const Lead leads[], int numLeads) {
    cout << "All Leads: " << endl;
    for (int i = 0; i < numLeads; i++) {
        leads[i].displayInformation();
        cout << endl;
    }
}

void displayAllTasks(const Task tasks[], int numTasks) {
    cout << "All Tasks: " << endl;
    for (int i = 0; i < numTasks; i++) {
        tasks[i].displayInformation();
        cout << endl;
    }
}