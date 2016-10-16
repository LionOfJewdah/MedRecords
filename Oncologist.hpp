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
class Oncologist final : public Doctor {
private:
public:
    Oncologist(std::string Name, int ID, Institution* inst = 0)
    : Doctor (Name, ID, inst)
    {

    }
    ~Oncologist();
    std::string typeOfProvider() const final {
        return "Oncologist";
    }
    //bool hasAccessTo(Patient* pPatient) not overloaded from doctor
    bool canAccessTheseRecords(recordClass rc) final {
        return true;
    }
    bool hasAccessTo(Patient* pPatient, recordClass rc) final {
        return Doctor::hasAccessTo(pPatient); // because can access any type of record
    }
protected:

};


#endif /* Oncologist_hpp */
