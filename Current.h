//
// Created by issa on 12/05/24.
//

#ifndef DEMOPROJECT_CURRENT_H
#define DEMOPROJECT_CURRENT_H


class Current {
private:
    double c;
    bool is_known;
public:
    Current();
    Current(const double current, bool known);
    void current(const double current);
    double current() const;
    bool known() const;
    void known(bool predicate);
};


#endif //DEMOPROJECT_CURRENT_H
