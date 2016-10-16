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
#include "boost/date_time/gregorian/gregorian.hpp"
using boost::gregorian::day_clock;
typedef boost::gregorian::date date_type;
using boost::gregorian::from_undelimited_string;

enum class recordClass : int { BIRTH = 0, PHYSICAL = 1, ALLERGY, HOSPITALIZATION, PRESCRIPTION, SURGERY, DISEASE };
//enum class healthCareProviderModel : int { HCP = 0, NURSE = 1, PA = 2, DOCTOR = 3, SURGEON = 4, ONCOLOGIST = 5, EMT = 6};

class Patient; // forward declaration

class HealthCareProvider : public Person {
private:
public:
    HealthCareProvider(std::string Name, int ID, Institution* inst = 0) : Person(Name, ID)
    {
        whereTheyWork = inst;
    };
    virtual ~HealthCareProvider() = default;
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
    virtual bool addRecord(Patient* pPatient, recordClass rc, std::string string1, date_type Dt, std::string string2) {
        return false;
    }
    /*
    virtual bool addRecord(Patient* pPatient, recordClass rc, std::string string1 = "", date_type Dt = day_clock::local_day(), std::string string2 = "") { //const {
        if (!pPatient) return false;
        if (!hasAccessTo(pPatient, rc)) return false;
        switch (rc) {
            case recordClass::BIRTH :
                (pPatient->pointToRecords())->addRecord(new birthRecord(pPatient,this));
                break;
            case recordClass::HOSPITALIZATION :
                (pPatient->pointToRecords())->addRecord(new hospitalizationRecord(pPatient,this, Dt));
                break;
            case recordClass::PRESCRIPTION :
                (pPatient->pointToRecords())->addRecord(new prescriptionRecord(pPatient,this, string1));
                break;
            case recordClass::SURGERY :
                (pPatient->pointToRecords())->addRecord(new surgeryRecord(pPatient,this,Dt,string1, string2));
                break;
            case recordClass::DISEASE :
                (pPatient->pointToRecords())->addRecord(new diseaseRecord(pPatient,this, Dt, string1, string2));
                break;
            case recordClass::ALLERGY :
                (pPatient->pointToRecords())->addRecord(new allergyRecord(pPatient,this, Dt, string1));
                break;
            default:
                return false;
        }
        return true;
    }
    */

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
    // virtual void printInfo() const {
    //     std::cout << "Health care provider: " << mName << '\t' << "Institution: " << whereTheyWork->getName();
    // }

protected:
    Institution* whereTheyWork;
    // Institution & whereTheyWork;
};


#endif /* HealthCareProvider_hpp */
