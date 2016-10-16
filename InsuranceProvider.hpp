//
//  InsuranceProvider.hpp
//  MedRecords
//
//  Created by David Paul Silverstone on Sun, Oct 16th, 2016.
//
//

#ifndef InsuranceProvider_hpp
#define InsuranceProvider_hpp

#include "Institution.hpp"

class InsuranceProvider : public Institution {
private:
public:
    InsuranceProvider(std::string name, int ID) : Institution(name, ID) {};
    ~InsuranceProvider() = default;
    bool hasAccessTo(Patient* p) {
        if (!p) return false;
        if (p->whosCoveringMe() == this) return true;
        return false;
    }
protected:

};


#endif /* InsuranceProvider_hpp */
