#pragma once

#include <iostream>
#include <string>

template <typename T, typename F>
void	iter(T* arr, const int n, F func)
{
	if (!arr || n <= 0)
		return;
	for (int i = 0; i < n; i++)
	{
		func(arr[i]);
	}
}