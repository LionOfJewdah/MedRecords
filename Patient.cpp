#include "Patient.hpp"
#include "Record.hpp"

Patient::Patient(std::string name, int ID, sex gender, date_type dob = day_clock::local_day(), InsuranceProvider* dudeOverchargingYou = 0)
    : Person(name, ID), mGender(gender) {
        //mDate_of_birth = day_clock(local_day());
        mDate_of_birth = dob;
        location = nullptr;
        coverage = dudeOverchargingYou;
        whereMyRecordsAt->setOwner(this);
};

Patient::~Patient(){
   delete whereMyRecordsAt;
}
