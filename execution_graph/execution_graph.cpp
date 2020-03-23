#include "execution_graph.h"

namespace execution_graph {

ExecutionGraph::ExecutionGraph() {
    // TODO
}

ExecutionGraph::~ExecutionGraph() {
    // TODO
}

ExecutionGraph::ExecutionGraph(const ExecutionGraph& graph) {
    // TODO
}

bool ExecutionGraph::Init(Context* global_context, int traffic_type) {
    // TODO
    return false;
}

ExecutionNode* ExecutionGraph::AddStartExecutionNode(const std::string& operator_name) {
    // TODO
    return nullptr;
}

const std::string ExecutionGraph::DebugString() {
    // TODO
    return "";
}

bool ExecutionGraph::GraphClipping(const std::string& op_name, CommonOperator* ut_op, int sequence) {
    // TODO
    return false;
}

void ExecutionGraph::FillExtendInfo(ExecutionGraph* parent, int which) {
    // TODO
    return false;
}

void ExecutionGraph::Run(Context* request_context, Context* frame_context) {
    // TODO
}

bool ExecutionGraph::IsValidGraph(ExecutionNode* node,
                                  std::map<ExecutionNode*, bool>* visited_node_map) {
    // TODO
    return false;
}

bool ExecutionGraph::IsValidGraph() {
    // TODO
    return false;
}

bool ExecutionGraph::InitNodeOperator(ExecutionNode* node) {
    // TODO
    return false;
}

bool ExecutionGraph::InitGraphOperators(ExecutionNode* node) {
    // TODO
    return false;
}

void ExecutionGraph::ClearGraph() {
    // TOOD
}

void ExecutionGraph::DebugString(ExecutionNode* node, std::string* result) {
    // TODO
}

bool ExecutionGraph::RunSubGraph(ExecutionNode* current_node,
                                 Context* request_context,
                                 Context* frame_context) {
    // TODO
    return false;
}

void ExecutionGraph::RunSubParallelGraph(ExecutionNode* current_node,
                                         Context* request_context,
                                         Context* frame_context) {
    // TODO
}

bool ExecutionGraph::RunCurrentExecutionNode(ExecutionNode* current_node,
                                             Context* request_context,
                                             Context* frame_context) {
    // TODO
    return false;
}

void ExecutionGraph::CutList(ExecutionNode* final_node,
                             ExecutionNode* ut_node,
                             bool after_exit) {
    // TODO
}


}  // namespace execution_graph
