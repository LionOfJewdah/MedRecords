//
//  Nurse.hpp
//  MedRecords
//
//  Created by David Paul Silverstone on Sun, Oct 16th, 2016.
//
//

#ifndef Nurse_hpp
#define Nurse_hpp

#include "HealthCareProvider"

class Doctor; // forward declaration

class Nurse : public HealthCareProvider {
private:
public:
    Nurse(std::string Name, int ID, Institution* inst = 0, Doctor* dr = 0)
    : HealthCareProvider(Name, ID, inst)
    {
        supervisor = dr;
    };
    ~Nurse();
    bool hasAccessTo(Patient* pPatient) {
        // a little more lenient on which patients nurses can see records of than Physician's Assistant
        // nurse can access records of patients at their division or
        return false;
    }
    bool canAccessTheseRecords(recordClass rc) {
        return (rc == recordClass::PHYSICAL || rc == recordClass::ALLERGY || rc == recordClass::SURGERY || rc == recordClass::PRESCRIPTION || rc == recordClass::HOSPITALIZATION);
    }
    bool hasAccessTo(Patient* pPatient, recordClass rc) {
        return (hasAccessTo(pPatient) && canAccessTheseRecords(rc));
    }
    std::string typeOfProvider() const {
        return "Nurse";
    }
protected:
    Doctor* supervisor;
};


#endif /* Nurse_hpp */
