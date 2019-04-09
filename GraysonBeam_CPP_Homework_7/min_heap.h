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
		max_heap(int capacity = kDefaultSize) : array(capacity + 1), heap_size{ 0 } {}

		static const int kDefaultSize = 99;

		bool is_empty() const
		{
			return this->heap_size == 0;
		}

		const E & get_max() const
		{
			if (this->is_empty())
			{
				throw std::out_of_range("Heap is empty");
			}
			else
			{
				return this->array[0];
			}
		}

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

		void remove()
		{
			if (this->is_empty())
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
			return heap_size;
		}

	private:
		std::vector<E> array;

		int heap_size;

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
