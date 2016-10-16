//
//  Person.hpp
//  MedRecords
//
//  Created by David Paul Silverstone on Sat, Oct 15th, 2016.
//
//  Abstract base class of patient and "doctor" classes

#ifndef Person_hpp
#define Person_hpp

#include <string>
#include <ctime> // time.h

typedef struct tm date_type;

class Person {
private:
public:
    Person(std::string name, int ID, date_type dob, sex gender) : mDate_of_birth(dob), mSex(gender), mID(ID), mName(name) {
    }
    virtual ~Person() {};
    std::string getName() { return mName; }
    virtual int getID() { return mID; }

protected:
    std::string mName;
    int mID;// _social_security;
    date_type mDate_of_birth;
    
    //place_type mPlace_of_birth; // if we want
};


#endif /* Person_hpp */
