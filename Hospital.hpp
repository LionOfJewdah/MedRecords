//
//  Hospital.hpp
//  MedRecords
//
//  Created by David Paul Silverstone on Sat, Oct 15th, 2016.
//
//  Implements Hospital or Clinic Idea

#ifndef Hospital_hpp
#define Hospital_hpp

#include "Institution.hpp"

class Hospital : public Institution {
private:
public:
    Hospital(std::string Name, int hospID) : Institution(Name, hospID) {};
    virtual ~Hospital()  = default;
protected:

};


#endif /* Hospital_hpp */
