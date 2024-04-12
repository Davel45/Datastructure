//
// Created by Vadim on 12.04.2024.
//

#ifndef DATASTRUCTURE_QUEUENODE_H
#define DATASTRUCTURE_QUEUENODE_H
#include <memory>
namespace queuenode {
    template<typename T>
    struct QueueNode {
        T data;
        std::shared_ptr<QueueNode> next;
        weak_ptr<QueueNode> previous;

        QueueNode(T data) : data{data} {}
    };
}
#endif //DATASTRUCTURE_QUEUENODE_H
