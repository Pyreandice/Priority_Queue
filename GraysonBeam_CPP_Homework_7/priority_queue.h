#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <queue>

#include "min_heap.h"

namespace boot
{
	template <typename E>
	class priority_queue
	{
	public:
		/**
		 * Public facing method for the peek_object_at_location
		 * method. This will call the peek_object_at_location method to return the
		 * data at the passed location in the heap.
		 * @param location the current location in the heap.
		 */
		E peek()
		{
			return peek_object_at_location();
		}

		/***
		 * Public facing method for the poll_object method.
		 * This will call the poll_object method to return and delete the
		 * data at the first position in the heap.
		 */
		void poll()
		{
			poll_object();
		}

		/***
		 * Public facing method for the return_size method.
		 * This will call the return_size method to return the current size
		 * of the heap.
		 */
		int size() const
		{
			return return_size();
		}

		/***
		 * Public facing method for the clear_heap method.
		 * This will call the clear_heap method to set all of the
		 * positions in the data equal to NULL.
		 */
		void clear()
		{
			clear_heap();
		}

		static void offer(E & value)
		{
			offer_values();
		}

		friend class max_heap;

	private:
		/***
		* Instantiate an instance of the max_heap class.
		*/
		nwacc::max_heap<int> max_heap;

		/***
		 * Variable to keep track of the size of the max_heap class.
		 */
		int heap_size = max_heap.pass_size();

		/***
		 * Determine if the heap is empty or not by checking to see if its
		 * size is equal to zero.
		 */
		bool is_empty() const
		{
			return this->size() == 0;
		}

		/**
		 * Private facing method for the peek method, will check
		 * to see if the current location is empty or if the stack is empty.
		 * If it is empty, throw an out of range exception.
		 * Else it is not empty, return the data at the specified location in the heap.
		 * @param location the current location in the heap.
		 */
		E peek_object_at_location()
		{
			if (this->is_empty())
			{
				throw std::out_of_range("Heap is empty");
			}
			else
			{
				return this->max_heap.get_max();
			}
		}

		/***
		 * Private facing method for the poll method, will
		 * return the first object in the heap and delete it.
		 * If there is not object in the first position then throw a range exception.
		 * Else there is an object to be returned.
		 */
		void poll_object()
		{
			if (this->is_empty())
			{
				throw std::out_of_range("Null head position...");
			}
			else
			{
				std::cout << this->max_heap.get_max() << std::endl;
				this->max_heap.remove(); // TODO: make sure this line does not break everything
			}
		}

		/***
		 * Private facing method for the size method,
		 * will return the size of the heap as long as it is
		 * not empty.
		 */
		int return_size() const
		{
			if (this->is_empty())
			{
				throw std::out_of_range("Heap is empty");
			}
			else
			{
				return max_heap.pass_size();
			}
		}

		/***
		 * Private facing method for the clear method which clears
		 * all of the data in the heap.
		 */
		void clear_heap()
		{
			while (!this->max_heap.is_empty())
			{
				this->max_heap.remove();
			}

			std::cout << "Heap is now empty... Printing new size... " << size() << std::endl;
		}

		static void offer_values(E & value)
		{
			E rhs = value;
		}
	};
}

#endif // PRIORITY_QUEUE_H_