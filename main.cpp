#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <chrono>

#include <cassert>
#include <sstream>


using namespace std;

class Edge;
class Node;

long inserts = 0;
long deletemins = 0;
long updates = 0;
long siftUps = 0;
long siftDowns = 0;
chrono::milliseconds dijkstraDuration;


#define LOG(x) std::cout << x << std::endl
#define READ(x) cin >> x
#define DIMACS 0
#define GENERATE 1
#define LOGS true
#define RODADAS 20

template <int N>
class KNode {
public:
    Node* value;
    int priority;
    vector<KNode<N>*> children;
    KNode<N>* parent;

    explicit KNode(Node* value, int priority) : value(value), priority(priority){
        for(int i = 0; i < N; i++){
            children.push_back(nullptr);
        }
    }

    KNode* getChild(int n){
        return (n < children.size()) ? children[n] : nullptr;
    }

    void setParent(KNode* newParent) {
        parent = newParent;
    };

    void insert(int pos, KNode<N>* newChild){
        children[pos] = newChild;
    }

    bool operator<(const KNode<N>& other) const {
        //std::cout << "Called operator< with priority " << priority << " compared to " << other.priority << std::endl;
        return priority < other.priority;
    }

    bool operator>(const KNode<N>& other) const {
        //std::cout << "Called operator> with priority " << priority << " compared to " << other.priority << std::endl;
        return priority > other.priority;
    }
};

class Node {
public:
    static const char NOT_EXPLORED = 0;
    static const char INSERTED = 1;
    static const char EXPLORED = 2;

    char explored = NOT_EXPLORED; // 0=not explored -  1=inserted - 2=explored
    int trueDistance = 0;
    KNode<1>* heapNode = nullptr;
    Edge* edges = nullptr;
};

void reset(vector<Node*> &nodes){
    for(Node* node : nodes){
        node->explored = Node::NOT_EXPLORED;
        node->trueDistance = 0;
        node->heapNode = nullptr;
    }
}

class Edge {
public:
    int targetIdx;
    int weight;
    Edge* next = nullptr;
};

template <int K>
class KHeap {
private:
    KNode<K> *root = nullptr;
    int length = 0;

public:
    bool empty(){
        return root == nullptr;
    }

    vector<int>* getKBaseIdx(int idx){
        if(idx == 0){
            return nullptr;
        }
        if(idx > length){
            return nullptr;
        }

        idx--;
        int depth = 0;
        int depthElsCount = 1;
        while(idx >= 0){
            idx -= depthElsCount;
            depthElsCount *= K;
            depth++;
        }
        depthElsCount /= K;
        depth--;
        idx += depthElsCount;

        int finalRowIdx = idx;

        auto* vec = new vector<int>();
        for(int row = 1; row <= depth; row++){
            vec->push_back(finalRowIdx % K);
            finalRowIdx /= K;
        }

        reverse(vec->begin(),vec->end());

        return vec;
    }

    KNode<K>* getElement(int idx){
        if(idx <= 0)
            return nullptr;

        if(idx == 1)
            return root;

        KNode<K>* el = root;

        auto* stepsToIdx = getKBaseIdx(idx);

        for(int i : *stepsToIdx) {
            el = el->getChild(i);
            if(el == nullptr) break;
        }

        delete stepsToIdx;
        return el;
    }

    void swap(KNode<K>* node1, KNode<K>* node2){
        KNode<K>* parentNode1 = node1->parent;
        KNode<K>* parentNode2 = node2->parent;

        for(int i = 0; i < K; i++){
            if(node1->children[i] == node2)
                node1->children[i] = node1;
            else
                if(node1->children[i]) node1->children[i]->parent = node2;

            if(node2->children[i] == node1)
                node2->children[i] = node2;
            else
                if(node2->children[i]) node2->children[i]->parent = node1;

            KNode<K>* tempRef = node1->children[i];
            node1->children[i] = node2->children[i];
            node2->children[i] = tempRef;
        }

        // update grandparent
        if(parentNode1 == node2) {
            node2->parent = node1;
        } else {
            if(parentNode1) for(int i = 0; i < K; i++){
                if(parentNode1->children[i] == node1){
                    parentNode1->children[i] = node2;
                    break;
                }
            }
            node2->parent = parentNode1;
        }

        // update grandparent
        if(parentNode2 == node1) {
            node1->parent = node2;
        } else {
            // update grandparent
            if(parentNode2) for(int i = 0; i < K; i++){
                if(parentNode2->children[i] == node2){
                    parentNode2->children[i] = node1;
                    break;
                }
            }

            node1->parent = parentNode2;
        }
    }

