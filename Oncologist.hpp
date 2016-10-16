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
    bool addRecord(Patient*, recordClass, std::string, date_type, std::string) final;
    // bool addRecord(Patient* pPatient, recordClass rc, std::string string1 = "", date_type Dt = day_clock::local_day(), std::string string2 = "") final {
    //     if (!pPatient) return false;
    //     if (!hasAccessTo(pPatient, rc)) return false;
    //     switch (rc) {
    //         case recordClass::BIRTH :
    //             (pPatient->pointToRecords())->addRecord(new birthRecord(pPatient,this));
    //             break;
    //         case recordClass::HOSPITALIZATION :
    //             (pPatient->pointToRecords())->addRecord(new hospitalizationRecord(pPatient,this, Dt));
    //             break;
    //         case recordClass::PRESCRIPTION :
    //             (pPatient->pointToRecords())->addRecord(new prescriptionRecord(pPatient,this, string1));
    //             break;
    //         case recordClass::SURGERY :
    //             return false;
    //             break;
    //         case recordClass::DISEASE :
    //             (pPatient->pointToRecords())->addRecord(new diseaseRecord(pPatient,this, Dt, string1, string2));
    //             break;
    //         case recordClass::ALLERGY :
    //             (pPatient->pointToRecords())->addRecord(new allergyRecord(pPatient,this, Dt, string1));
    //             break;
    //         default:
    //             return false;
    //     }
    //     return true;
    // }
protected:

};


#endif /* Oncologist_hpp */
