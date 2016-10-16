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
    virtual bool hasAccessTo(Patient* pPatient); // overloaded in Surgeon, but not in Oncologist
    // {
    //     return (pPatient->isAuthorized(this));
    // } // overloaded in Surgeon, but not in Oncologist
    virtual bool canAccessTheseRecords(recordClass rc) {
        // Doctor can access: birthRecord,
        return true;
    }
    virtual bool hasAccessTo(Patient* pPatient, recordClass rc)  {
        return (hasAccessTo(pPatient) && canAccessTheseRecords(rc));
    }
    virtual bool addRecord(Patient* pPatient, recordClass rc, std::string string1, date_type Dt, std::string string2); // see implementation file
    // virtual void printInfo() const {
    //     std::cout << "Doctor: " << mName << '\t' << "Institution: " << whereTheyWork->getName();
    // }
    //from HealthCareProvider.hpp: `enum class recordClass : int { BIRTH = 0, PHYSICAL = 1, ALLERGY, HOSPITALIZATION, PRESCRIPTION, SURGERY, DISEASE };`
protected:

};


#endif /* Doctor_hpp */
