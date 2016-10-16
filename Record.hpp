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
#include "Doctor.hpp"
#include <ctime>
#include "Institution.hpp"
#include <algorithm> // std::sort()

class Record {
private:
public:
    Record(Patient* pDude, Institution* whoWroteMe, std::string whatAmI) : pPatient(pDude), pIssue(whoWroteMe), mCategory(whatAmI) {
        _date_of_issue = *(localtime(time(0)));
    };
    Record(Patient* pDude, Institution* whoWroteMe, date_type whenTho, std::string whatAmI) : pPatient(pDude), pIssue(whoWroteMe), _date_of_issue(whenTho), mCategory(whatAmI) {};
    virtual ~Record();
protected:
    Patient* pPatient;
    Institution* pIssue;
    date_type _date_of_issue;
    std::string mCategory;
        // can take values "prescription", "disease", "birth", "allergy", "surgery", "labresult", "hospitalization"
};

class RecordList final {
private:
    std::vector<Record*> patientRecords; // a sorted list of the patient's medical records, sorted by date
    Patient& owner;
public:
    RecordList(Patient& rOwner) {
        owner = rOwner;
    };
    ~RecordList() {
        while (!patientRecords.empty()) {
            if (patientRecords.back()) delete patientRecords.back();
            patientRecords.pop_back();
        } // dynamic memory management
    }
};


#endif /* Record_hpp */
