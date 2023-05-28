#include "include/employee.hpp"


Employee::Employee(std::string name_, bool forkliftCertificate_) {
    /**
     * @brief Constructor of the employee class
     * @param name_ The name of the employee
     * @param forkliftCertificate_ The employee owns a forkliftcertificate
     */
    this->name = name_;
    this->forkliftCertificate = forkliftCertificate_;
    this->busy = false;
};
    
std::string Employee::getName() const {
    /**
     * @brief Returns the name of the employee.
     */
    return this->name;
};

bool Employee::getBusy() const {
    /**
     * @brief Returns whether the employee is busy.
     */
    return this->busy;
};

void Employee::setBusy(bool busy_) {
    /** 
     * @brief Alter the busy status of an employee
     * @param busy_ Boolean for if the employee is busy
     */
    this->busy = busy_;
};

bool Employee::getForkliftCertificate() const {
    /**
     * @brief Returns whether the employee owns a forkliftcertificate.
     */
    return this->forkliftCertificate;
};

void Employee::setForkliftCertificate(bool forkliftCertificate_) {
    /**
     * @brief Alters whether the employee owns a forkliftcertificate.
     * @param forkliftCertificate_ Boolean for if the employee owns forkliftcertificate.
     */
    this->forkliftCertificate = forkliftCertificate_;
};
