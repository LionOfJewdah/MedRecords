//
//  HealthCareProvider.hpp
//  MedRecords
//
//  Created by David Paul Silverstone on Sat, Oct 15th, 2016.
//
//

#ifndef HealthCareProvider_hpp
#define HealthCareProvider_hpp

#include "Institution.hpp"
#include "Person.hpp"

class Patient; // forward declaration

class HealthCareProvider : public Person {
private:
public:
    HealthCareProvider();
    virtual ~HealthCareProvider();
    virtual bool hasAccessTo(Patient* pPatient) = 0;
    virtual bool hasAccessTo(Patient* pPatient) = 0;
protected:
    Institution* whereTheyWork;
    // Institution & whereTheyWork;
};


#endif /* HealthCareProvider_hpp */
