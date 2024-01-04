#include <iostream>
#include <queue>
using namespace std;

class Graph{
    int size;
    typedef struct Node
    {
        int dst, cost;
        struct Node* next;
    } node;
    node** adjList;

    node* createNode(int val1, int val2){
        node* n = new node;
        n->dst = val1;
        n->cost = val2;
        n->next = NULL;
        return n;
    }
    bool present(int* arr, int n, int key){
        for (register int i=0; i<n; i++){
            if (key == arr[i])
                return true;
        }
        return false;
    }
    void explore(queue<int> &q, node* n){
        if (!n) return;
        while (n){
            q.push(n->dst);
            n = n->next;
        }
    }
public:
    Graph(int n=1){
        size = n;
        adjList = new node*[n];
    }
    void insert(int src, int dst, int cost=0){
        label:
        if (adjList[src]){
            node* n = adjList[src];
            while (n->next)
                n = n->next;
            n->next = createNode(dst,cost);
        }
        else{
            adjList[src] = createNode(src,0);
            goto label;
        }
    }
    void bfsTraversal(){
        int* visited = new int[size];
        register int i = 0, j = 0;
        queue<int> q;
        q.push(adjList[j]->dst);
        while (!q.empty()){
            if (!present(visited,i,q.front())){
                cout<<q.front()<<" ";
                visited[i++] = q.front();
            }
            if (j<size) explore(q,adjList[j++]);      
            q.pop();
        }
        cout<<endl;
        delete[] visited;
    }
};

int main()
{
    cout<<"Number of vertices : ";
    int n;
    cin>>n;
    Graph g(n);
    int src, dst, cost;
	bool weighted, enter;
    cout<<"Weighted? {0/1} : ";
    cin>>weighted;
	do{
        if (weighted){
            cout<<"source, destination, cost : ";
            cin>>src>>dst>>cost;
            g.insert(src,dst,cost);
        }
        else{
            cout<<"source, destination : ";
            cin>>src>>dst;
            g.insert(src,dst);
        }
		cout<<"Insert more linkages? {0/1} : ";
		cin>>enter;
	} while(enter);

    cout<<"Breadth first traversal\n";
    g.bfsTraversal();
    
    return 0;
}
