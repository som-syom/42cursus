#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string _target;
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(std::string const&);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const&);
		PresidentialPardonForm& operator=(PresidentialPardonForm const&);

		void execute(Bureaucrat const& executor) const;
};

#endif
