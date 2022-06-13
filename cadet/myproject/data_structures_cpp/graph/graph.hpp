#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

/*
 * GRAPH CLASS
 * @author	: Sungjun Park
 * @mail	: khsj15@naver.com
 * DESCRIPTION
 * Array based Graph Data structure
*/
#include <string.h> // memset
#include <iostream> // cout
#include <stack> // DFS
#include <queue> // BFS

class EMPTY_GRAPH{};
class FULL_GRAPH{};

template<class ItemType>
class graph
{
private:
	ItemType *vertices; // Vertex ARRAY (NAME OR IDX.. etc..)
	int *visitedVertex; // Using for search Vertex
	int **edges; // Edge Weight Array (2D)
	int numberOfVertices; // Current Number of Vertices (Stored)
	int maxNumberOfVertices; // Maximum Number of Vertices
	int getIdxOfVertex(const ItemType vertex) const;
	void resetVisitPlace();
public:
	graph();
	graph(int maxSize);
	~graph();
	bool isFull() const;
	bool isEmpty() const;
	void addVertex(const ItemType vertex);
	void addEdge(const ItemType fromVertex, const ItemType toVertex, const int weight);
	void deleteVertex(const ItemType vertex);
	void deleteEdge(const ItemType fromVertex, const ItemType toVertex);
	int getWeightOfEdge(const ItemType fromVertex, const ItemType toVertex) const;
	void printGrpahDFS();
	void printGraphBFS();
};

template<class ItemType>
int graph<ItemType>::getIdxOfVertex(const ItemType vertex) const
{
	for (int i = 0; i < numberOfVertices; ++i)
	{
		if (vertex == vertices[i])
			return (i);
	}
	return (-1);
}

static void initzero(int *arr, unsigned int size)
{
	for (unsigned int i = 0; i < size; ++i)
	{
		arr[i] = 0;
	}
}

template<class ItemType>
graph<ItemType>::graph()
{
	const int MAX_SIZE = 50;
	(this->maxNumberOfVertices) = MAX_SIZE;
	(this->vertices) = new ItemType [maxNumberOfVertices];
	(this->edges) = new int* [maxNumberOfVertices];
	(this->visitedVertex) = new int [maxNumberOfVertices];
	(this->numberOfVertices) = 0;
	// init
	initzero(this->visitedVertex, maxNumberOfVertices);
	for (int i = 0; i < maxNumberOfVertices; ++i)
	{
		(this->edges)[i] = new int [maxNumberOfVertices];
	}
	for (int i = 0; i < maxNumberOfVertices; ++i)
	{
		initzero((this->edges)[i], maxNumberOfVertices);
	}
}

template<class ItemType>
graph<ItemType>::graph(int maxSize)
{
	(this->maxNumberOfVertices) = maxSize;
	(this->vertices) = new ItemType [maxNumberOfVertices];
	(this->edges) = new int* [maxNumberOfVertices];
	(this->visitedVertex) = new int [maxNumberOfVertices];
	(this->numberOfVertices) = 0;
	// init
	initzero(this->visitedVertex, maxNumberOfVertices);
	for (int i = 0; i < maxNumberOfVertices; ++i)
	{
		(this->edges)[i] = new int [maxNumberOfVertices];
	}
	for (int i = 0; i < maxNumberOfVertices; ++i)
	{
		initzero((this->edges)[i], maxNumberOfVertices);
	}
}


template<class ItemType>
graph<ItemType>::~graph()
{
	delete [] (this->vertices);
	for (int i = 0; i < maxNumberOfVertices; ++i)
	{
		delete [] (this->edges)[i];
	}
	delete [] (this->edges);
	delete [] (this->visitedVertex);
}

template<class ItemType>
bool graph<ItemType>::isFull() const
{
	return ((this->maxNumberOfVertices) <= (this->numberOfVertices));
}

template<class ItemType>
bool graph<ItemType>::isEmpty() const
{
	return (this->numberOfVertices == 0);
}

