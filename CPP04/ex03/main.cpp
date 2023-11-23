#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

#include "print.hpp"

int		ex03Subject(void);
void	ex03Custom(void);
void	testMateria(void);
void	testCopyConstructor(void);
void	testErrorStuff(void);

int main()
{
	// ex03Subject();
	ex03Custom();
}

int	ex03Subject(void)
{
	print::headerLine("Exercise 03: Interface & recap");
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}

void	ex03Custom(void)
{
	testMateria();
	testCopyConstructor();
	testErrorStuff();
}

void	testMateria(void)
{
	print::headerLine("Exercise 03: Interface & recap - Custom Tests");
	IMateriaSource	*book = new MateriaSource;
	book->learnMateria(new Ice);
	{
		Character	harry("Harry");
		ICharacter	*draco = new Character("Draco");

		draco->equip(book->createMateria("ice"));
		draco->use(0, harry);
		book->learnMateria(new Cure);
		draco->use(0, harry);
		harry.equip(book->createMateria("cure"));
		draco->use(0, harry);
		harry.equip(book->createMateria("ice"));
		draco->use(0, harry);
		harry.use(1, *draco);
		delete draco;
		harry.use(0, harry);
	}
	delete book;
}

void	testCopyConstructor(void)
{
	print::headerLine("Deepcopy testing");
	{
		print::subHeaderLine("Deepcopy - Materia");
		Ice				*spell = new Ice;
		Ice				*copy = new Ice(*spell);

		std::cout	<< spell	<< "\t"	<< spell->getType()	<< "\n"
					<< copy	<< "\t"	<< copy->getType()
					<< std::endl;
		delete spell;
		delete copy;
	}
	{
		print::subHeaderLine("Deepcopy - MateriaSource");
		MateriaSource	pouch;

		pouch.learnMateria(new Cure);
		pouch.learnMateria(new Ice);
		MateriaSource	spare(pouch);
		pouch.displayMateria("Pouch");
		spare.displayMateria("Spare pouch");
	}
	{
		print::subHeaderLine("Deepcopy - Character");
		Character	ron("Ron");
		ron.equip(new Ice);
		Character	copy(ron);

		ron.displayCharacter();
		copy.displayCharacter();
	}
}

void	testErrorStuff(void)
{
	print::headerLine("Errorhandling testing");
	MateriaSource	book;
	Character		hermione("Hermione");

	print::subHeaderLine("Non-existing");
	hermione.use(0, hermione);
	hermione.equip(book.createMateria("cure"));
	print::subHeaderLine("Learning spells");
	AMateria	*spell = new Cure;
	book.learnMateria(new Cure);
	book.learnMateria(new Cure);
	book.learnMateria(spell);
	book.learnMateria(spell);
	book.learnMateria(spell);
	print::subHeaderLine("Equipping spells");
	hermione.equip(book.createMateria("reparo"));
	hermione.equip(book.createMateria("ice"));
	hermione.equip(book.createMateria("cure"));
	hermione.use(4, hermione);
	hermione.equip(book.createMateria("cure"));
	hermione.equip(book.createMateria("cure"));
	AMateria	*temp = book.createMateria("cure");
	hermione.equip(temp);
	hermione.equip(temp);
	print::subHeaderLine("Using spells");
	hermione.use(4, hermione);
	hermione.use(-1, hermione);
	hermione.use(2, hermione);
	print::subHeaderLine("Deconstructing");
}
