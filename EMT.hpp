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
    std::string typeOfProvider() const {
        return "Emergency Room Doctor";
    }
protected:

};


#endif /* EMT_hpp */
