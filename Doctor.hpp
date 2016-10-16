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
    Doctor();
    virtual ~Doctor();
    virtual std::string typeOfProvider() const {
        return "Doctor";
    }
protected:

};


#endif /* Doctor_hpp */
