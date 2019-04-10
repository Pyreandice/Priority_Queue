#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <queue>

#include "min_heap.h"
#include "priority_queue.h"

int main()
{
	boot::priority_queue<int> priority_queue;

	for (auto index = 99; index >= 0; index--)
	{
		priority_queue.offer(index);
	}

	std::cout << priority_queue.peek() << std::endl;

	while (!priority_queue.is_empty())
	{
		priority_queue.poll();
	}

	priority_queue.clear();

	return 0;
}
