#include <iostream>

class Graph {
	int** _grid;
	int size, origin_at;

	void _read_values() {
		for (int y = 0; y < size; y++)
			for (int x = 0; x < size; x++)
				std::cin >> _grid[y][x];
	}

	int _map_x(int coordinate) const {
		return origin_at + coordinate;
	}
	int _map_y(int coordinate) const {
		return origin_at - coordinate;
	}
public:
	Graph(size_t size) {
		this->size = size;

		// Indexing start at 0;
		this->origin_at = (size / 2);

		// std::cout << origin_at << " origin: \n";

		_grid = new int*[size];
		for (int i = 0; i < size; i++)
			_grid[i] = new int[size];

		// Fill the grid
		_read_values();
	}

	void value_at(int y, int x) const {
		int mapped_y = _map_y(y);
		int mapped_x = _map_x(x);

		if (mapped_y >= size or mapped_y < 0 or
		        mapped_x >= size or mapped_x < 0)
			std::cout << "INVALID INPUT\n";
		else
			std::cout << _grid[mapped_y][mapped_x] << '\n';
	}

	~Graph() {
		for (int i = 0; i < size; i++) {
			delete[] _grid[i];
			_grid[i] = NULL;
		}

		delete _grid;
		_grid = NULL;
		size = origin_at = 0;
	}


};

int main() {
	long long size; std::cin >> size;
	Graph graph(size);
	long long queries; std::cin >> queries;
	int y, x;
	while (queries--) {
		std::cin >> x >> y;
		graph.value_at(y, x);
	}
	return 0;
}