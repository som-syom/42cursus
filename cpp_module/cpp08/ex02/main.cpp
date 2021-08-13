#include "mutantstack.hpp"

int main()
{
	std::cout << "-------------------[subject main]" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "-------------------[list iterator compare]" << std::endl;

	std::list<int> test1;
	MutantStack<int> test2;

	for (int i = 0; i < 10; i++)
	{
		test1.push_back(i + 10);
		test2.push(i + 10);
	}

	std::cout << "list.begin()        : " << *test1.begin() << std::endl;
	std::cout << "Mutantstack.begin() : " << *test2.begin() << std::endl;
	std::cout << "list.rbegin()         : " << *test1.rbegin() << std::endl;
	std::cout << "Mutantstack.rbegin()  : " << *test2.rbegin() << std::endl;

	std::list<int>::iterator iter1;
	MutantStack<int>::iterator iter2;

	std::cout << "list : ";
	for (iter1 = test1.begin(); iter1 != test1.end(); iter1++)
		std::cout << *iter1 << " ";
	std::cout << std::endl;
	
	std::cout << "Mutant Stack : ";
	for (iter2 = test2.begin(); iter2 != test2.end(); iter2++)
		std::cout << *iter2 << " ";
	std::cout << std::endl;

	std::list<int>::reverse_iterator iter3;
	MutantStack<int>::reverse_iterator iter4;

	std::cout << "reverse list : ";
	for (iter3 = test1.rbegin(); iter3 != test1.rend(); iter3++)
		std::cout << *iter3 << " ";
	std::cout << std::endl;

	std::cout << "reverse Mutant Stack : ";
	for (iter4 = test2.rbegin(); iter4 != test2.rend(); iter4++)
		std::cout << *iter4 << " ";
	std::cout << std::endl;

	return 0;
}