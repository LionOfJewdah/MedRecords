//
//  Record.hpp
//  MedRecords
//
//  Created by David Paul Silverstone on Sat, Oct 15th, 2016.
//
//  RecordList and Record class

#ifndef Record_hpp
#define Record_hpp

#include <vector>
#include "Patient.hpp"
//#include "HealthCareProvider.hpp" // included in Doctor
#include "Doctor.hpp"
#include "Surgeon.hpp"
#include "EMT.hpp"
//#include "Analyst.hpp"
//#include <ctime>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "Institution.hpp"
#include <algorithm> // std::sort()

class Record {
protected:
    void setIssueDate(date_type d) {
        _date_of_issue = d;
    } // only derived classes can access this
    Patient* pPatient;
    HealthCareProvider* pIssuer;
    Institution* pIssue_Inst;
    date_type _date_of_issue;
    // std::string mCategory;
    //     // can take values "prescription", "disease", "birth", "allergy", "surgery", "labresult", "hospitalization"
    recordClass mCategory;
    //from HealthCareProvider.hpp: `enum class recordClass : int { BIRTH = 0, PHYSICAL = 1, ALLERGY, HOSPITALIZATION, PRESCRIPTION, SURGERY, DISEASE };`
private:
public:
    // Record(Patient* pDude, HealthCareProvider* whoWroteMe/*, std::string whatAmI*/) :
    // pPatient(pDude), pIssuer(whoWroteMe)/*, mCategory(whatAmI) */
    Record(Patient* pDude, HealthCareProvider* whoWroteMe, recordClass whatAmI)
    : pPatient(pDude), pIssuer(whoWroteMe), mCategory(whatAmI)
    {
        //_date_of_issue = day_clock(local_day());
        _date_of_issue = day_clock::local_day();
        if (whoWroteMe) pIssue_Inst = whoWroteMe->getInstitution();
        else pIssue_Inst = 0;
        // safety code against segmentation faults
    };
    // Record(Patient* pDude, HealthCareProvider* whoWroteMe, date_type whenTho/*, std::string whatAmI*/) :
    // pPatient(pDude), pIssuer(whoWroteMe), _date_of_issue(whenTho)/*, mCategory(whatAmI) */
    Record(Patient* pDude, HealthCareProvider* whoWroteMe, date_type whenTho, recordClass whatAmI) :
    pPatient(pDude), pIssuer(whoWroteMe), _date_of_issue(whenTho), mCategory(whatAmI)
    {
        if (whoWroteMe) pIssue_Inst = whoWroteMe->getInstitution();
        else pIssue_Inst = 0;
    };
    virtual ~Record();
    date_type getDateIssued() const {
        return _date_of_issue;
    }
    //virtual void INeedToMakeThisClassAbstract() = 0; // there are no just "records"
    bool operator<(const Record & rhs) {
        return (_date_of_issue < rhs.getDateIssued());
    }
};

class RecordList final {
private:
    std::vector<Record> patientRecords; // a sorted list of the patient's medical records, sorted by date
    // Patient& owner;
    Patient* owner;
public:
    RecordList(Patient* pOwner) {
        owner = pOwner;
    };
    // ~RecordList() {
    //     while (!patientRecords.empty()) {
    //         if (patientRecords.back()) delete patientRecords.back();
    //         patientRecords.pop_back();
    //     } // dynamic memory management
    // }
    // need to add add, which calls std::sort()

    void setOwner(Patient* p) {
        owner = p;
    }
};


#endif /* Record_hpp */
