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
		class NoNumbersInTheList : public std::exception{
			virtual const char* what() const throw();
		};
		class OneNumberOnTheList : public std::exception{
			virtual const char* what() const throw();
		};

		void addNumber(unsigned int N);
		int shortestSpan();
		int longestSpan();

		void addNumber(std::list<unsigned int>::iterator begin, std::list<unsigned int>::iterator end);

	private:
		unsigned int _maxSize;
		std::list<unsigned int> listElements;
};



#endif
