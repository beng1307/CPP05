#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class	Bureaucrat
{
	private:

		const std::string	name;
		unsigned int		grade;

	public:

		Bureaucrat();
		Bureaucrat(const std::string name, unsigned int grade);
		~Bureaucrat();

		class	GradeTooLowException: public std::exception
		{
			public:
		
				virtual const char *what() const throw();
		};
		
		class	GradeTooHighException: public std::exception
		{
			public:
		
				virtual const char *what() const throw();
		};

		
		void	increment_grade();
		void	decrement_grade();
		
		const std::string	getName() const;
		unsigned int		getGrade() const;
	};
	
	std::ostream	&operator<<(std::ostream &outputstream, const Bureaucrat &bureaucrat);
	
#endif