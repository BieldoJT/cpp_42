#ifndef SPAN_HPP

# define SPAN_HPP


class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		~Span();
	private:
		int *list; // trocar por constainer list - STL
};

#endif
