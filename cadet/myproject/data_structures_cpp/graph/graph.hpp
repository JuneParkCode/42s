#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

/*
 * GRAPH CLASS
 * @author	: Sungjun Park
 * @mail	: khsj15@naver.com
 * DESCRIPTION
 * Array based Graph Data structure
*/
#include <string.h>
#include <stack>
#include <queue>

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
	void searchGraphDFS(void *f()) const;
	void printGrpahDFS() const;
	void searchGraphBFS(void *f()) const;
	void printGraphBFS() const;
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

template<class ItemType>
static void bzero(ItemType *arr, unsigned int size)
{
	for (int i = 0; i < size; ++i)
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
	(this->edges) = new int [maxNumberOfVertices][maxNumberOfVertices];
	(this->visitedVertex) = new int [maxNumberOfVertices];
	(this->numberOfVertices) = 0;
	// init
	bzero(this->vertices, maxNumberOfVertices);
	bzero(this->visitedVertex, maxNumberOfVertices);
	for (int i = 0; i < maxNumberOfVertices; ++i)
		bzero((this->edges)[i], maxNumberOfVertices);
}

template<class ItemType>
graph<ItemType>::graph(int maxSize)
{
	(this->maxNumberOfVertices) = maxSize;
	(this->vertices) = new ItemType [maxNumberOfVertices];
	(this->edges) = new int [maxNumberOfVertices][maxNumberOfVertices];
	(this->visitedVertex) = new int [maxNumberOfVertices];
	(this->numberOfVertices) = 0;
	// init
	bzero(this->vertices, maxNumberOfVertices);
	bzero(this->visitedVertex, maxNumberOfVertices);
	for (int i = 0; i < maxNumberOfVertices; ++i)
		bzero((this->edges)[i], maxNumberOfVertices);
}


template<class ItemType>
graph<ItemType>::~graph()
{
	delete [] (this->vertices);
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
	const int &edge = (this->edges)[idxOfFromVertex][idxOfToVertex];
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
	bzero((this->visitedVertex), numberOfVertices, 0);
}

template<class ItemType>
void graph<ItemType>::searchGraphDFS(void *f()) const
{

}

template<class ItemType>
void graph<ItemType>::printGrpahDFS() const
{

}

template<class ItemType>
void graph<ItemType>::searchGraphBFS(void *f()) const
{

}

template<class ItemType>
void graph<ItemType>::printGraphBFS() const
{

}


#endif
