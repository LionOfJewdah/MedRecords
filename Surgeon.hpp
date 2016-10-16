//
//  Surgeon.hpp
//  MedRecords
//
//  Created by David Paul Silverstone on Sun, Oct 16th, 2016.
//
//

#ifndef Surgeon_hpp
#define Surgeon_hpp

#include "Doctor.hpp"

class Surgeon : public Doctor {
private:
    //Division* division;
    Institution* division;
public:
    Surgeon(std::string Name, int ID, Institution* inst = 0)
    : Doctor (Name, ID, inst)
    {
        division = inst; // one day, will be a division of inst
    }
    ~Surgeon();
    // Division * getDivision() const { return division; }
    Institution* getDivision() const { return division; }
    std::string typeOfProvider() const final {
        return "Surgeon";
    }
    bool hasAccessTo(Patient* pPatient) final;
    // {
    //     if (!pPatient) return false;
    //     if (pPatient->whereAmIAt() == this->getDivision()) return true;
    //     // given more time we could make it so the cardiologist could only access patients in the cardio division of their hospital, etc.
    //     return false;
    // }
    bool canAccessTheseRecords(recordClass rc) final {
        return true;
    }
    bool hasAccessTo(Patient* pPatient, recordClass rc) final {
        return hasAccessTo(pPatient); // because can access any type of record while they're undergoing surgery
    }
    bool addRecord(Patient*, recordClass, std::string, date_type, std::string) final;
    // see implementation
protected:

};


#endif /* Surgeon_hpp */
