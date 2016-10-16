//
//  Person.hpp
//  MedRecords
//
//  Created by David Paul Silverstone on Sat, Oct 15th, 2016.
//
//  Abstract base class of Patient and HealthCareProvider classes

#ifndef Person_hpp
#define Person_hpp

#include <string>

class Person {
private:
public:
    Person(std::string name, int ID) : mName(name), mID(ID) {};
    virtual ~Person() {};
    std::string getName() const { return mName; }
    virtual int getID() const { return mID; }

protected:
    std::string mName;
    int mID;// _social_security;
    //place_type mPlace_of_birth; // if we want
};


#endif /* Person_hpp */
