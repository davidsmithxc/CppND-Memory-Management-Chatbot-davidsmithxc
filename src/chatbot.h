#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////
    // TODO Task2: Update ChatBot to Conform to rule of 5
    //          Notes to self: I need to think through how this chatbot ownership
    //          should be working. The ChatLogic creates the ChatBot and needs a handle
    //          to it, but doesn't need to own it. It seems that I should _move_ the ChatBot
    //          from GraphNode to GraphNode. This sort of sounds like I should use a shared
    //          pointer. I guess the *point* in this case is the avoid the need for manually
    //          taking care of "naked" _new_ and _delete_ usage. Though I still haven't wrapped
    //          my  head around it. From the program schematic, it seems that ChatBot isn't
    //          really owned by anyone. ChatBot does own the handle to the image. I need to be
    //          careful here, to not carelessly copy it.
    ChatBot(const ChatBot &source); // (2) copy constructor
    ChatBot& operator=(const ChatBot &source); // (3) copy assignment operator
    ChatBot(ChatBot &&source); // (4) move constructor
    ChatBot& operator=(ChatBot &&source); // (5) move assignment operator
    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() const { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */