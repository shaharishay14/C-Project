#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
using namespace std;

#include "CPlane.h"
#include "CFlightInfo.h"
#include "CCrewMember.h"
#include "CFlight.h"
#include "CFlightCompany.h"
#include "CAddress.h"
#include "CPilot.h"
#include "CCargo.h"
#include "CHost.h"
#include "CFlightCompException.h"
#include "PlaneCrewFactory.h"

//const int CM_COUNT = 5;
//const int PLANE_COUNT = 4;
//const int FLIGHT_COUNT = 4;

void main()
{

	CFlightCompany* pDelta=NULL;
	try
	{

		pDelta = new CFlightCompany("Delta.txt",0);
		cout << "This was in file " << endl;
		pDelta->Print(cout);

	} catch (const CFlightCompException& e){
		e.Show();
		pDelta = new CFlightCompany("Delta");
	}

	//Checking some of the exception put try and catch for each section	
	
	// Test 1: CPlane constructor with negative seat count
	try {
		cout << "\n=== Testing CPlane constructor with negative seat count ===" << endl;
		CPlane p1(-34,"AirBus");
	} catch (const CFlightCompException& e) {
		cout << "Caught exception: ";
		e.Show();
	}
	
	// Test 2: CCargo constructor with negative maxKg
	try {
		cout << "\n=== Testing CCargo constructor with negative maxKg ===" << endl;
		CCargo c1(45,"Jumbo",-560,200);
	} catch (const CFlightCompException& e) {
		cout << "Caught exception: ";
		e.Show();
	}
	
	// Test 3: CCargo constructor with negative maxVolume
	try {
		cout << "\n=== Testing CCargo constructor with negative maxVolume ===" << endl;
		CCargo c2(45,"Jumbo",560,-200);
	} catch (const CFlightCompException& e) {
		cout << "Caught exception: ";
		e.Show();
	}
	
	// Test 4: CFlightInfo constructor with negative flight number
	try {
		cout << "\n=== Testing CFlightInfo constructor with negative flight number ===" << endl;
		CFlightInfo f1("London",-23,120,5000);
	} catch (const CFlightCompException& e) {
		cout << "Caught exception: ";
		e.Show();
	}
	
	// Test 5: CFlightInfo constructor with too long destination
	try {
		cout << "\n=== Testing CFlightInfo constructor with too long destination ===" << endl;
		CFlightInfo f2("LondonVeryLong",23,120,5000);
	} catch (const CFlightCompException& e) {
		cout << "Caught exception: ";
		e.Show();
	}
	
	// Test 6: CFlightInfo constructor with negative duration
	try {
		cout << "\n=== Testing CFlightInfo constructor with negative duration ===" << endl;
		CFlightInfo f3("London",23,-120,5000);
	} catch (const CFlightCompException& e) {
		cout << "Caught exception: ";
		e.Show();
	}
	
	// Test 7: CFlightInfo constructor with negative distance
	try {
		cout << "\n=== Testing CFlightInfo constructor with negative distance ===" << endl;
		CFlightInfo f4("London",23,120,-5000);
	} catch (const CFlightCompException& e) {
		cout << "Caught exception: ";
		e.Show();
	}
	
	// Test 8: Array access with invalid index
	try {
		cout << "\n=== Testing GetCrewMember with invalid index ===" << endl;
		CCrewMember* pC1 = pDelta->GetCrewMember(-1);
	} catch (const CFlightCompException& e) {
		cout << "Caught exception: ";
		e.Show();
	}
	
	// Test 9: Air crew handling with negative delta minutes
	try {
		cout << "\n=== Testing air crew handling with negative delta minutes ===" << endl;
		CCrewMember* pC2 = pDelta->GetCrewMember(0);
		(*pC2) +=-4;
	} catch (const CFlightCompException& e) {
		cout << "Caught exception: ";
		e.Show();
	}
	
	// Test 10: Array access operator with invalid index
	try {
		cout << "\n=== Testing [] operator with invalid index ===" << endl;
		CPlane p0 = (*pDelta)[9];
	} catch (const CFlightCompException& e) {
		cout << "Caught exception: ";
		e.Show();
	}



	//call a static function that get plane or customer from user.
	
	CPlaneCrewFactory::GetCompanyDataFromUser(*pDelta);

	// Test 11: Normal operations (should work)
	try {
		cout << "\n=== Testing normal operations ===" << endl;
		CFlightInfo Info("Paris",343,320,5000);
		CFlight flight1(Info, &(*pDelta)[0]);
		pDelta->AddFlight(flight1);

		CFlight* pF = pDelta->GetFlightByNum(343);
		CCrewMember* pCmTemp;
		if ( pF != NULL) {
			cout << "flight 343 was found " << endl;
			for (int i = 0; i < pDelta->GetCrewCount(); i++){
				pCmTemp = pDelta->GetCrewMember(i);
				*pF + pCmTemp;
			}
		}
	} catch (const CFlightCompException& e) {
		cout << "Caught exception: ";
		e.Show();
	}

	
	try
	{

		pDelta->SaveToFile("Delta.txt");

	} catch (const CFlightCompException& e){
		e.Show();
	}

	// Save data before exiting
	try {
		cout << "\n=== Saving company data to file ===" << endl;
		pDelta->SaveToFile("Delta.txt");
		cout << "Data saved successfully!" << endl;
	} catch (const CFlightCompException& e) {
		cout << "Error saving data: ";
		e.Show();
	}

	delete pDelta;





	cout << "\n=== Exception Testing Complete ===" << endl;
	cout << "All exception handling scenarios have been tested!" << endl;

	system("pause");
}