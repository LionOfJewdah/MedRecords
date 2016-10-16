//
//  Lab.hpp
//  MedRecords
//
//  Created by David Paul Silverstone on Sat, Oct 15th, 2016.
//
//

#ifndef Lab_hpp
#define Lab_hpp

#include "Institution.hpp"

class Lab : public Institution {
private:
    Institution* partOf;
public:
    Lab();
    ~Lab();
protected:

};


#endif /* Lab_hpp */