    KNode<K>* insert(Node* value, int priority){
        inserts++;
        if(length <= 0){
            root = new KNode<K>(value, priority);
            length = 1;
            return root;
        }

        length++;
        auto* stepsToIdx = getKBaseIdx(length);

        KNode<K>* parentNode = root;
        for(int vecIdx = 0; vecIdx < stepsToIdx->size() - 1; vecIdx++){
            parentNode = parentNode->getChild(stepsToIdx->at(vecIdx));
        }

        auto* newNode = new KNode<K>(value, priority);
        newNode->setParent(parentNode);
        parentNode->insert(stepsToIdx->at(stepsToIdx->size()-1), newNode);

        value->heapNode = reinterpret_cast<KNode<1>*>(newNode);
        value->explored = Node::INSERTED;

        KNode<K>* possibleNewRoot = siftUp(newNode);
        if(possibleNewRoot != nullptr){
            root = possibleNewRoot;
        }
        delete stepsToIdx;

        return newNode;
    }

    KNode<K>* siftUp(KNode<K>* el){
        while(el->parent && (*el) < (*el->parent)){
            swap(el, el->parent);
            siftUps++;
        }
        if(el->parent == nullptr){
            return el;
        } else {
            return nullptr;
        }
    }

    KNode<K>* siftDown(KNode<K>* el){
        KNode<K>* possibleNewRoot = el;
        bool swapped = true;
        bool firstSwap = true;
        while(swapped){
            swapped = false;

            if(!el->children[0]){
                break;
            }
            int minEl = el->children[0]->priority;
            int minIdx = 0;

            for(int i = 1; i < K; i++){
                if(!el->children[i])
                    break;
                if(el->children[i]->priority < minEl){
                    minIdx = i;
                    minEl = el->children[i]->priority;
                }
            }

            if((*el->children[minIdx]) < (*el)){
                if(firstSwap){
                    possibleNewRoot = el->children[minIdx];
                    firstSwap = false;
                }
                swap(el, el->children[minIdx]);
                siftDowns++;
                swapped = true;
            }
        }

        while(possibleNewRoot->parent != nullptr){
            possibleNewRoot = possibleNewRoot->parent;
        }

        return possibleNewRoot;
    }

    void delNode(KNode<K>* node){
        if(node->parent){
            for(int i = 0; i < node->parent->children.size(); i++){
                KNode<K>* child = node->parent->children.at(i);
                if(child && child == node){
                    node->parent->children[i] = nullptr;
                    break;
                }
            }
            node->parent = nullptr;
        }
        for(int i = 0; i < node->children.size(); i++){
            KNode<K>* child = node->children.at(i);
            if(child){
                child->parent = nullptr;
            }
            node->children[i] = nullptr;
        }
    }

    KNode<K>* delMin(){
        KNode<K>* lastEl = getElement(length);
        swap(root, lastEl);
        KNode<K>* oldRoot = root;
        root = lastEl;


        oldRoot->value->explored = Node::EXPLORED;

        delNode(oldRoot);
        length--;
        deletemins++;

        if(length == 0){
            root = nullptr;

        } else {
            KNode<K>* possibleRoot = siftDown(root);
            if(possibleRoot){
                root = possibleRoot;
            }
        }

        return oldRoot;
    }

    void update(KNode<K>* el, int newPriority){
        el->priority = newPriority;
        updates++;

        KNode<K>* possibleNewRoot = siftUp(el);
        if(possibleNewRoot != nullptr){
            root = possibleNewRoot;
        }
    }

    void print(){
        if(length == 0) {
            LOG("empty");
            return;
        }
        auto* vector = getKBaseIdx(length);


        int len;
        if(vector == nullptr){
            len = 0;
        } else {
            len = vector->size();
        }
        int spaces = pow(K, len) * 3;

        queue<KNode<K>*> myQueue;
        myQueue.push(root);

        for(int row = 0; row <= len; row++){
            bool first = true;
            for(int elIdx = 0; elIdx < pow(K, row); elIdx++){
                if(myQueue.empty()){
                    cout << endl;
                    delete vector;
                    return;
                }
                KNode<K>* el = myQueue.front();
                myQueue.pop();

                bool bar = false;
                if(elIdx % K == 0 && !first) bar = true;
                for(int iter = 0; iter < K; iter++){
                    if(el->children[iter] != nullptr){
                        myQueue.push(el->children[iter]);
                    } else {
                        break;
                    }
                }

                for(int iter = 0; iter < (spaces/pow(K,row)-1)/2; iter++){
                    cout << (bar ? "|" : " ");
                    bar = first = false;
                }

                cout << el->priority;

                for(int iter = 0; iter < (spaces/pow(K,row)-1)/2; iter++){
                    cout << " ";
                }

            }
            cout << endl;
        }
        delete vector;
    }
};

void dijkstra(vector<Node*> &nodes, int startingNode){
    const int K = 4;
    KHeap<K> queue;

    queue.insert(nodes[startingNode], 0);

    while(!queue.empty()){
        KNode<K>* currKNode = queue.delMin();
        Node* currNode = currKNode->value;
        currNode->trueDistance = currKNode->priority;

        Edge* edges = currNode->edges;
        while(edges != nullptr){
            int newWeight = currKNode->priority + edges->weight;
            Node* nextNode = nodes[edges->targetIdx];


            if(nextNode->explored == Node::NOT_EXPLORED){
                queue.insert(nextNode, newWeight);
            } else if (nextNode->explored == Node::INSERTED) {
                int currWeight = nextNode->heapNode->priority;
                if(newWeight < currWeight){
                    queue.update(reinterpret_cast<KNode<K>*>(nextNode->heapNode),newWeight);
                }
            }

            edges = edges->next;
        }
        delete(currKNode);
    }
}

