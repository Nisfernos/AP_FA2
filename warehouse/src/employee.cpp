#include "include/employee.hpp"

Employee::Employee(std::string name_, bool forkliftCertificate_) {
    this->name = name_;
    this->forkliftCertificate = forkliftCertificate_;
};
    
std::string Employee::getName() const {
    return this->name;
};

bool Employee::getBusy() const {
    return this->busy;
};

void Employee::setBusy(bool busy_) {
    this->busy = busy_;
};

bool Employee::getForkliftCertificate() const {
    return this->forkliftCertificate;
};

void Employee::setForkliftCertificate(bool forkliftCertificate_) {
    this->forkliftCertificate = forkliftCertificate_;
};
