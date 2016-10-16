//
//  Surgeon.hpp
//  MedRecords
//
//  Created by David Paul Silverstone on Sun, Oct 16th, 2016.
//
//

#ifndef Surgeon_hpp
#define Surgeon_hpp

#include "Doctor.hpp"

class Surgeon : public Doctor {
private:
public:
    Surgeon();
    ~Surgeon();
    std::string typeOfProvider() const {
        return "Surgeon";
    }
protected:

};


#endif /* Surgeon_hpp */
