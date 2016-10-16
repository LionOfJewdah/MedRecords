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
protected:
    Doctor* supervisor;
};


#endif /* PhysicianAssistant_hpp */
