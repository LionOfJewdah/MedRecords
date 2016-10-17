#include "Patient.hpp"
#include "Record.hpp"

Patient::Patient(std::string name, int ID, sex gender, date_type dob = day_clock::local_day(), InsuranceProvider* dudeOverchargingYou = 0)
    : Person(name, ID), mGender(gender) {
        //mDate_of_birth = day_clock(local_day());
        mDate_of_birth = dob;
        location = nullptr;
        coverage = dudeOverchargingYou;
        whereMyRecordsAt = new RecordList(this);
};

Patient::~Patient(){
    if (whereMyRecordsAt) delete whereMyRecordsAt;
}

Patient::Patient(Patient&& other) : Person(other.mName, other.mID) { // my second move constructor
    mGender = other.mGender;
    mDate_of_birth = other.mDate_of_birth;
    location = other.location;
    other.location = 0;
    coverage = other.coverage;
    other.coverage = 0;
    whereMyRecordsAt = other.whereMyRecordsAt;
    other.whereMyRecordsAt = 0;
}
