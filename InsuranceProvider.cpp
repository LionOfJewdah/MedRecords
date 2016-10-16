#include "InsuranceProvider.hpp"
#include "Patient.hpp"

bool InsuranceProvider::hasAccessTo(Patient* p) const {
    if (!p) return false;
    if (p->whosCoveringMe() == this) return true;
    return false;
}
