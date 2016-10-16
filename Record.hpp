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
    Record();
    virtual ~Record();
protected:

};

class RecordList final {
private:
    std::vector<Record*> patientRecords; // a sorted list of
    Patient& owner;
public:
    RecordList() = default;
    ~RecordList() {
        while (!patientRecords.empty()) {
            if (patientRecords.back()) delete patientRecords.back();
            patientRecords.pop_back();
        } // dynamic memory management
    }
};


#endif /* Record_hpp */
