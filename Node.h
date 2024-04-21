//
// Created by issa on 21/04/24.
//

#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H


class Node {
private:
    int v;
public:
    Node();

    explicit Node(int val);

    void value(int val);

    [[nodiscard]] int value() const;
};


#endif //UNTITLED_NODE_H
