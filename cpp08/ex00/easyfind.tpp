#include <algorithm>
#include <exception>
#include <vector>

class NotFoundException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Element not found in the container.";
    }
};

template <typename T>
typename T::iterator easyfind(T& container, int to_find)
{
    typename T::iterator it = std::find(container.begin(), container.end(), to_find);

    if (it == container.end()) {
        throw NotFoundException();
    }

    return it;
}
