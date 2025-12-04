#ifndef AFORM_HPP
#define	AFORM_HPP

#include <string>

class	Bureaucrat;

class	AForm
{
	private:

		const std::string	name;
		bool				is_signed;
		const unsigned		signing_grade;
		const unsigned		executing_grade;

		AForm();

	public:
		
		AForm(const std::string &name, unsigned signing_grade, unsigned executing_grade);
		AForm	&operator=(AForm &other);
		AForm(AForm &other);
		virtual	~AForm();

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

		class	NotSignedException: public std::exception
		{
			public:
		
				virtual const char *what() const throw();
		};

		void				beSigned(Bureaucrat &bureaucrat);
		void				execute(Bureaucrat const &executor) const;
		virtual	void		executeAction() const = 0;
		
		const std::string	get_name() const;
		bool				get_is_signed() const;
		unsigned			get_signing_grade() const;
		unsigned			get_executing_grade() const;
		
};
	
	std::ostream &operator<<(std::ostream &output, const AForm &form);

#endif