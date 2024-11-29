#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INT_MAX 1000000


//this is a  min function defined to find the minimum of two numbers
int min(int a ,int b){return (a>b)?a:b;}

//this is QueueNode data structure defined  for using 
typedef struct
{   // the vertex,depth,node parameters are defined for this data type


    int vertex;
    int depth;
    int cost;
} QueueNode;

//this is the graph data type defined for using 
typedef struct
{   
    //these paricular parameters are defined for this datatype
    int numVertices;
    int numEdges;
    int source;
    int destination;
    int n;
    int **graph;
} Graph;

// this is a function which creates a new Queue Node and then return it 
QueueNode *newNode(int vertex, int depth, int cost)
{   
    //this function creates a new pointer of the Queue Datatype
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    node->vertex = vertex;
    node->depth = depth;
    node->cost = cost;
    return node;
}

//this is a create graph function which creates a graph
Graph *createGraph(int numVertices, int numEdges)
{
    int i = 0;
    int j = 0;
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = numEdges;
    graph->graph = (int **)malloc(numVertices * sizeof(int *));
    for (i = 0; i < numVertices; i++)
    {
        graph->graph[i] = (int *)malloc(numVertices * sizeof(int));
        for (j = 0; j < numVertices; j++)
        {
            graph->graph[i][j] = INT_MAX;
        }
    }
    return graph;
}

//this function adds a new edge to the graph when it is called 
// it takes the pointer of graph ,source and destination values ,weight and then adds accordingly
void addEdge(Graph *graph, int source, int destination, int weight)
{   

    //adding the edge in the graph as per the source and destination
    graph->graph[source][destination] = weight;
}

//this is min cost function which calculates the minimumm cost of the graph
int minCostPath(Graph *graph, int source, int destination, int n)
{
    int i = 0;
    int j = 0;
    int minCost = INT_MAX;

    //creating a  2D array for storing the visited edges
    int **visited = (int **)malloc(graph->numVertices * sizeof(int *));
    for (i = 0; i < graph->numVertices; i++)
    {
        visited[i] = (int *)malloc(n + 1 * sizeof(int));
        for (j = 0; j <= n; j++)
        {
            visited[i][j] = 0;
        }
    }

    //initialize a new pointere queue
    QueueNode *queue = (QueueNode *)malloc(sizeof(QueueNode));
    queue->vertex = source;
    queue->depth = 0;
    queue->cost = 0;

    //findinng the cost
    while (queue != NULL)
    {
        QueueNode *currentNode = queue;
        minCost= queue->depth;
        if (visited[currentNode->vertex][currentNode->depth] == 1)
        {
            continue;
        }
        visited[currentNode->vertex][currentNode->depth] = 1;
        if (currentNode->vertex == destination && currentNode->depth == n)
        {
            minCost = min(minCost, currentNode->cost);
            continue;
        }
        for (i = 0; i < graph->numVertices; i++)
        {
            if (graph->graph[currentNode->vertex][i] != INT_MAX)
            {
                int newDepth = currentNode->depth + 1;
                if (newDepth <= n)
                {
                    int newCost = currentNode->cost + graph->graph[currentNode->vertex][i];
                    QueueNode *newNode1 = newNode(i, newDepth, newCost);
                    newNode1->depth = queue->depth;
                    queue = newNode1;
                }
            }
        }
        free(currentNode);
    }

    
    for (i = 0; i < graph->numVertices; i++)
    {
        free(visited[i]);
    }
    free(visited);
    return minCost;
}


int main()
{   

    //this is the source,destination etc data for the graph
    int numVertices = 8;
    int numEdges = 14;
    int source = 0;
    int destination = 3;
    int n = 4;

    //creating the graph by hardcoding the values of the inputs
    Graph *graph = createGraph(numVertices, numEdges);

    ///adding all the edges in the graph
    addEdge(graph, 0, 6, -1);
    addEdge(graph, 0, 1, 5);
    addEdge(graph, 1, 6, 3);
    addEdge(graph, 1, 5, 5);
    addEdge(graph, 1, 2, 7);
    addEdge(graph, 2, 3, 8);
    addEdge(graph, 3, 4, 10);
    addEdge(graph, 5, 2, -1);
    addEdge(graph, 5, 3, 9);
    addEdge(graph, 5, 4, 1);
    addEdge(graph, 6, 5, 2);
    addEdge(graph, 7, 6, 9);
    addEdge(graph, 7, 1, 6);


    //calling the minCost function and printing the answer
    int k=minCostPath(graph, source, destination, n);
    printf("the minimum cost of the path is:%d",k);


}