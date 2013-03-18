#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

template <class T>
class DirectedGraph {

	struct Node {
		T data;
		std::set<int> neighbors;
	};

	std::map< int, Node * > nodes;
	int nodeId;

public:
	DirectedGraph() {
		this->nodeId = 0;
	}

	int createNode(T data) {
		Node *node = new Node;
		node->data = data;
		nodes.insert( std::pair<int, Node *>(nodeId, node) );
		return nodeId++;
	}

	bool add(int node1, int node2) {
		if (nodes.count(node1) == 0 || nodes.count(node2) == 0) {
			return false;
		}
		Node *node = nodes[node1];
		node->neighbors.insert(node2);
		return true;
	}

	bool isNeighbor(int node1, int node2) {
		if (nodes.count(node1) == 0 || nodes.count(node2) == 0) {
			return false;
		}
		return nodes[node1]->neighbors.count(node2) > 0;
	}

	/*
		Checks if a path exists from node1 and node2

		This method uses a BFS (Breadth First Search) and makes use of a queue to do so
	*/
	bool isPath(int node1, int node2) {
		if (nodes.count(node1) == 0 || nodes.count(node2) == 0) {
			return false;
		}
		if (node1 == node2) {
			return true;
		}
		std::queue<int> unvisited;
		std::set<int> visited;
		unvisited.push(node1);
		while (!unvisited.empty()) {
			int currentId = unvisited.front();
			std::cout << "Current ID: " << currentId << std::endl;
			Node *current = nodes[currentId];
			std::set<int> neighbors = current->neighbors;
			std::set<int>::iterator it;
			std::cout << "Number of neighbors: " << neighbors.size() << std::endl;
			for (it = neighbors.begin(); it != neighbors.end(); it++) {
				std::cout << "Neighbor ID: " << *it << std::endl;
				if (nodes[*it] == nodes[node2]) {
					return true;
				} else if (visited.count(*it) == 0) {
					unvisited.push(*it);
				}
			}
			visited.insert(currentId);
			unvisited.pop();
		}
		return false;
	}

};

/*
	Debugging/Testing
*/
int main(int argc, char *argv[]) {
	DirectedGraph<int> graph;
	int node1 = graph.createNode(3);
	int node2 = graph.createNode(6);
	int node3 = graph.createNode(4);
	int node4 = graph.createNode(2);
	graph.add(node1, node2);
	graph.add(node4, node2);
	graph.add(node2, node3);
	//true
	std::cout << graph.isPath(node1, node2) << std::endl;
	//true
	std::cout << graph.isPath(node1, node3) << std::endl;
	//false
	std::cout << graph.isPath(node3, node1) << std::endl;
	return 0;
}