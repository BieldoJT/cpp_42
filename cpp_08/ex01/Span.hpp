#ifndef SPAN_HPP

# define SPAN_HPP

# include <list>
# include <exception>
# include <iostream>


class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &copy);
		Span &operator=(const Span &other);
		~Span();

		class LimitReached : public std::exception{
			virtual const char* what() const throw();
		};

		void addNumber(unsigned int N);

	private:
		unsigned int _maxSize;
		std::list<unsigned int> listElements;
};



#endif
