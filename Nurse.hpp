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

class Nurse : public HealthCareProvider {
private:
public:
    Nurse(std::string Name, int ID, Institution* inst = 0)
    : HealthCareProvider(Name, ID, inst)
    {

    };
    ~Nurse();
    bool hasAccessTo(Patient* pPatient) {
        // a little more lenient on which patients nurses can see records of than Physician's Assistant
        return false;
    }
    bool canAccessTheseRecords(recordClass rc) {
        return (rc == PHYSICAL || rc == ALLERGY || rc == SURGERY || rc == PRESCRIPTION || rc == HOSPITALIZATION);
    }
    bool hasAccessTo(Patient* pPatient, recordClass rc) {
        return (hasAccessTo(pPatient) && canAccessTheseRecords(rc));
    }
    std::string typeOfProvider() const {
        return "Nurse";
    }
protected:

};


#endif /* Nurse_hpp */
