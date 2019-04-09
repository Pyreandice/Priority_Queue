#include <iostream>
#include <string>

#include "min_heap.h"
#include "priority_queue.h"

int main()
{
	boot::priority_queue<int> priority_queue;

	for (auto index = 99; index >= 0; index--)
	{
		priority_queue.offer(index);
	}
	priority_queue.print();

	std::cout << priority_queue.peek() << std::endl;

	priority_queue.poll();

	priority_queue.clear();

	return 0;
}
