#include "Bureaucrat.hpp"
#include "print.hpp"
#include "colors.hpp"

#include <string>
// std::string
#include <iostream>
// std::cout

static void	runTest(std::string name, int grade);

int	main(void)
{
	print::headerLine("Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!");
	try
	{
		Bureaucrat	numOne("Number 1.0", 1);

		std::cout	<< C_GRAY	<< numOne
					<< C_RESET	<< ": Bring me the evaluation forms for the new Bureaucrats.\n"	
					<< C_RESET	<< std::endl;
		runTest("Bender Bending Rodríguez", 0);
		runTest("Morgan Proctor", 19);
		runTest("Hermes Conrad", 36);
		runTest("Hubert J. Farnsworth", 150);
		runTest("Philip J. Fry", 1025);
		std::cout	<< C_GRAY	<< numOne
					<< C_RESET	<< ": Guards! Bring me the forms I need to fill out to have them taken away!"
					<< C_RESET	<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr	<< C_LRED	<< e.what()
					<< C_RESET	<< std::endl;;
	}
	return (0);
}

static void	runTest(std::string name, int grade)
{
	print::subHeaderLine(name + ", Grade " + std::to_string(grade));
	try
	{
		Bureaucrat	bc(name, grade);
		std::cout	<< C_GRAY	<< bc
					<< C_RESET	<< " is requesting the forms to report for duty."
					<< C_RESET	<< std::endl;

		if (bc.getGrade() >= 36)
		{
			bc.demote();
			if (bc.getGrade() == 37)
				--bc;
			std::cout	<< C_GRAY	<< bc
						<< C_RESET	<< " has been demoted."
						<< C_RESET	<< std::endl;
		}
		if (bc.getGrade() <= 38)
		{
			bc.promote();
			std::cout	<< C_GRAY	<< bc
						<< C_RESET	<< " has been promoted."
						<< C_RESET	<< std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr	<< C_LRED	<< e.what()
					<< C_RESET	<< std::endl;;
	}
	std::cout	<< std::endl;
}
