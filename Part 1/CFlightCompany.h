#pragma once
#include <string>

class CFlightCompany 
{
private:
    std::string name;

    void ValidateData() const;

public:
    CFlightCompany() = delete; 
    CFlightCompany(const std::string& name);

    CFlightCompany(const CFlightCompany& other);
    ~CFlightCompany();

    std::string GetName() const;
	void SetName(const std::string& newName);

    void Print() const;
};
