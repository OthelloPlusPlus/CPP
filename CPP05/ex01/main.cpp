#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "print.hpp"
#include "colors.hpp"

#include <string>
// std::string
#include <iostream>
// std::cout

static void	testForm(Bureaucrat &bc, std::string name, int signGrade, int execGrade);

int	main(void)
{
	print::headerLine("Exercise 01: Form up, maggots!");
	Bureaucrat	bc("Hermes", 37);

	testForm(bc, "1a Requisition to be evaluated", 11, 11);
	testForm(bc, "555b Requisition to appropriate peoples bank accounts", 151, 151);
	testForm(bc, "23c Requisition to use the toilet", 150, 150);
	testForm(bc, "79168d Requisition to pass the evaluation", 36, 38);
	return (0);
}

static void	testForm(Bureaucrat &bc, std::string name, int signGrade, int execGrade)
{
	print::subHeaderLine("Testing Form " + name);
	try
	{
		Form	form(name, signGrade, execGrade);
		std::cout	<<	form	<< "\n\n";
		bc.signForm(form);
		std::cout	<<	form	<< "\n\n";
		bc.signForm(form);
		std::cout	<< '\n';
		form.printForm();
	}
	catch(const std::exception& e)
	{
		std::cerr	<< C_LRED	<< e.what()
					<< C_RESET	<< std::endl;;
	}
	std::cout	<< std::endl;
}
