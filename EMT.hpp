//
//  EMT.hpp
//  MedRecords
//
//  Created by David Paul Silverstone on Sun, Oct 16th, 2016.
//
//

#ifndef EMT_hpp
#define EMT_hpp

#include "HealthCareProvider.hpp"

// has temporary access to ALL medical records of a patient, while in the ER ward ONLY
class EMT : public HealthCareProvider {
private:
public:
    EMT();
    ~EMT();
    bool hasAccessTo(Patient* pPatient) {
        if (!pPatient) return false;
        if (pPatient->whereAmIAt() == this->getInstitution())
            return true; // EMT has access if and only if the patient is at that hospital/provider institution at that time
        return false; //
    }
    bool canAccessTheseRecords(recordClass rc) { return true; }
    bool hasAccessTo(Patient* pPatient, recordClass rc) {
        return hasAccessTo(pPatient);
    }
    std::string typeOfProvider() const {
        return "Emergency Room Doctor";
    }
    bool addRecord(Patient* pPatient, recordClass rc, std::string string1 = "", date_type Dt = day_clock::local_day(), std::string string2 = "") /*const*/ final {
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
                (pPatient->pointToRecords())->addRecord(new surgeryRecord(pPatient,this,Dt,string1, string2));
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
protected:

};


#endif /* EMT_hpp */
