#ifndef MIN_HEAP_H_
#define MIN_HEAP_H_

#include <iostream>
#include <stdexcept>
#include <vector>
#include <queue>

namespace nwacc
{
	template <typename E>
	class max_heap
	{
	public:
		/***
		 * Constructor for the max_heap class.
		 */
		max_heap(int capacity = kDefaultSize) : array(capacity + 1), heap_size{ 0 } {}

		/***
		 * Value to store the default size of the heap.
		 */
		static const int kDefaultSize = 99;

		/***
		 * Check to see if the heap is empty or not and return
		 * true if the heap is not empty and
		 * false if the heap is empty.
		 */
		bool is_empty() const
		{
			return this->heap_size == 0;
		}

		/***
		 * Get the most important item in the heap. Also known as the
		 * FIRST item in the heap or the last item inserted.
		 * @return the first item in the heap.
		 */
		const E & get_max() const
		{
			if (!this->is_empty())
			{
				return this->array[0];
			}
			else
			{
				throw std::out_of_range("Heap is empty");
			}
		}

		/***
		 * Insert a new value into the heap using move semantics.
		 * This insert method will make sure to use the 0 element of the heap
		 * by using the formula "hole - 1 / 2", and will insert until the heap no longer
		 * has any free locations or there are no more items to be inserted.
		 * @param x the value to be inserted.
		 */
		void insert(const E & x)
		{
			if (this->heap_size == this->array.size() - 1)
			{
				this->array.resize(this->array.size() * 2);
			}

			// Percolate up
			int hole = ++this->heap_size - 1;
			E copy = x;

			this->array[hole] = std::move(copy);
			for (; x < this->array[hole - 1 / 2]; hole /= 2)
			{
				if (hole > 0 && this->array[(hole - 1) / 2] < this->array[hole])
				{
					this->array[hole] = std::move(this->array[hole - 1 / 2]);
				}
			}
		}

		/***
		* Insert a new value into the heap using move semantics.
		* This insert method will make sure to use the 0 element of the heap
		* by using the formula "hole - 1 / 2", and will insert until the heap no longer
		* has any free locations or there are no more items to be inserted.
		* @param value the value to be inserted.
		*/
		void insert(E && value)
		{
			// we want to see if I have room. 
			if (this->heap_size == this->array.size() - 1)
			{
				this->array.resize(this->array.size() * 2);
			} // else, we have space, do_nothing();

			// Percolate up
			int hole = ++this->heap_size - 1;
			E copy = value;

			this->array[hole] = std::move(copy);
			for (; value < this->array[hole - 1 / 2]; hole /= 2)
			{
				if (hole > 0 && this->array[(hole - 1) / 2] < this->array[hole])
				{
					this->array[hole] = std::move(this->array[hole - 1 / 2]);
				}
			}
		}

		/***
		 * Remove the most important item inside the heap and
		 * percolate down the heap by one item to shift the
		 * "level of importance". In other words, shift all of the
		 * items in the heap to the left one space.
		 */
		void remove()
		{
			if (!this->is_empty())
			{
				throw std::out_of_range("Heap is empty");
			}
			else
			{
				this->array[0] = std::move(this->array[this->heap_size--]);
				this->percolate_down(1);
			}
		}

		/***
		 * Print the whole heap from front to back
		 * @param out the out parameter
		 */
		void print(std::ostream & out = std::cout)
		{
			auto index = 1;
			while (index <= this->heap_size)
			{
				out << this->array[index] << " ";
				index++;
			}
			out << std::endl;
		}

		/***
		 * Return the size of the heap to allow variable passing
		 * between classes.
		 */
		int pass_size() const
		{
			return this->array.size();
		}

	private:
		/***
		 * Initialize a new vector named array.
		 */
		std::vector<E> array;

		/***
		 * Value to keep track of the heap size.
		 */
		int heap_size{};

		/***
		 * Move down the heap looking for a new location to enter data
		 * and if no spot is found. Then the heap is full and we need to
		 * re-size the heap to fit the new data.
		 * @param spot the location for the data insertion.
		 */
		void percolate_down(int spot)
		{
			auto temp = std::move(this->array[spot]);
			auto child = 0;
			auto is_done = false;

			while (!is_done && spot * 2 <= this->heap_size)
			{
				child = spot * 2;
				if (child != this->heap_size && this->array[child + 1] < this->array[child])
				{
					child++;
				}

				if (this->array[child] < temp)
				{ // we found a place for data to be inserted
					this->array[spot] = std::move(this->array[child]);
					spot = child;
				}
				else
				{
					is_done = true;
				}
			}
			this->array[spot] = std::move(temp);
		}
	};

}

#endif // MIN_HEAP_H_
