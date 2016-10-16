//
//  Oncologist.hpp
//  MedRecords
//
//  Created by David Paul Silverstone on Sun, Oct 16th, 2016.
//
//

#ifndef Oncologist_hpp
#define Oncologist_hpp

#include "Doctor.hpp"

// has long-term access to all of a patient's medical records
class Oncologist : public Doctor {
private:
public:
    Oncologist();
    ~Oncologist();
    std::string typeOfProvider() const {
        return "Oncologist";
    }
protected:

};


#endif /* Oncologist_hpp */
