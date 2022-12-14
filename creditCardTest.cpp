#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/* Step 0. */
// Read customer information from external file
// Make no changes to the following code
void ReadCustomerData(vector<string>& names, vector<string>& states, vector<double>& debt) {
    // Create Variable
    ifstream inFS;

    // Read all data from file into three parallel vectors
    try {
        // Open File
        inFS.open("CustomerData.txt");

        // Add Data From File
        for (long unsigned index = 0; index < names.size(); ++index) {
            inFS >> names.at(index); // last name
            inFS >> states.at(index); // state of residence
            inFS >> debt.at(index);   // amount of debt
        }//end for-loop
    } catch (string err) {
        // File Not Found
        cout << "Failed to read the data file: " << err << endl;
    }//end try-catch

    // Close File
    inFS.close();

    // Test Code
    // cout << "Names: " << endl;
    // for (int i = 0; i < 1000; i++) {
    //     cout << names.at(i) << endl;
    // }//end for-each
    // cout << "Debt: " << endl;
    // for (int i = 0; i < 5; i++) {
    //     cout << debt.at(i) << endl;
    // }//end for-each
    // cout << "States: " << endl;
    // for (int i = 0; i < 5; i++) {
    //     cout << states.at(i) << endl;
    // }//end for-each
    // // 
}//end ReadCustomerData()

// Just used to Test Step 1
void printInputs(int &numOfCustomers, int &debtLimit, char &firstLetterOfCustomerName, string &stateAbbrev) {
    cout << "\nTest Inputs: " << endl;
    cout << "Number of Customers: " << numOfCustomers << endl;
    cout << "Debt Limit: " << debtLimit << endl;
    cout << "First Initial Letter: " << firstLetterOfCustomerName << endl;
    cout << "State Abbreviation: " << stateAbbrev << endl;
}//end printInputs()

/* Step 2. */
// Print Customer with Highest Debt
void printNameWithMaxDebt(vector<double> &debt, vector<string> &names, int numOfCustomers) {
    // Step 2 Variables
    string name = names[0];
    double maxDebt = debt[0];

    // Loop through Debt and Names to find the Customer with the Highest Debt
    for (unsigned long i = 1; i < numOfCustomers; i++) {
        if (maxDebt < debt[i]) {
            maxDebt = debt[i];
            name = names[i];
        }//end if
    }//end for-loop

    // Output
    cout << "Customers: " << numOfCustomers << endl;
    cout << "Highest Debt: " << name << endl;
}//end printNameWithMaxDebt()

/* Step 3. */
// Print the Number of Customer Names that Start with Inputted Letter
void printNumOfNamesWithLetter(vector<string> &names, int numOfCustomers, char firstLetterOfCustomerName) {
    // Step 3 Variables
    int numOfMatches = 0;
    string name;

    // Get Number of Customer Names that Start with Specific Letter
    for (unsigned long i = 0; i < numOfCustomers; i++) {
        name = names[i].substr(0, 1);//get first letter
        if (name.find(firstLetterOfCustomerName) != string::npos)
            numOfMatches++;
        //end if
    }//end for-loop

    // Output
    cout << "Customer names that start with \'" << firstLetterOfCustomerName << "\': " << numOfMatches << endl;
}//end printNumOfNamesWithLetter()

/* Step 4. */
// Print the Number of Customers with Debt Over the Debt Limit
void printNumWithPlusDebt(vector<double> &debt, int numOfCustomers, int debtLimit) {
    // Step 4 Variables
    int numWithDebt = 0;
    int numNoDebt = 0;
    double debtNum;

    // Get Number of Customers with Debt Over the Debt Limit
    for (unsigned long i = 0; i < numOfCustomers; i++) {
        debtNum = debt[i];
        if (debtNum > (double)debtLimit) {
            numWithDebt++;
        } else if (debtNum == 0) {
            numNoDebt++;
        }//end else-if
    }//end for-loop

    // Output
    cout << "Customers with debt over $" << (int)debtLimit << ": " << numWithDebt << endl;
    cout << "Customers debt free: " << numNoDebt << endl;
}//end printNumWithPlusDebt()

/* Step 5. */
// Repeat for Each Customer in Inputted State
void printDataForState(vector<string> &states, vector<string> &names, vector<double> &debt, char firstLetterOfCustomerName, int debtLimit, string stateAbbrev) {
    // Step 5 Variables
    int numOfCustomers = 0;
    string state;

    // Get Number of Customers in the Inputted State
    for (unsigned long i = 0; i < states.size(); i++) {
        state = states[i];
        if (state.compare(stateAbbrev) == 0)
            numOfCustomers++;
        //end if
    }//end for-loop

    // Output
    cout << "\n" << stateAbbrev << " Report" << endl;
    printNameWithMaxDebt(debt, names, numOfCustomers);
    printNumOfNamesWithLetter(names, numOfCustomers, firstLetterOfCustomerName);
    printNumWithPlusDebt(debt, numOfCustomers, debtLimit);
}//end printDataForState()

int main() {
    // Step 0 Variable
    int numOfCustomers = 0;
    // Step 1 Variables
    int debtLimit = 0;
    char firstLetterOfCustomerName;
    string stateAbbrev;

    // Input # of customers and create parallel vectors
    /* Type your code */
    // Get Requested Number of Customers
    cout << "How many customers are there? ";
    cin >> numOfCustomers;

    // Create Parallel Vectors
    vector<string> names(numOfCustomers);
    vector<double> debt(numOfCustomers);
    vector<string> states(numOfCustomers);

    // Fill vectors with data from another external file
    /* Type your code here */  
    // Read File Data into the Vectors
    ReadCustomerData(names, states, debt);

    /* Step 1. */
    // Input debt limit, search phrase, and state
    // Get the Debt Limit
    cout << "Enter the debt limit: ";
    cin >> debtLimit;
    // Get a Letter to Search with
    cout << "Enter a first initial to search with: ";
    cin.ignore();
    cin.get(firstLetterOfCustomerName);
    // Get a State Abbreviation
    cout << "Enter a State Abbreviation: ";
    cin.ignore();
    getline(cin, stateAbbrev);

    // Test Code to Check that Step 0 and Step 1 Works
    //printInputs(numOfCustomers, debtLimit, firstLetterOfCustomerName, stateAbbrev);

    
    // Output /* Step 5. */
    cout << "\nU.S. Report" << endl;// Report Header
    /* Step 2. */
    printNameWithMaxDebt(debt, names, numOfCustomers);
    /* Step 3. */
    printNumOfNamesWithLetter(names, numOfCustomers, firstLetterOfCustomerName);
    /* Step 4. */
    printNumWithPlusDebt(debt, numOfCustomers, debtLimit);
    /* Step 5. */
    printDataForState(states, names, debt, firstLetterOfCustomerName, debtLimit, stateAbbrev);

   return 0;
}//end main()
