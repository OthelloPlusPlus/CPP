#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "print.hpp"
#include "colors.hpp"

#include <string>
// std::string
#include <iostream>
// std::cout

static void	testForm(Bureaucrat &signer, Bureaucrat &executor, AForm *form);

int	main(void)
{
	print::headerLine("Exercise 02: No, you need form 28B, not 28C...");
	Bureaucrat	numOne("Number 1.0", 1);
	Bureaucrat	hermes("Hermes", 37);
	Bureaucrat	morgan("Morgan Proctor", 19);
	Bureaucrat	farnsworth("Hubert J. Farnsworth", 150);

	testForm(farnsworth, hermes, new ShrubberyCreationForm("_in_front_of_my_car"));
	testForm(morgan, farnsworth, new ShrubberyCreationForm("_in_front_of_my_car"));
	testForm(morgan, hermes, new ShrubberyCreationForm("_in_front_of_my_car"));
	testForm(hermes, hermes, new RobotomyRequestForm("Bender"));
	testForm(hermes, hermes, new RobotomyRequestForm("Fry"));
	testForm(hermes, hermes, new RobotomyRequestForm("Leela"));
	testForm(numOne, numOne, new PresidentialPardonForm("Roberto"));

	return (0);
}

static void	testForm(Bureaucrat &signer, Bureaucrat &executor, AForm *form)
{
	print::subHeaderLine("Testing " + form->getName());
	// std::cout	<< C_LORANGE	<< signer	
	// 			<< C_RESET	<< " to sign the form: "
	// 			<< C_CYAN	<< form->getName()
	// 			<< C_RESET	<< std::endl;
	signer.signForm(*form);
	// std::cout	<< C_LORANGE	<< executor	
	// 			<< C_RESET	<< " to execute the form: "
	// 			<< C_CYAN	<< form->getName()
	// 			<< C_RESET	<< std::endl;
	executor.executeForm(*form);
	delete form;
	std::cout	<< std::endl;
}
