
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main()
{
	srand(time(0));

	Base*	base1 = generate();
	identify(base1);
	identify(*base1);

	A*	a1 = new A();
	identify(a1);
	identify(*a1);

	B*	b1 = new B();
	identify(b1);
	identify(*b1);

	C*	c1 = new C();
	identify(c1);
	identify(*c1);

	delete base1;
	delete a1;
	delete b1;
	delete c1;
}
