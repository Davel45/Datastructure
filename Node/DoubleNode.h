//
// Created by Vadim on 11.04.2024.
//

#ifndef DATASTRUCTURE_DOUBLENODE_H
#define DATASTRUCTURE_DOUBLENODE_H
#include <memory>

namespace doublenode {
    template<typename T>
    struct DoubleNode {
        T data;
        std::shared_ptr<DoubleNode> next;
        std::weak_ptr<DoubleNode> previous;

        DoubleNode(T data) : data{data} {}
    };
}
#endif //DATASTRUCTURE_DOUBLENODE_H
