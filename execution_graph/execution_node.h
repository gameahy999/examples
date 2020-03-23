#pragma once

#include <map>
#include <string>
#include <vector>

#include "common_operator.h"
#include "partition_operator.h"

namespace execution_graph {

class ExecutionGraph;

enum TIMEOUT_STRATEGY {
    IGNORE = 0,
    SKIP_CURRENT
};

struct ExecutionNodeOptions {
    uint64_t time_ms = std::numeric_limits<uint64_t>::max();
    TIMEOUT_STRATEGY time_strategy = IGNORE;
};

class ExecutionNode {
    friend class ExecutionGraph;
public:
    enum NodeType {
        NODE_TYPE_SERIAL = 0,
        NODE_TYPE_PARALLEL,
        NODE_TYPE_PARTITION,
        NODE_TYPE_CONDITION
    };

    ExecutionNode(const ExecutionNode& node, ExecutionGraph* execution_graph);
    virtual ~ExecutionNode();


};

}  // namespace execution_graph
