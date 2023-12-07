#include <iostream>


namespace node {

    #pragma pack(1)
    struct Node {
        int data;       // 4    + 3 = 8
        Node* next;     // 8
        Node* prev;     // 8
        bool is_fictitious; // 1 + 7 = 8 ??
    };
    #pragma pack()
}

int main()
{
    std::cout << sizeof(node::Node) << std::endl;
    return 0;
}