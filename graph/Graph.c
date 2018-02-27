/*
 * Graph.c
 *
 *  Created on: 2018. 2. 27.
 *      Author: user
 */


#include "Graph.h"

Graph* createGraph() {
	Graph* graph = (Graph*) malloc(sizeof(Graph));
	graph->vertices = NULL;
	graph->vertexCount = 0;

	return graph;
}

void destroyGraph(Graph* graph) {
	while (graph->vertices != NULL) {
		Vertex* vertices = graph->vertices->next;
		destroyVertex(graph->vertices);
		graph->vertices = vertices;
	}

	free(graph);
}

Vertex* createVertex(ElementType data) {
	Vertex* vertex = (Vertex*) malloc(sizeof(Vertex));
	vertex->data = data;
	vertex->next = NULL;
	vertex->adjacencyList = NULL;
	vertex->visited = NotVisited;
	vertex->index = -1;

	return vertex;
}

void destroyVertex(Vertex* vertex) {
	while (vertex->adjacencyList != NULL) {
		Edge* edge = vertex->adjacencyList->next;
		destroyEdge(vertex->adjacencyList);
		vertex->adjacencyList = edge;
	}

	free(vertex);
}

Edge* createEdge(Vertex* from, Vertex* target, int weight) {
	Edge* edge = (Edge*) malloc(sizeof(Edge));
	edge->from = from;
	edge->target = target;
	edge->next = NULL;
	edge->weight = weight;

	return edge;
}

void destroyEdge(Edge* edge) {
	free(edge);
}

void addVertex(Graph* graph, Vertex* vertex) {
	Vertex* vertexList = graph->vertices;

	if (vertexList == NULL) {
		graph->vertices = vertex;
	} else {
		while (vertexList->next != NULL) {
			vertexList = vertexList->next;
		}

		vertexList->next = vertex;
	}

	vertex->index = graph->vertexCount++;
}

void addEdge(Vertex* vertex, Edge* edge) {
	if (vertex->adjacencyList == NULL) {
		vertex->adjacencyList = edge;
	} else {
		Edge* adjacencyList = vertex->adjacencyList;

		while (adjacencyList->next != NULL) {
			adjacencyList = adjacencyList->next;
		}

		adjacencyList->next = edge;
	}
}

void printGraph(Graph* graph) {
	Vertex* vertex = NULL;
	Edge* edge = NULL;

	if ((vertex = graph->vertices) == NULL) {
		return;
	}

	while (vertex != NULL) {
		printf("%c : ", vertex->data);

		if ((edge = vertex->adjacencyList) == NULL) {
			vertex = vertex->next;
			printf("\n");
			continue;
		}

		while (edge != NULL) {
			printf("%c[%d] ", edge->target->data, edge->weight);
			edge = edge->next;
		}

		printf("\n");

		vertex = vertex->next;
	}

	printf("\n");
}
