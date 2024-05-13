//
// Created by issa on 12/05/24.
//

#ifndef DEMOPROJECT_CURRENT_H
#define DEMOPROJECT_CURRENT_H



#include "ElectricalProperty.h"
class Current : public ElectricalProperty {
protected:
    std::string get_type() const override;
public:
    Current();
    Current(const double value, bool known);
};
#endif //DEMOPROJECT_CURRENT_H
