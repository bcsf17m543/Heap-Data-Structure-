#include<iostream>
using namespace std;
class Maxheap
{
private:
	int *lst;
	int hsize;
public:
	Maxheap()
	{
		hsize = 0;
		lst = new int[100];
	}
	Maxheap(int size)
	{
		hsize = 0;
		lst = new int[size];
	}
	int PARENT(int i)
	{
		return (i - 1) / 2;
	}
	int LEFT(int i)
	{
		return (2 * i + 1);
	}
	int RIGHT(int i)
	{
		return (2 * i + 2);
	}
	void Insert(int val)
	{
		lst[hsize++] = val;
		Pushup(hsize - 1);

	}
	void Add(int val)
	{
		lst[hsize++] = val;
	}
	void swap(int&a, int&b)
	{
		int temp = a;
		a = b;
		b = temp;
		return;

	}
	void Pushup(int i)
	{
		int p = PARENT(i);
		if (i > 0)
		{
			if (lst[p] < lst[i])
			{
				swap(lst[i], lst[p]);
				Pushup(PARENT(i));
			}
		}
	}
	void remove(int i)
	{
		lst[i] = lst[--hsize];
		Pushdown(i);

	}
	void Pushdown(int i)
	{
		int l = LEFT(i);
		int r = RIGHT(i);
		int BIG = i;
		if (l < hsize && lst[l] > lst[i])
		{
			BIG = l;
		}
		if (r < hsize && lst[r] > lst[BIG])
		{
			BIG = r;
		}

		if (BIG != i) {
			swap(lst[i], lst[BIG]);
			Pushdown(BIG);
		}
	}
	void Display()
	{

		for (int i = 0; i < hsize; i++)
		{

			cout << lst[i] << endl;
			if (lst[LEFT(i)] >0 )
			{
				cout << lst[LEFT(i)] << " ---- ";
			}
			if (lst[RIGHT(i)] >0 )
			{
				cout<< lst[RIGHT(i)] << endl;
			}
				


		}
	}
	int GetMax()
	{
		return lst[0];
	}
	void DeleteMax()
	{
		remove(0);
	}
	
	void DeleteAll()
	{
		while(hsize!=0)
		{
			DeleteMax();
		}
		
	}
	void Concatinate( Maxheap& rhs)
	{
		int fat = rhs.hsize + this->hsize;
		Maxheap ans(fat);
		for (int i = 0; i < hsize; i++)
		{
			ans.Add(this->lst[i]);

		}
		for (int i = 0; i < rhs.hsize; i++)
		{
			ans.Add(rhs.lst[i]);

		}
		for (int i = 0; i < fat; i++)
		{
			ans.Pushup(i);
		}
		ans.Display();

	}
};
int main()
{
	Maxheap j;
	j.Insert(1);
	j.Display();
	cout << "\n----------------\n";
	j.Insert(15);
	j.Display();
	cout << "\n----------------\n";

	j.Insert(8);
	j.Display();
	cout << "\n----------------\n";

	j.Insert(60);
	j.Display();
	cout << "\n----------------\n";

	j.Insert(10);
	j.Display();
	cout << "\n----------------\n";

	j.Insert(22);
	j.Display();
	cout << "\n----------------\n";

	j.Insert(55);
	j.Display();
	cout << "\n----------------\n";

	j.Insert(99);
	j.Display();
	cout << "\n----------------\n";

	j.Insert(45);
	j.Insert(12);

	j.Display();

	cout << "\n----------------\n";
	cout << j.GetMax();
	cout << "\n----------------\n";

	j.DeleteMax();
	j.Display();
	
	j.DeleteAll();
	cout << "\ndelete all----------------\n";

	j.Display();
	cout << "\ndelete all----------------\n";

	//------------------TASK 2---------------//
	Maxheap haj;
	Maxheap B;
	haj.Insert(6);
	haj.Insert(5);
	haj.Insert(4);
	haj.Insert(3);
	haj.Insert(2);
	haj.Insert(1);
	haj.Display();
	cout << "\n----------------\n";

	B.Insert(15);
	B.Insert(8);
	B.Insert(60);
	B.Insert(10);
	B.Insert(29);
	cout << "\n----------------\n";
	B.Display();
	cout << "\n-----Final Output-----------\n";

	haj.Concatinate(B);
	return 0;
}