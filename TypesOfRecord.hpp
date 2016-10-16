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

class birthRecord : public Record {
    birthRecord();
    ~birthRecord();
};

class hospitalizationRecord : public Record {
private:
    date_type hospDate;
    date_type releaseDate;
public:
    hospitalizationRecord();
    ~hospitalizationRecord();
};

class prescriptionRecord : public Record {
protected:
    std::string _name_of_pharmacy;
public:
    prescriptionRecord(Patient* pDude, Institution* issuer, std::string whoFillingMeMang) : Record(pDude, issuer, "prescription") {
        _name_of_pharmacy = whoFillingMeMang;
    };
    prescriptionRecord(Patient* pDude, Institution* issuer, date_type when, std::string whoFillingMeMang) : Record(pDude, issuer, when, "prescription") {
        _name_of_pharmacy = whoFillingMeMang;
    };
    ~prescriptionRecord();
private:
    //
};

class diseaseRecord : public Record {
protected:
    std::string diseaseName;
    std::string diagnosis;
    //date_type onset;
    //date_type recovery;
public:
    diseaseRecord(Patient* pDude, Institution* issuer, std::string n_dis, std::string diag) : Record(pDude, issuer, "disease"), diseaseName(n_dis), diagnosis(diag) {

    };
    ~diseaseRecord();
};

class surgeryRecord : public Record {
protected:
    //Surgeon* pSurgeon; // HealthCareProvider* surgeon;
    std::string operation;
    std::string result;
public:
    surgeryRecord(Patient* pP, Institution* pI, Surgeon* pS)
    : Record(pP, pI, "surgery")
        {

        }
    ~surgeryRecord();

};

class allergyRecord : public Record {
protected:
    std::string allergies; // HealthCareProvider* surgeon;
    //std::string operation;
    //std::string result;
public:
    allergyRecord(Patient* pDude, Institution* issuer, std::string what_al) : Record(pDude, issuer, "allergy"), allergies(what_al) {};
    ~allergyRecord();
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
};
*/


#endif /* TypesOfRecord_hpp */
