//
//  PhysicianAssistant.hpp
//  MedRecords
//
//  Created by David Paul Silverstone on Sun, Oct 16th, 2016.
//
//

#ifndef PhysicianAssistant_hpp
#define PhysicianAssistant_hpp

#include "HealthCareProvider.hpp"
class Doctor;

class PhysicianAssistant : public HealthCareProvider {
private:
public:
    PhysicianAssistant(std::string Name, int ID, Institution* inst = 0, Doctor* dr = 0)
    : HealthCareProvider(Name, ID, inst)
    {
        supervisor = dr;
    };
    ~PhysicianAssistant() = default;
    bool hasAccessTo(Patient* pPatient) {
        // return true if they're currently there, for physicals
        if (!pPatient) return false;
        if (pPatient->whereAmIAt() != this->getInstitution()) return false;
        if (pPatient->isAuthorized(supervisor)) return true;
        return false;
    }
    bool canAccessTheseRecords(recordClass rc) {
        //using namespace recordClass;
        return (rc == recordClass::PHYSICAL || rc == recordClass::ALLERGY || rc == recordClass::SURGERY || rc == recordClass::PRESCRIPTION);
    }
    bool hasAccessTo(Patient* pPatient, recordClass rc) {
        return (hasAccessTo(pPatient) && canAccessTheseRecords(rc));
    }
    std::string typeOfProvider() const {
        return "Physician\'s Assistant";
    }

    bool addRecord(Patient* pPatient, recordClass rc, std::string string1 = "", date_type Dt = day_clock::local_day(), std::string string2 = "") final {
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

protected:
    Doctor* supervisor;
};


#endif /* PhysicianAssistant_hpp */
