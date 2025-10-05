#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <fstream>
using namespace std;

#include "CFlightCompany.h"
#include "CFlightCompException.h"
#include "CPlaneCrewFactory.h"

//const int CM_COUNT = 5;
//const int PLANE_COUNT = 4;
//const int FLIGHT_COUNT = 4;

int main()
{

  	CFlightCompany *pDelta = nullptr;

  	// Check if file is empty first
    ifstream checkFile("Delta.txt");
    bool isEmpty = false;
    
    if (checkFile.is_open()) {
        checkFile.seekg(0, ios::end);
        if (checkFile.tellg() == 0) {
            isEmpty = true;
            cout << "=== File is empty, will get user input ===" << endl;
        }
        checkFile.close();
    } else {
        isEmpty = true;
        cout << "=== File doesn't exist, will get user input ===" << endl;
    }
    
    if (isEmpty) {
        // File is empty - get user input
        cout << "=== Creating new flight company from user input ===" << endl;
        pDelta = new CFlightCompany("Delta");
        
        // Get data from user
        CPlaneCrewFactory::GetCompanyDataFromUser(*pDelta);
        
        cout << "\n=== New flight company created with user data: ===" << endl;
        pDelta->Print(cout);
    }
    else {
        // File is not empty - try to load it
        try {
            cout << "=== Attempting to load flight company from file ===" << endl;
            ifstream inFile("Delta.txt");
            pDelta = new CFlightCompany(inFile);
            inFile.close();
            cout << "=== Successfully loaded flight company from file! ===" << endl;
            pDelta->Print(cout);
        }
        catch (const CFlightCompException& e) {
            cout << "=== Failed to load from file: ";
            e.Show();
            cout << "\n=== Creating new flight company from user input instead ===" << endl;
            
            // If loading failed, create new company and get user input
            pDelta = new CFlightCompany("Delta");
            CPlaneCrewFactory::GetCompanyDataFromUser(*pDelta);
            
            cout << "\n=== New flight company created with user data: ===" << endl;
            pDelta->Print(cout);
        }
    }

    cout << "=== Would you like to add data to the flight company? (y/n) ==="
         << endl;
    char choice;
    cin >> choice;
    if (choice == 'y') {
        CPlaneCrewFactory::GetCompanyDataFromUser(*pDelta);
        cout << "\n=== Data added to the flight company: ===" << endl;
        pDelta->Print(cout);
    }
    else {
        cout << "=== No data added to the flight company. ===" << endl;
    }

    
     // Save the flight company regardless of how data was received
    try {
        cout << "\n=== Saving flight company data to file ===" << endl;
        pDelta->SaveToFile("Delta.txt");
        cout << "=== Data successfully saved to Delta.txt! ===" << endl;
    }
    catch (const CFlightCompException& e) {
        cout << "=== Error saving data: ";
        e.Show();
    }
    
    // Clean up
    cout << "\n=== Cleaning up ===" << endl;
    delete pDelta;
    pDelta = nullptr;
    
    cout << "=== Flight company deleted. Program completed successfully! ===" << endl;
    
    system("pause");
    return 0;
}