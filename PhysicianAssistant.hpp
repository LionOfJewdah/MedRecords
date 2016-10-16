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

class PhysicianAssistant : public HealthCareProvider {
private:
public:
    PhysicianAssistant();
    ~PhysicianAssistant();
    bool hasAccessTo(Patient* pPatient) {
        // return true if they're currently there, for physicals
        return false;
    }
    bool canAccessTheseRecords(recordClass rc) = 0;
    bool hasAccessTo(Patient* pPatient, recordClass rc) = 0;
protected:

};


#endif /* PhysicianAssistant_hpp */
