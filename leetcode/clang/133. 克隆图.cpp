#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Node {
	int val; //ж╣
	int numNeighbors; //аз╬с
	struct Node** neighbors;
};

#define NODE_COUNT 101
struct Node *vector[NODE_COUNT] = {0};

struct Node* dfs(struct Node *s)
{
    if (s == NULL) {
		return NULL;
	}
    if (vector[s->val]) {
		return vector[s->val];
	}
    struct Node* n = (struct Node*)calloc(sizeof(struct Node), 1);
    n->val = s->val;
    n->numNeighbors = s->numNeighbors;
    n->neighbors = (struct Node**)calloc(sizeof(struct Node*), s->numNeighbors);
    vector[s->val] = n;
    for(int i = 0; i < s->numNeighbors; i++) {
        n->neighbors[i] = dfs(s->neighbors[i]);
    }
    return n;
}

struct Node *cloneGraph(struct Node *s) 
{
	if (s == NULL) {
		return NULL;
	}
	memset(vector, 0, sizeof(vector));
    return dfs(s);
}

struct Node *createGraph(int *a[2], int n)
{
	if (a == NULL || n == 0) {
	    return NULL;
    } 
    struct Node *nodeList = (struct Node *)malloc(sizeof(struct Node) * n);
    if (nodeList == NULL) {
        return NULL;
    }

}

void createGraph(struct Node *g)
{
	if (g == NULL) {
	    return NULL;
    }

}

int main()
{
	int *a[2] = {{2,4},{1,3},{2,4},{1,3}};
	int n = sizeof(a) / sizeof(a[0]);
	struct Node *g = createGraph(a, n);
	struct Node *g2 = cloneGraph(g);
	visitGraph(g);
	freeGraph(g);
	freeGraph(g2);
	return 0;
}

