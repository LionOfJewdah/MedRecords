#include "Doctor.hpp"
#include "TypesOfRecord.hpp"
#include "Patient.hpp"

bool Doctor::hasAccessTo(Patient* pPatient) {
    return (pPatient->isAuthorized(this));
} 

bool Doctor::addRecord(Patient* pPatient, recordClass rc, std::string string1 = "", date_type Dt = day_clock::local_day(), std::string string2 = "") {
    if (!pPatient) return false;
    if (!hasAccessTo(pPatient, rc)) return false;
    switch (rc) {
        case recordClass::BIRTH :
            (pPatient->pointToRecords())->addRecord(new birthRecord(pPatient,this));
            break;
        case recordClass::HOSPITALIZATION :
            (pPatient->pointToRecords())->addRecord(new hospitalizationRecord(pPatient,this, Dt));
            break;
        case recordClass::PRESCRIPTION :
            (pPatient->pointToRecords())->addRecord(new prescriptionRecord(pPatient,this, string1));
            break;
        case recordClass::SURGERY :
            // (pPatient->pointToRecords())->addRecord(new surgeryRecord(pPatient,this,Dt,string1, string2));
            return false;
            break;
        case recordClass::DISEASE :
            (pPatient->pointToRecords())->addRecord(new diseaseRecord(pPatient,this, Dt, string1, string2));
            break;
        case recordClass::ALLERGY :
            (pPatient->pointToRecords())->addRecord(new allergyRecord(pPatient,this, Dt, string1));
            break;
        default:
            return false;
    }
    return true;
}
