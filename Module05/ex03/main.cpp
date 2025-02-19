#include "inc/Bureaucrat.hpp"
#include "inc/AForm.hpp"
#include "inc/ShrubberyCreationForm.hpp"
#include "inc/RobotomyRequestForm.hpp"
#include "inc/PresidentialPardonForm.hpp"
#include "inc/Intern.hpp"

int main()
{
	Intern someRandomIntern;
	
	AForm *form1 = someRandomIntern.makeForm("shrubbery creation", "Bender");
	AForm *form2 = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm *form3 = someRandomIntern.makeForm("presidential pardon", "Bender");
	AForm *form4 = someRandomIntern.makeForm("random", "Bender");

	Bureaucrat b1("Bender", 1);

	if (form1){
		b1.signForm(*form1);
		b1.executeForm(*form1);
		delete form1;
	}
	if (form2){
		b1.signForm(*form2);
		b1.executeForm(*form2);
		delete form2;
	}
	if (form3){
		b1.signForm(*form3);
		b1.executeForm(*form3);
		delete form3;
	}
	if (form4){
		delete form4;
	}

	return (0);
}