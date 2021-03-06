//
//  TypesOfRecord.hpp
//  MedRecords
//
//  Created by David Paul Silverstone on Sun, Oct 16th, 2016.
//
//

#ifndef TypesOfRecord_hpp
#define TypesOfRecord_hpp

#include "Record.hpp"
#include "Hospital.hpp"
//using boost::date_time::day_clock;
//using boost::date_time::local_day;
#include "Doctor.hpp"
#include "Surgeon.hpp"
#include "EMT.hpp"
#include "Nurse.hpp"
#include "Oncologist.hpp"
#include "PhysicianAssistant.hpp"
//#include "InsuranceProvider.hpp"

typedef HealthCareProvider HCP;

class birthRecord : public Record {
public:
    birthRecord(Patient* pDude, Doctor* whoBirthedMeh) : Record(pDude, whoBirthedMeh, recordClass::BIRTH) {
        if (pDude) this->setIssueDate(pDude->getDOB());
        else this->setIssueDate(day_clock::local_day());
    }
    ~birthRecord();
};

class hospitalizationRecord : public Record {
protected:
    date_type hospDate;
    date_type releaseDate;
public:
    hospitalizationRecord(Patient* pPatient, HCP* pCaregiver, date_type in_date = day_clock::local_day(), date_type out_date = day_clock::local_day())
    :  Record(pPatient, pCaregiver, recordClass::HOSPITALIZATION, out_date)
    {
        hospDate = in_date;
        releaseDate = out_date;
    };
    ~hospitalizationRecord();
    // void INeedToMakeThisClassAbstract() {}; // jk lol
};

class prescriptionRecord : public Record {
protected:
    std::string _name_of_pharmacy;
public:
    prescriptionRecord(Patient* pDude, HCP* issuer, std::string whoFillingMeMang) : Record(pDude, issuer, recordClass::PRESCRIPTION) {
        _name_of_pharmacy = whoFillingMeMang;
    };
    prescriptionRecord(Patient* pDude, HCP* issuer, date_type when, std::string whoFillingMeMang) : Record(pDude, issuer, recordClass::PRESCRIPTION, when) {
        _name_of_pharmacy = whoFillingMeMang;
    };
    ~prescriptionRecord();
    // void INeedToMakeThisClassAbstract() {}; // jk lol
};

class diseaseRecord : public Record {
protected:
    std::string diseaseName;
    std::string diagnosis;
    //date_type onset;
    //date_type recovery;
public:
    diseaseRecord(Patient* pDude, HCP* issuer, date_type Dt = day_clock::local_day(), std::string n_dis = "Cold", std::string diag = "Sick")
    : Record(pDude, issuer, recordClass::DISEASE, Dt), diseaseName(n_dis), diagnosis(diag)
    {
        // fak man maybe I should have Analyst* issuer
    };
    ~diseaseRecord();
    // void INeedToMakeThisClassAbstract() {}; // jk lol
};

class surgeryRecord : public Record {
protected:
    //Surgeon* pSurgeon; // HealthCareProvider* surgeon;
    std::string operation;
    std::string result;
public:
    surgeryRecord(Patient* pPatient, Surgeon* pSurgeon, date_type Dt = day_clock::local_day(), std::string op = "Surgery", std::string res = "Good")
    : Record(pPatient, pSurgeon, recordClass::SURGERY, Dt)
        {
            operation = op;
            result = res;
            if (op == "") operation = "Surgery";
            if (res == "") result = "Good";
        }
    ~surgeryRecord();
    // void INeedToMakeThisClassAbstract() {}; // jk lol
};

class allergyRecord : public Record {
protected:
    std::string allergies; // HealthCareProvider* surgeon;
    //std::string operation;
    //std::string result;
public:
    allergyRecord(Patient* pDude, HCP* issuer, date_type Dt = day_clock::local_day(), std::string what_al = "Pollen") : Record(pDude, issuer, recordClass::ALLERGY, Dt), allergies(what_al) {};
    ~allergyRecord(); // Analyst* issuer
    // void INeedToMakeThisClassAbstract() {}; // jk lol
};

/*
class labTest : public Record, virtual public surgeryRecord, virtual public allergyRecord, virtual public diseaseRecord {
protected:
    Institution* whoOrderedIt;
    std::string thingYoureTestingFor;
    std::string result;
    bool isSurgeryRec;
    bool isAllergyRec;
    bool isDiseaseRec;
public:
    labTest();
    ~labTest();
    // void INeedToMakeThisClassAbstract() {}; // jk lol
};
*/


#endif /* TypesOfRecord_hpp */
