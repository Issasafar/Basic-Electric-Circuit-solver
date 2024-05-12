//
// Created by issa on 10/05/24.
//

#ifndef DEMOPROJECT_VOLTAGE_H
#define DEMOPROJECT_VOLTAGE_H


class Voltage {
protected:
double v;
bool is_known;
public:
    Voltage();
    Voltage(const double voltage, bool known);
    void voltage(const double voltage);
    double voltage() const;
    bool known() const;
    void known(bool predicate);
};

#endif //DEMOPROJECT_VOLTAGE_H
