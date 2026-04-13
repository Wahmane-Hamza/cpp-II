
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

	delete base1;

}