template<class ItemType>
void graph<ItemType>::addVertex(const ItemType vertex)
{
	if (this->isFull())
		throw (FULL_GRAPH());
	const int idxOfVertex = (this->numberOfVertices)++;
	(this->vertices)[idxOfVertex] = vertex;
}

template<class ItemType>
void graph<ItemType>::addEdge(const ItemType fromVertex, const ItemType toVertex, const int weight)
{
	const int idxOfFromVertex = getIdxOfVertex(fromVertex);
	const int idxOfToVertex = getIdxOfVertex(toVertex);
	if (idxOfFromVertex < 0 || idxOfToVertex < 0)
		return ;
	int &edge = (this->edges)[idxOfFromVertex][idxOfToVertex];
	edge = weight;
}

template<class ItemType>
void graph<ItemType>::deleteVertex(const ItemType vertex)
{
	const int idxOfVertex = getIdxOfVertex(vertex);
	if (idxOfVertex < 0)
		return ;
	--(this->numberOfVertices);
	// to zero edges
	for (int row = 0; row < maxNumberOfVertices; ++row)
	{
		edges[row][idxOfVertex] = 0;
	}
	for (int col = 0; col < maxNumberOfVertices; ++col)
	{
		edges[idxOfVertex][col] = 0;
	}
}

template<class ItemType>
void graph<ItemType>::deleteEdge(const ItemType fromVertex, const ItemType toVertex)
{
	const int idxOfFromVertex = getIdxOfVertex(fromVertex);
	const int idxOfToVertex = getIdxOfVertex(toVertex);
	if (idxOfFromVertex < 0 || idxOfToVertex < 0)
		return ;
	edges[idxOfFromVertex][idxOfToVertex] = 0;
}

template<class ItemType>
int graph<ItemType>::getWeightOfEdge(const ItemType fromVertex, const ItemType toVertex) const
{
	const int idxOfFromVertex = getIdxOfVertex(fromVertex);
	const int idxOfToVertex = getIdxOfVertex(toVertex);
	if (idxOfFromVertex < 0 || idxOfToVertex < 0)
		throw (EMPTY_GRAPH()); // 적절한 에러가 필요하다...
	return (edges[idxOfFromVertex][idxOfToVertex]);
}

template<class ItemType>
void graph<ItemType>::resetVisitPlace()
{
	initzero((this->visitedVertex), numberOfVertices);
}

template<class ItemType>
void graph<ItemType>::printGrpahDFS()
{
	if (this->isEmpty())
		return ;
	resetVisitPlace();
	std::stack<int> pathStack;
	pathStack.push(0); // ROOT
	while (!pathStack.empty())
	{
		const int fromVtx = pathStack.top();
		pathStack.pop();
		if (visitedVertex[fromVtx])
			continue;
		else
			visitedVertex[fromVtx] = true;
		// print current path and weight
		std::cout << vertices[fromVtx] << '\n';
		// traverse tree
		for (int toVtx = 0; toVtx < numberOfVertices; ++toVtx)
		{
			if (edges[fromVtx][toVtx])
			{
				pathStack.push(toVtx);
			}
		}
	}
}

template<class ItemType>
void graph<ItemType>::printGraphBFS()
{
	if (this->isEmpty())
		return ;
	resetVisitPlace();
	std::queue<int> pathQue;
	pathQue.push(0); // ROOT
	while (!pathQue.empty())
	{
		const int fromVtx = pathQue.front();
		pathQue.pop();
		if (visitedVertex[fromVtx])
			continue;
		else
			visitedVertex[fromVtx] = true;
		// print current path and weight
		std::cout << vertices[fromVtx] << '\n';
		// traverse tree
		for (int toVtx = 0; toVtx < numberOfVertices; ++toVtx)
		{
			if (edges[fromVtx][toVtx])
			{
				pathQue.push(toVtx);
			}
		}
	}
}


#endif
