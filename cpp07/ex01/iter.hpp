template <typename T>
void iter(T *arr, int len, void (*f)(T &))
{
	for (int i = 0; i < len; i++)
		f(arr[i]);
}

template <typename T>
void print(T &x)
{
	std::cout << x << std::endl;
}

template <typename T>
void addOne(T &x)
{
	x++;
}