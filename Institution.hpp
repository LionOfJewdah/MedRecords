//
//  Institution.hpp
//  MedRecords
//
//  Created by David Paul Silverstone on Sat, Oct 15th, 2016.
//
//

#ifndef Institution_hpp
#define Institution_hpp

#include <string>

class Institution {
private:
public:
    Institution(std::string name, int ID) {
        mName = name;
        mInstID = ID;
    }
    virtual ~Institution() = default;
    std::string getName() const { return mName; }
    int getID() { return mInstID; }
    virtual std::string typeOfInst() const {
        return "Institution";
    }
protected:
    std::string mName;
    int mInstID;
};


#endif /* Institution_hpp */
