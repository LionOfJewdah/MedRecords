//
//  Doctor.hpp
//  MedRecords
//
//  Created by David Paul Silverstone on Sat, Oct 15th, 2016.
//
//

#ifndef Doctor_hpp
#define Doctor_hpp

#include "HealthCareProvider.hpp"

// has long-term access to a patient's medical records while authorized
class Doctor : public HealthCareProvider {
private:
public:
    Doctor(std::string Name, int ID, Institution* inst = 0)
    : HealthCareProvider (Name, ID, inst)
    {

    }
    virtual ~Doctor() = default;
    virtual std::string typeOfProvider() const {
        return "Doctor";
    }
    virtual bool hasAccessTo(Patient* pPatient) {
        return (pPatient->isAuthorized(this));
    } // overloaded in Surgeon, but not in Oncologist
    virtual bool canAccessTheseRecords(recordClass rc) {
        // Doctor can access: birthRecord,
        return true;
    }
    virtual bool hasAccessTo(Patient* pPatient, recordClass rc)  {
        return (hasAccessTo(pPatient) && canAccessTheseRecords(rc));
    }
    virtual bool addRecord(Patient* pPatient, recordClass rc, std::string string1 = "", date_type Dt = day_clock::local_day(), std::string string2 = "") {
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
    virtual void printInfo() const {
        std::cout << "Doctor: " << mName << '\t' << "Institution: " << whereTheyWork->getName();
    }
    //from HealthCareProvider.hpp: `enum class recordClass : int { BIRTH = 0, PHYSICAL = 1, ALLERGY, HOSPITALIZATION, PRESCRIPTION, SURGERY, DISEASE };`
protected:

};


#endif /* Doctor_hpp */
