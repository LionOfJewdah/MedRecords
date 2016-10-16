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
    hospitalizationRecord();
    ~hospitalizationRecord();
};

class prescriptionRecord : public Record {
protected:
    std::string _name_of_pharmacy;
public:
    prescriptionRecord();
    ~prescriptionRecord();
private:
    //
};

class diseaseRecord : public Record {

public:
    diseaseRecord();
    ~diseaseRecord();
};

class surgeryRecord : public Record {

public:
    surgeryRecord();
    ~diseaseRecord();
    
};




#endif /* TypesOfRecord_hpp */
