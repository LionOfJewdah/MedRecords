#include "PhysicianAssistant.hpp"
#include "TypesOfRecord.hpp"
#include "Patient.hpp"

bool PhysicianAssistant::hasAccessTo(Patient* pPatient) {
    if (!pPatient) return false;
    if (!supervisor) return false;
    if (pPatient->whereAmIAt() != this->getInstitution()) return false;
    if (pPatient->isAuthorized(supervisor)) return true;
    return false;
}

bool PhysicianAssistant::addRecord(Patient* pPatient, recordClass rc, std::string string1 = "", date_type Dt = day_clock::local_day(), std::string string2 = "")
{
    if (!pPatient) return false;
    if (!hasAccessTo(pPatient, rc)) return false;
    switch (rc) {
        case recordClass::BIRTH :
            return false;
            break;
        case recordClass::HOSPITALIZATION :
            (pPatient->pointToRecords())->addRecord(new hospitalizationRecord(pPatient,this, Dt));
            break;
        case recordClass::PRESCRIPTION :
            (pPatient->pointToRecords())->addRecord(new prescriptionRecord(pPatient,this, string1));
            break;
        case recordClass::SURGERY :
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
