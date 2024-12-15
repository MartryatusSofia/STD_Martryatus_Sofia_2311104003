#include <iostream>
#include <queue>

using namespace std;

struct ElmNode;

struct ElmEdge {
    ElmNode *Node;
    ElmEdge *Next;
};

struct ElmNode {
    char info;
    bool visited;
    ElmEdge *firstEdge;
    ElmNode *Next;
};

struct Graph {
    ElmNode *first;
};

void createGraph(Graph &G) {
    G.first = NULL;
}

void insertNode(Graph &G, char X){
    ElmNode *newNode = new ElmNode;
    newNode->info = X;
    newNode->visited = false;
    newNode->firstEdge = NULL;
    newNode->Next = NULL;

    if(G.first == NULL){
        G.first = newNode;
    } else {
        ElmNode *temp = G.first;
        while (temp->Next != NULL){
            temp = temp->Next ;
        }
        temp-> Next = newNode;
    }
}

void connectNode(ElmNode *N1, ElmNode *N2){
    ElmEdge *newEdge = new ElmEdge;
    newEdge -> Node = N2;
    newEdge -> Next = N1->firstEdge;
    N1->firstEdge = newEdge;
}

void PrintInfoGraph(Graph G) {
    ElmNode *temp = G.first;
    while (temp != NULL){
        cout << temp->info << " ";
        temp = temp->Next;
    }
    cout << endl;
}

void ResetVisited(Graph &G){
    ElmNode *temp = G.first;
    while (temp !=NULL){
        temp->visited = false;
        temp = temp->Next;
    }
}

void printDFS(Graph G, ElmNode *N){
    if (N == NULL){
        return;
    }
    N->visited = true;
    cout << N->info << " ";
    ElmEdge *edge = N->firstEdge;
    while (edge != NULL){
        if (!edge->Node->visited){
            printDFS(G, edge->Node);
        }
        edge = edge->Next;
    }
}

void printBFS(Graph G, ElmNode *N){
    queue<ElmNode*> q;
    q.push(N);
    N->visited = true;

    while(!q.empty()) {
        ElmNode *current = q.front();
        q.pop();
        cout << current->info << " ";

        ElmEdge *edge = current->firstEdge;
        while (edge != NULL) {
            if (!edge->Node->visited) {
                edge->Node->visited = true;
                q.push(edge->Node);
            }
            edge = edge->Next;
        }
    }
}

int main(){
    Graph G;
    createGraph(G);

    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');
    insertNode(G, 'F');
    insertNode(G, 'G');
    insertNode(G, 'H');

    ElmNode *A =G.first;
    ElmNode *B =A->Next;
    ElmNode *C =B->Next;
    ElmNode *D =C->Next;
    ElmNode *E =D->Next;
    ElmNode *F =E->Next;
    ElmNode *G1 =F->Next;
    ElmNode *H =G1->Next;

    connectNode(A, B);
    connectNode(A, C);
    connectNode(B, D);
    connectNode(B, E);
    connectNode(C, F);
    connectNode(C, G1);
    connectNode(D, H);

    cout << "DFS traversal: ";
    ResetVisited(G);
    printBFS(G, A);
    cout << endl;

    return 0;
}