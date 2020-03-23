#pragma once

#include <map>
#include <string>

#include "execution_node.h"

namespace execution_graph {

struct ExtendGraph {
    int which;
    ExecutionGraph* self;
    ExecutionGraph* parent;

    ExtendGraph() : which(-1), self(nullptr), parent(nullptr) {}
    ~ExtendGraph() = default;
};

// ExecutionGraph用于维护图的执行结点
// 图的创建过程如下：
//   ExecutionGraph *execution_graph = new ExecutionGraph();
//   // 添加开始执行结点
//   ExecutionNode *execution_node =
//       execution_graph->AddStartExecutionNode("operator1");
//   // 添加普通执行结点
//   execution_node = execution_node->AddExecutionNode("operator2");

class ExecutionGraph {
    friend class TrafficDistribution;
public:
    ExecutionGraph();
    virtual ~ExecutionGraph();

    // 执行器初始化
    bool Init(Context* global_context, int traffic_type);

    // 添加开始执行结点
    ExecutionNode* AddStartExecutionNode(const std::string& operator_name);

    // 设置出口结点
    // 该结点之前的结点执行失败后统一跳转到该结点
    // 该结点之后的结点都被执行，不做是否执行成功的判断
    void SetExitExecutionNode(ExecutionNode* node) {exit_node_ = node;}

    // Operator耗时、成功失败等信息上报
    const std::string DebugString();

    // 思南日志上报
    // void StatisticsToJson(Json::Value *json_value);

    bool GraphClipping(const std::string& op_name, CommonOperator* ut_op, int sequence);

    // void UtRun(Context *request_context, Context *frame_context);

    void PushNode(const std::string& op, ExecutionNode* node) {
        nodes_[op] = node;
    }
    ExecutionNode* SearchNode(const std::string& op) {
        return nodes_[op];
    }
    void SetDependency(const std::string& op_a, const std::string& op_b) {
        dependency_[op_a].push_back(op_b);
    }
    void FillExtendInfo(ExecutionGraph* parent, int which);
    int32_t GetNestPartition() {
        return extend_info.which;
    }

private:
    friend class ExecutionNode;
    friend class PartitionOperator;

    ExecutionGraph(const ExecutionGraph& graph);
    // 执行器执行入口
    void Run(Context* request_context, Context* frame_context);

    // 检查graph是否合法
    bool IsValidGraph(ExecutionNode* node,
                      std::map<ExecutionNode*, bool>* visited_node_map);
    bool IsValidGraph();

    // 初始化结点的operator
    bool InitNodeOperator(ExecutionNode* node);
    bool InitGraphOperators(ExecutionNode* node);
    void ClearGraph();

    void DebugString(ExecutionNode* node, std::string* result);
    // void StatisticsToJson(ExecutionNode* node, Json::Value* json_value);

    bool RunSubGraph(ExecutionNode* current_node,
                     Context* request_context,
                     Context* frame_context);
    void RunSubParallelGraph(ExecutionNode* current_node,
                             Context* request_context,
                             Context* frame_context);
    bool RunCurrentExecutionNode(ExecutionNode* current_node,
                                 Context* request_context,
                                 Context* frame_context);
    void CutList(ExecutionNode* final_node,
                 ExecutionNode* ut_node,
                 bool after_exit);

    ExecutionNode* start_node_;  // 头部结点
    ExecutionNode* exit_node_;  // 出口结点

    Context* global_context_;
    int traffic_type_;
    // clsTimer timer_;
    std::map<std::string, ExecutionNode*> nodes_;
    std::map<std::string, vector<std::string>> dependency_;
    ExtendGraph extend_info;
};

}  // namespace execution_graph
