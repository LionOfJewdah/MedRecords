//
//  Oncologist.hpp
//  MedRecords
//
//  Created by David Paul Silverstone on Sun, Oct 16th, 2016.
//
//

#ifndef Oncologist_hpp
#define Oncologist_hpp

#include "Doctor.hpp"

// has long-term access to all of a patient's medical records while treating that patient
class Oncologist : public Doctor {
private:
public:
    Oncologist();
    ~Oncologist();
    std::string typeOfProvider() const {
        return "Oncologist";
    }
    //bool hasAccessTo(Patient* pPatient) not overloaded from doctor
    bool canAccessTheseRecords(recordClass rc) {
        return true;
    }
    bool hasAccessTo(Patient* pPatient, recordClass rc) {
        return hasAccessTo(pPatient); // because can access any type of record
    }
protected:

};


#endif /* Oncologist_hpp */
