#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <exception>
#include <string>

template<typename T>
class	Array
{
	public:

		Array():arr(NULL), len(0) {}
		Array(unsigned int len)
		{
			this->len = len;
			this->arr = new T[len]();
		}
		Array(const Array<T> &orig)
		{
			this->len = orig.len;
			this->arr = new T[orig.len]();
			for (int i = 0; i < orig.len; i++)
				this->arr = orig.arr[i];
		}
		~Array(void)
		{
			delete [] this->arr;
		}
		Array	&operator=(const T &orig)
		{
			this->len = orig.len;
			delete []this->arr;
			this->arr = new T[len]();
			for (int i = 0; i < orig.len; i++)
				this->arr = orig.arr[i];
			return (*this);
		}
		T	&operator[](size_t i)
		{
			if (i >= this->len)
				throw std::out_of_range("Index " + std::to_string(i) +
						" is not less then len(" + std::to_string(this->len) + ")");
			return (this->arr[i]);
		}
		size_t	size(void) const
		{
			return (this->len);
		}

	private:

		T		*arr;
		size_t	len;
};

#endif
