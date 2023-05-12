#include "graphedge.h"
#include "graphnode.h"
#include <memory>

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    // TASK 5
    // not needed anymore, since smart pointer handles the destruction of the object itself
    // delete _chatBot;

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(/*GraphEdge *edge*/ std::unique_ptr<GraphEdge> edge)
{
    // BEFORE: _childEdges.push_back(edge);
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    // TASK 5
    // BEFORE: _chatBot = chatbot;
    // BEFORE: _chatBot->SetCurrentNode(this);
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    // TASK 5
    // BEFORE: newNode->MoveChatbotHere(_chatBot);
    newNode->MoveChatbotHere(std::move(_chatBot));
    //_chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    // BEFORE: return _childEdges[index];
    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}