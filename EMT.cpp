#include "EMT.hpp"
#include "TypesOfRecord.hpp"
#include "Patient.hpp"

bool EMT::hasAccessTo(Patient* pPatient) {
    if (!pPatient) return false;
    if (pPatient->whereAmIAt() == this->getInstitution())
        return true; // EMT has access if and only if the patient is at that hospital/provider institution at that time
    return false; //
}

bool EMT::addRecord(Patient* pPatient, recordClass rc, std::string string1 = "", date_type Dt = day_clock::local_day(), std::string string2 = "") /*const*/ {
      if (!pPatient) return false;
      if (!hasAccessTo(pPatient, rc)) return false;
      switch (rc) {
          case recordClass::BIRTH :
              //(pPatient->pointToRecords())->addRecord(new birthRecord(pPatient,this));
              return false;
              break;
          case recordClass::HOSPITALIZATION :
              (pPatient->pointToRecords())->addRecord(new hospitalizationRecord(pPatient,this, Dt));
              break;
          case recordClass::PRESCRIPTION :
              return false; // EMT's cant prescribe you stuff
              break;
          case recordClass::SURGERY :
              //(pPatient->pointToRecords())->addRecord(new surgeryRecord(pPatient,this,Dt,string1, string2));
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
