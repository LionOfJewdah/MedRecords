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

#include "Person.hpp"
#include "HealthCareProvider.hpp"
#include "InsuranceProvider.hpp"
// #include <vector>
#include <set>
#include <ctime> // time.h

typedef struct tm date_type;

class RecordList; // forward declaration

class Patient final : public Person {
private:
    sex mGender;
    date_type mDate_of_birth;
    // std::vector<Person*> mNextOfKin;
    // HealthCareProvider* primaryCarePhysician;
    std::set<HealthCareProvider*> authorizedDoctors;
    RecordList* whereMyRecordsAt;
    InsuranceProvider* coverage; // NULL if they have no insurance
    Institution* whereAmIAt; // NULL if not in a hospital or clinic, else points to the thing
    typedef std::set<HealthCareProvider*>::iterator guysWhoCanTreatMe;
public:

    Patient(std::string name, int ID, sex gender)
        : Person(name, ID), mSex(gender) {
            mDate_of_birth = _date_of_issue = *(localtime(time(0)));
            whereAmIAt = nullptr;
        };
    Patient(std::string name, int ID, sex gender, date_type dob)
        : Person(name, ID), mDate_of_birth(dob), mSex(gender) {
            whereAmIAt = nullptr;
        };
    ~Patient();
    sex getSex() { return mGender; }
    bool isAuthorized (HealthCareProvider* pDude) const {
        guysWhoCanTreatMe goIteratorGo = authorizedDoctors.find(pDude);
        return (goIteratorGo != authorizedDoctors.end());
    } // true if found, else false
    bool authorize (HealthCareProvider* pDude) {
        pair<guysWhoCanTreatMe, bool> thing = authorizedDoctors.insert(pDude);
        return thing.second;
    } // false if pDude was already authorized, true if newly authorized
    bool deauthorize (HealthCareProvider* pDude) {
        int wereTheGuyThere = authorizedDoctors.erase(pDude);
        return ((bool) wereTheGuyThere);
    } // true if was removed, false if wasn't found
    InsuranceProvider* whosCoveringMe() const {
        return coverage;
    }
protected:
};

#endif /* Patient_hpp */
