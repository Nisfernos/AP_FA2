#pragma once
#include <string>

class Employee {
    /**
     * @brief This class represents an employee in warehouse.
     * @param name The name of the employee.
     * @param busy If the employee is currently busy.
     * @param forkliftCertificate Whether the employee has a forkliftCertificate.
     * You can get the busy status, whether the employee has a forkliftcertificate and the name of the employee.
     * You can alter the busy boolean, and alter if the employee owns a forkliftcertificate.
     */
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