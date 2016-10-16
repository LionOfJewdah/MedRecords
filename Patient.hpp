//
//  Patient.hpp
//  MedRecords
//
//  Created by David Paul Silverstone on Sat, Oct 15th, 2016.
//
//

#ifndef Patient_hpp
#define Patient_hpp

enum class sex : bool { MALE = false, FEMALE = true };

#include "boost/date_time/gregorian/gregorian.hpp"
using boost::gregorian::day_clock;
typedef boost::gregorian::date date_type;
using boost::gregorian::from_undelimited_string;
#include "Person.hpp"
#include "HealthCareProvider.hpp"
//#include "InsuranceProvider.hpp"
// #include <vector>
#include <set>
//#include <ctime> // time.h
//typedef struct tm date_type;

class RecordList; // forward declaration
class InsuranceProvider;

class Patient final : public Person {
private:
    date_type mDate_of_birth;
    sex mGender;
    // std::vector<Person*> mNextOfKin;
    // HealthCareProvider* primaryCarePhysician;
    std::set<HealthCareProvider*> authorizedDoctors;
    RecordList* whereMyRecordsAt; // fuck no use a map or vector or smthg smh
    InsuranceProvider* coverage; // NULL if they have no insurance
    Institution* location; // NULL if not in a hospital or clinic, else points to the thing
    typedef std::set<HealthCareProvider*>::iterator guysWhoCanTreatMe;

public:
    Patient(std::string name, int ID, sex gender, date_type dob = day_clock::local_day(), InsuranceProvider* dudeOverchargingYou = 0)
        : Person(name, ID), mGender(gender) {
            //mDate_of_birth = day_clock(local_day());
            mDate_of_birth = dob;
            location = nullptr;
            coverage = dudeOverchargingYou;
    };
    /*
    Patient(std::string name, int ID, sex gender, date_type dob)
        : Person(name, ID), mDate_of_birth(dob), mGender(gender) {
            location = nullptr;
            coverage = nullptr;
    };
    Patient(std::string name, int ID, sex gender, date_type dob, InsuranceProvider* dudeOverchargingYou)
        : Person(name, ID), mDate_of_birth(dob), mGender(gender) {
            location = nullptr;
            coverage = dudeOverchargingYou;
    };
    */
    ~Patient() {
        //delete whereMyRecordsAt;
    }

    sex getSex() const { return mGender; }

    bool isAuthorized (HealthCareProvider* pDude) const {
        guysWhoCanTreatMe goIteratorGo = authorizedDoctors.find(pDude);
        return (goIteratorGo != authorizedDoctors.end());
    } // true if found, else false

    bool authorize (HealthCareProvider* pDude) {
        std::pair<guysWhoCanTreatMe, bool> thing = authorizedDoctors.insert(pDude);
        return thing.second;
    } // false if pDude was already authorized, true if newly authorized

    bool deauthorize (HealthCareProvider* pDude) {
        int wereTheGuyThere = authorizedDoctors.erase(pDude);
        return ((bool) wereTheGuyThere);
    } // true if was removed, false if wasn't found

    InsuranceProvider* whosCoveringMe() const {
        return coverage;
    }

    bool amICovered() const {
        return (coverage != nullptr);
    }

    Institution* whereAmIAt() const {
        return location;
    }

    date_type getDOB() const {
        return mDate_of_birth;
    }

    

protected:
};

#endif /* Patient_hpp */
