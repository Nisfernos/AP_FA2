#pragma once
#include <string>

class Employee
{
private:
    std::string name;
    bool busy;
    bool forkliftCertificate;
    
public:
    Employee(std::string name_, bool forkliftCertificate_);
    
    std::string getName() const;
    bool getBusy() const;
    void setBusy(bool busy_);
    bool getForkliftCertificate() const;
    void setForkliftCertificate(bool forkliftCertificate_);
};