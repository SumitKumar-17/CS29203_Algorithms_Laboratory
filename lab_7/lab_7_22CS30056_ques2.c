#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node
{
    int course;
    struct node *next;
} Node;
typedef struct graph
{
    int numCourses;
    Node **adjList;
    int *inDegree;
} Graph;
void addEdge(Graph *graph, int u, int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->course = v;
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;
    graph->inDegree[v]++;
}
int topologicalSort(Graph *graph, int *result)
{
    int i = 0;
    int index = 0;
    int queue[graph->numCourses];
    int front = 0, rear = 0;
    for (i = 0; i < graph->numCourses; i++)
    {
        if (graph->inDegree[i] == 0)
        {
            queue[rear++] = i;
        }
    }
    while (front < rear)
    {
        int course = queue[front++];
        result[index++] = course;
        Node *neighbor = graph->adjList[course];
        while (neighbor != NULL)
        {
            int adjCourse = neighbor->course;
            graph->inDegree[adjCourse]--;
            if (graph->inDegree[adjCourse] == 0)
            {
                queue[rear++] = adjCourse;
            }
            neighbor = neighbor->next;
        }
    }

    return index;
}
bool canFinishAllCourses(int numCourses, int prereq[][2], int prereqSize)
{
    int i = 0;
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numCourses = numCourses;
    graph->adjList = (Node **)malloc(numCourses * sizeof(Node *));
    graph->inDegree = (int *)malloc(numCourses * sizeof(int));
    for (i = 0; i < numCourses; i++)
    {
        graph->adjList[i] = NULL;
        graph->inDegree[i] = 0;
    }
    for (i = 0; i < prereqSize; i++)
    {
        addEdge(graph, prereq[i][0], prereq[i][1]);
    }
    int result[numCourses];
    int index = topologicalSort(graph, result);
    if (index != numCourses)
    {
        return false;
    }
    return true;
}
int main()
{   int i=0;
    int numCourses;
    printf("Enter the number of course:");
    scanf("%d", &numCourses);

    printf("enter the number of values for the prequisite array:");
    int p;
    scanf("%d",&p);

    printf("enter the prequisites array:");
    int prereq[p][2];

    for (i = 0; i < p; i++)
    {
        scanf("%d %d", &prereq[i][0], &prereq[i][1]);
    }

    int prereqSize = sizeof(prereq) / sizeof(prereq[0]);

    bool canFinish = canFinishAllCourses(numCourses, prereq, prereqSize);
    if (canFinish)
    {
        printf("Can finish all courses: true\n");
    }

    else
    {
        printf("Can finish all courses: false\n");
    }

    return 0;
}