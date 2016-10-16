#include "Patient.hpp"
#include "Record.hpp"

Patient::~Patient(){
   delete whereMyRecordsAt;
}
