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
    // virtual bool hasAccessTo(Patient* pPatient) = 0;
    // virtual bool canAccessTheseRecords(recordClass rc) = 0;
    // virtual bool hasAccessTo(Patient* pPatient, recordClass rc) = 0;
    virtual bool hasAccessTo(Patient* pPatient) {
        return false;
    }
    virtual bool canAccessTheseRecords(recordClass rc) {
        return false;
    }
    virtual bool hasAccessTo(Patient* pPatient, recordClass rc) {
        return false;
    }

    Institution* getInstitution() const {
        return whereTheyWork;
    }
    virtual std::string typeOfProvider() const {
        return "Health care provider";
    }
    virtual bool addRecord(Patient* pPatient, recordClass rc, std::string stuff = "", date_type Dt = day_clock::local_day()) {
        // do stuff if you can
        return false;
    }
    virtual void printInfo() const {
        std::cout << "Health care provider: " << mName << '\t' << "Institution: " << whereTheyWork->getName();
    }

protected:
    Institution* whereTheyWork;
    // Institution & whereTheyWork;
};


#endif /* HealthCareProvider_hpp */
