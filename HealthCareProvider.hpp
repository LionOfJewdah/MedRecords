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

enum class recordClass : int { BIRTH = 0, PHYSICAL = 1, ALLERGY, HOSPITALIZATION, PRESCRIPTION, SURGERY, DISEASE };

class Patient; // forward declaration

class HealthCareProvider : public Person {
private:
public:
    HealthCareProvider(std::string Name, int ID, Institution* inst = 0) : Person(Name, ID)
    {
        whereTheyWork = inst;
    };
    virtual ~HealthCareProvider() {};
    virtual bool hasAccessTo(Patient* pPatient) = 0;
    virtual bool canAccessTheseRecords(recordClass rc) = 0;
    virtual bool hasAccessTo(Patient* pPatient, recordClass rc) = 0;
    Institution* getInstitution() const {
        return whereTheyWork;
    }
    virtual std::string typeOfProvider() const {
        return "Health care provider";
    }
    virtual void addRecord(Patient* pPatient, Record /*&& const */ rcd) = 0;
protected:
    Institution* whereTheyWork;
    // Institution & whereTheyWork;
};


#endif /* HealthCareProvider_hpp */
