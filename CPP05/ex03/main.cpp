#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "print.hpp"
#include "colors.hpp"

#include <string>
// std::string
#include <iostream>
// std::cout

static void	testIntern(Intern &intern, Bureaucrat &bc, std::string name, std::string target);

int	main(void)
{
	print::headerLine("Exercise 02: No, you need form 28B, not 28C...");
	Bureaucrat	hermes("Hermes", 37);
	Intern		intern;

	testIntern(intern, hermes, "", "Fry");
	testIntern(intern, hermes, " ", "Fry");
	testIntern(intern, hermes, " form", "Fry");
	testIntern(intern, hermes, "forms", "Fry");
	testIntern(intern, hermes, "intern replacement form", "Fry");
	testIntern(intern, hermes, "SHRUBBERYCREATIONFORM", "_in_front_of_my_car");
	testIntern(intern, hermes, "robotomy request", "Bender");
	testIntern(intern, hermes, " Pre Si Den Tial Par Don Form ", "Roberto");
	return (0);
}

static void	testIntern(Intern &intern, Bureaucrat &bc, std::string name, std::string target)
{
	AForm	*form;

	print::subHeaderLine("Requesting '" + name + "' for: " + target);
	form = intern.makeForm(name, target);
	if (form)
	{
		bc.signForm(*form);
		bc.executeForm(*form);
		delete form;
	}
	std::cout	<< std::endl;
}
