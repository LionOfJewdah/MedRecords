//
//  Nurse.hpp
//  MedRecords
//
//  Created by David Paul Silverstone on Sun, Oct 16th, 2016.
//
//

#ifndef Nurse_hpp
#define Nurse_hpp

#include "HealthCareProvider.hpp"

class Doctor; // forward declaration

class Nurse : public HealthCareProvider {
private:
public:
    Nurse(std::string Name, int ID, Institution* inst = 0, Doctor* dr = 0)
    : HealthCareProvider(Name, ID, inst)
    {
        //supervisor = dr;
    };
    ~Nurse();
    bool hasAccessTo(Patient*) final;
    // bool hasAccessTo(Patient* pPatient) final {
    //     // a little more lenient on which patients nurses can see records of than Physician's Assistant
    //     // nurse can access records of patients at their division or
    //     if (!pPatient) return false;
    //     if (pPatient->whereAmIAt() == this->whereTheyWork) return true;
    //     return false;
    // }
    bool canAccessTheseRecords(recordClass rc) final {
        return (rc == recordClass::PHYSICAL || rc == recordClass::ALLERGY || rc == recordClass::SURGERY || rc == recordClass::PRESCRIPTION || rc == recordClass::HOSPITALIZATION);
    }
    bool hasAccessTo(Patient* pPatient, recordClass rc) final {
        return (hasAccessTo(pPatient) && canAccessTheseRecords(rc));
    }
    std::string typeOfProvider() const final {
        return "Nurse";
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
    //             (pPatient->pointToRecords())->addRecord(new surgeryRecord(pPatient,this,Dt,string1, string2));
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
    // Doctor* supervisor;
};


#endif /* Nurse_hpp */
