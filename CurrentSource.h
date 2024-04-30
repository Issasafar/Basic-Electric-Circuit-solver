//
// Created by issa on 30/04/24.
//

#ifndef DEMOPROJECT_CURRENTSOURCE_H
#define DEMOPROJECT_CURRENTSOURCE_H


#include "Component.h"

class CurrentSource : public Component {
private:
    using Component::voltage;
public:
    CurrentSource();


    CurrentSource(double val, double resistance);

    CurrentSource(double val, double resistance, Node &start, Node &end);


};


#endif //DEMOPROJECT_CURRENTSOURCE_H