void generateGraph(int argc, char* argv[], vector<Node*>& graph, int& nodesCount, int& edgeCount){

    double edgeChance = 0.2;
    if(argc == 3){
        nodesCount = atoi(argv[1]);
        edgeChance = atof(argv[2]);
    }

    int maxWeight = 10000;

    srand48(time(nullptr));

    for(int i=0; i < nodesCount; i++)
        graph.push_back(new Node());

    for(int i=0; i < nodesCount; i++)
        for(int j=0; j < nodesCount; j++)
            if (i != j && drand48() < edgeChance) {
                edgeCount++;
                Edge* e = new Edge();
                e->targetIdx = j;
                e->weight = lrand48()%maxWeight;
                Edge* lastEdge = graph.at(i)->edges;
                if(lastEdge == nullptr) {
                    graph.at(i)->edges = e;
                } else {
                    while(lastEdge->next != nullptr){
                        lastEdge = lastEdge->next;
                    }
                    lastEdge->next = e;
                }
            }
}


void readDimacs(istream& in, vector<Node*>& graph, int& nodesCount, int& edgeCount) {
    string line, dummy;
    while (line.substr(0,4) != "p sp")
        getline(in,line);

    // (1) get nodes and edges
    stringstream linestr;
    linestr.str(line);

    linestr >> dummy >> dummy >> nodesCount >> edgeCount;

    for(int i=0; i < nodesCount; i++)
        graph.push_back(new Node());

    unsigned i=0;
    while (i<edgeCount) {
        getline(in,line);
        if (line.substr(0,2) == "a ") {
            stringstream arc(line);
            int srcNodeIdx,targetNode,weight;
            char ac;
            arc >> ac >> srcNodeIdx >> targetNode >> weight;

            srcNodeIdx--;
            targetNode--;

            Edge* e = new Edge();
            e->targetIdx = targetNode;
            e->weight = weight;
            Node* srcNode = graph.at(srcNodeIdx);
            Edge* lastEdge = srcNode->edges;
            if(lastEdge == nullptr) {
                srcNode->edges = e;
            } else {
                while(lastEdge->next != nullptr)
                    lastEdge = lastEdge->next;
                lastEdge->next = e;
            }

            i++;
        }
    }
    if(LOGS)
        cout << "finished reading" << endl;
}

void printStats(){
    if(!LOGS)
        return;
    LOG("***************************************");
    LOG("");
    cout << "Inserts    ->  " << inserts / RODADAS << endl;
    cout << "Deletes    ->  " << deletemins / RODADAS << endl;
    cout << "Updates    ->  " << updates / RODADAS << endl;
    cout << "Sift Ups   ->  " << siftUps / RODADAS << endl;
    cout << "Sift Downs ->  " << siftDowns / RODADAS << endl;
    cout << "Duration   ->  " << dijkstraDuration.count() / RODADAS << "ms" << endl;
    LOG("");
    LOG("***************************************");
}

void roda(int argc, char *argv[], int nodesCount, int edgeCount, vector<Node*> &graph, char processing){
    // (2) print example path
    int src = -1;
    int dst = -1;

    if(argc == 3 && processing == DIMACS){
        src = atoi(argv[1]) - 1;
        dst = atof(argv[2]) - 1;
    } else {
        src = lrand48()%nodesCount;
        dst = lrand48()%nodesCount;
    }


    auto start = chrono::high_resolution_clock::now();
    dijkstra(graph, src);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    dijkstraDuration += duration;

    if(src != -1 && dst != -1) {
        if(graph[dst]->explored == Node::NOT_EXPLORED) {
            cerr << "inf" << endl;
        } else {
            cerr << "Distance between " << src+1 << " and " << dst+1 << " is " << graph[dst]->trueDistance << endl;
        }
    } else {
        for(int i = 0; i < graph.size(); i++)
            cerr << "Distance between " << src+1 << " and " << i+1 << " is " << graph[i]->trueDistance << endl;
    }

}

int main(int argc, char *argv[]) {

    vector<Node*> graph;
    int nodesCount, edgeCount;

    char processing = GENERATE;
    if(processing == GENERATE){
        generateGraph(argc, argv, graph, nodesCount, edgeCount);
    } else if (processing == DIMACS){
        readDimacs(cin, graph, nodesCount, edgeCount);
    }

    for(int i = 0; i < RODADAS; i++){
        roda(argc, argv, nodesCount, edgeCount, graph, processing);
        reset(graph);
        LOG(i);
        if(processing == GENERATE){
            graph.clear();
            generateGraph(argc, argv, graph, nodesCount, edgeCount);
        }
    }

    printStats();

    return 0;
}
