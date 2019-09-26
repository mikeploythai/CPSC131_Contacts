#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string choice;

void options() {
    cout << "contactsCPP\n";
    cout << "==========\n";

    cout << "a) Make new contact(s)\n";
    cout << "b) View contact(s)\n";
    cout << "c) Exit\n";

    cout << endl;
    cout << "Choose an option: ";
    cin >> choice;
    cout << endl;
}

int main() {
    while(true) {
        // Options screen
        options();
        
        // Choice 'a'
        if (choice == "a") {
            int charNum = 1;

            ofstream outputFile;
            string fileName;

            // Ask for file name
            cout << "Please provide the filename for your contacts list: ";
            cin >> fileName;
            outputFile.open(fileName);
            cin.ignore();
            cout << endl;

            // Create contact
            string name;
            cout << "Contact " << charNum++ << ": " << endl;
            cout << "Name: ";
            getline(cin,name);

            // While loop until "Done"
            while(name != "Done") {
                outputFile << "Contact " << charNum - 1 << ": " << name << endl;

                string number;
                cout << "Number: ";
                cin >> number;
                cin.ignore();
                cout << endl;

                outputFile << "Number: " << number << endl << endl;;

                cout << "Contact " << charNum++ << ": " << endl;
                cout << "Name: ";
                getline(cin,name);
            }
            outputFile.close();
            
            // Saving
            cout << endl;
            cout << "Saving contacts into " << fileName << endl << endl;
            cout << "Done!" << endl << endl;

        // Choice 'b'
        } else if (choice == "b") {
            string phonebook;
            string line;
            ifstream inputFile;

            // Ask for file name
            cout << "Please provide the file name for your phonebook: ";
            cin >> phonebook;
            cout << endl;

            inputFile.open(phonebook);

            // If statement
            if(inputFile.good()) {
                if (inputFile.peek() == EOF) {
                    cout << "Phone book does not contain any contacts!\n";
                } else {
                    while(getline(inputFile,line)) {
                        cout << line << endl;
                    }
                }
            } else {
                cout << "Invalid phonebook file!\n";
            }
            inputFile.close();

        // Choice 'c'
        } else if (choice == "c") {
            break;
        }
    }
}