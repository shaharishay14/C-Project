#pragma once


enum PlaneType
{
	eRegular,
	eCargo,
	nofPlaneType
};

enum CrewType
{
	eHost,
	ePilot,
	nofCrewType
};
#define _CRT_SECURE_NO_WARNINGS
#include <string>
using namespace std;


const string PlaneType_TITLE[nofPlaneType] = {"Regular","Cargo"};
const string CrewType_TITLE[nofCrewType] = {"Host","Pilot"};


class CPlane;
class CCrewMember;
class CFlightCompany;
class CAddress;
class CFlight;
class CPlaneCrewFactory
{
public:

	static PlaneType GetPlaneType(const CPlane* pPlane);
	static CrewType GetCrewType(const CCrewMember *pCrew);

    // Get company data from user
	static void GetCompanyDataFromUser(CFlightCompany& comp);
	static CPlane* GetPlaneFromUser();
	static CCrewMember *GetCrewFromUser();
	static CFlight* GetFlightFromUser(CFlightCompany& company);

    // Get company data from file
	static CCrewMember* GetCrewMemberFromFile(ifstream& inFile);
	static CPlane* GetPlaneFromFile(ifstream& inFile);
	static CFlight *GetFlightFromFile(ifstream &inFile, CFlightCompany *company);

    // Save company data to file
    static void SaveCrewMemberToFile(ofstream& outFile, const CCrewMember* crew);
    static void SavePlaneToFile(ofstream& outFile, const CPlane* plane);
    static void SaveFlightToFile(ofstream& outFile, const CFlight* flight);

	


private:
	CPlaneCrewFactory(void) { ;}
};