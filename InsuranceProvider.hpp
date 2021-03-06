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

class Patient; // forward declaration

class InsuranceProvider : public Institution {
private:
public:
    InsuranceProvider(std::string name, int ID) : Institution(name, ID) {};
    ~InsuranceProvider() = default;
    bool hasAccessTo(Patient* p) const;
protected:

};

#endif /* InsuranceProvider_hpp */
