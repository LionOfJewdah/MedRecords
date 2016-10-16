//
//  dataBaseSystem.hpp
//  MedRecords
//
//  Created by David Paul Silverstone on Sun, Oct 16th, 2016.
//
//  We didn't have time to implement this :(

#ifndef dataBaseSystem_hpp
#define dataBaseSystem_hpp

#include <map>
#include "Record.hpp"
#include "Patient.hpp"

class dataBaseSystem {
private:
    std::map<int, Patient*> whosWho;
    std::map<int, RecordList*> whosAreWhose;
public:
    dataBaseSystem();
    ~dataBaseSystem();
protected:

};


#endif /* dataBaseSystem_hpp */
