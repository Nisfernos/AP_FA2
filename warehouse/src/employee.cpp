#include "include/employee.hpp"

Employee::Employee(std::string name_, bool forkliftCertificate_) {
    /**
     * @brief 
     * @param 
     */
    this->name = name_;
    this->forkliftCertificate = forkliftCertificate_;
};
    
std::string Employee::getName() const {
    /**
     * @brief 
     * @param 
     */
    return this->name;
};

bool Employee::getBusy() const {
    /**
     * @brief 
     * @param 
     */
    return this->busy;
};

void Employee::setBusy(bool busy_) {
    /**
     * @brief 
     * @param 
     */
    this->busy = busy_;
};

bool Employee::getForkliftCertificate() const {
    /**
     * @brief 
     * @param 
     */
    return this->forkliftCertificate;
};

void Employee::setForkliftCertificate(bool forkliftCertificate_) {
    /**
     * @brief 
     * @param 
     */
    this->forkliftCertificate = forkliftCertificate_;
};
