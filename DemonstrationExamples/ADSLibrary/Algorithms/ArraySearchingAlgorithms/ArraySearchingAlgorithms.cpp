namespace ADSLibrary
{
	namespace Algorithms
	{
		namespace ArraySearchingAlgorithms
		{
			bool LinearSearch1(const int a[], const int n, const int x)
			{
				for (int i = 0; i < n; i++)
				{
					if (a[i] == x)
					{
						return true;
					}
				}
				return false;
			}
			
			int LinearSearch2(const int a[], const int n, const int x)
			{
				for (int i = 0; i < n; i++)
				{
					if (a[i] == x)
					{
						return i;
					}
				}
				return -1;
			}

			bool LinearSearchRecursive1(const int a[], const int n, const int x, const int i)
			{
				if (i == n)
				{
					return false;
				}
				if (a[i] == x)
				{
					return true;
				}
				return LinearSearchRecursive1(a, n, x, i + 1);
			}

			int LinearSearchRecursive2(const int a[], const int n, const int x, const int i)
			{
				if (i == n)
				{
					return -1;
				}
				if (a[i] == x)
				{
					return i;
				}
				return LinearSearchRecursive2(a, n, x, i + 1);
			}

			bool BinarySearch1(const int a[], const int n, const int x)
			{
				int l = 0;
				int r = n - 1;
				while (l <= r)
				{
					int m = (l + r) / 2;
					if (x == a[m])
					{
						return true;
					}
					if (x < a[m])
					{
						r = m - 1;
					}
					else
					{
						l = m + 1;
					}
				}
				return false;
			}

			int BinarySearch2(const int a[], const int n, const int x)
			{
				int l = 0;
				int r = n - 1;
				while (l <= r)
				{
					int m = (l + r) / 2;
					if (x == a[m])
					{
						return m;
					}
					if (x < a[m])
					{
						r = m - 1;
					}
					else
					{
						l = m + 1;
					}
				}
				return -1;
			}

			int BinarySearch3(const int a[], const int n, const int x)
			{
				int l = 0;
				int r = n - 1;
				while (l <= r)
				{
					int m = (l + r) / 2;
					if (x == a[m])
					{
						return m;
					}
					if (x < a[m])
					{
						r = m - 1;
					}
					else
					{
						l = m + 1;
					}
				}
				return ~l;
			}

			bool BinarySearchRecursive1(const int a[], const int l, const int r, const int x)
			{
				if (l > r)
				{
					return false;
				}
				int m = (l + r) / 2;
				if (x == a[m])
				{
					return true;
				}
				if (x < a[m])
				{
					return BinarySearchRecursive1(a, l, m - 1, x);
				}
				return BinarySearchRecursive1(a, m + 1, r, x);
			}

			bool BinarySearchRecursive1a(const int a[], const int l, const int r, const int x)
			{
				if (l > r)
				{
					return false;
				}
				int m = (l + r) / 2;
				if (x == a[m])
				{
					return true;
				}
				return x < a[m] ? BinarySearchRecursive1a(a, l, m - 1, x) : BinarySearchRecursive1a(a, m + 1, r, x);
			}

			int BinarySearchRecursive2(const int a[], const int l, const int r, const int x)
			{
				if (l > r)
				{
					return -1;
				}
				int m = (l + r) / 2;
				if (x == a[m])
				{
					return m;
				}
				if (x < a[m])
				{
					return BinarySearchRecursive2(a, l, m - 1, x);
				}
				return BinarySearchRecursive2(a, m + 1, r, x);
			}

			int BinarySearchRecursive3(const int a[], const int l, const int r, const int x)
			{
				if (l > r)
				{
					return ~l;
				}
				int m = (l + r) / 2;
				if (x == a[m])
				{
					return m;
				}
				if (x < a[m])
				{
					return BinarySearchRecursive3(a, l, m - 1, x);
				}
				return BinarySearchRecursive3(a, m + 1, r, x);
			}
		}
	}
}