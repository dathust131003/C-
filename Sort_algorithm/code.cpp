#include <iostream>
using namespace std;

void selection_Sort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min_pos = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[min_pos] > a[j])

				min_pos = j;
		}
		swap(a[min_pos], a[i]);
	}
}
/*
	đọ phức tạp : 0(n^2)
	tư tưởng : ở mỗi bước nó sẽ đưa phần tyuwr lớn nhất chưa được
	sắp xếp về cuối dãy
*/
void bubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		/*
			duyẹt các phần tử chưa được sắp xếp và đưa các phần tử
			về cuối dãy
		*/
		for (int j = 0; j < n - i - 1; j++)
		{
			/*
			voi i = 0 : chạy đeesn n -1
			với i = 1 : chạy đến n-2
			mối lần chạy sẽ đưa được 1 phần tử về cuối
			*/
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}

/*
	thuật toán sắp xếp chèn
	độ phức tạp 0(n^2)
	tư tưởng : ở mỗi bước , nó sẽ cố gắng chèn phần tử ở chỉ số i
	vào trong đoạn từ 0 -> i-1
*/

void insertingSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		// chèn phần tử a[i]  vào cái đoạn a[0,i-1]
		int pos = i - 1, x = a[i];
		for (int j = 0; j < pos; j++)
		{
			// di tìm vị trí đầu tiên < x ==> chèn đàng sau
			while (pos >= 0 && a[pos] >= x)
			{
				// dich tu traio sang phai
				a[pos + 1] = a[pos];
				--pos;
			}
			// đã tìm thấy  a[pos] là phần tử đầu tiền < x
			a[pos + 1] = x;
		}
	}
}
/*
	counting sort
	điều kiện áp dụng: khai báo đựoc mảng đếm có số lượng
	phần tử lớn nhất của phần tử trong mảng
	-- 0 < a[i]< 10^6

*/
int dem[100001]; // 0 < a[i] < 10^6
void countingSort(int a[], int n)
{
	int k = -1e9;
	for (int i = 0; i < n; i++)
	{
		dem[a[i]]++;
		k = max(k, a[i]);
	}
	for (int i = 0; i <= k; i++)
	{
		// nếu dem[i] > 0 thì vòng lập thực hiện
		for (int j = 0; j < dem[i]; ++j)
			cout << i << ' ';
	}
}

/*
	merge Sort
	tư tưởng:- chia 1 mảng thành các mảng có 1 phần tử (dùng để quy )
			 - dùng 1 hàm  để sắp xếp 2 mảng đã được sắp xếp
			 -
*/
void merge(int a[], int l, int m, int r)
{
	int n1 = m - l + 1, n2 = r - m;
	// số phần tử mảng x bằng từ  l-> m- 1 , phần tử mảng y từ m -> r
	int x[n1], y[n2];
	// gán mảng x[] từ a[l] -> a[m-1]
	for (int i = 0; i < n1; i++)
	{
		x[i] = a[l + i];
	}
	// gán mảng y[] từ a[m] -> a[r]
	for (int i = 0; i < n2; i++)
	{
		y[i] = a[m + i + 1];
	}
	// sắp xếp 2 mảng
	int i = 0, j = 0, index = l;
	while (i < n1 && j < n2)
	{
		if (x[i] > y[j])
		{
			a[index] = y[j];
			index++;
			j++;
		}
		else
		{
			a[index] = x[i];
			++index;
			++i;
		}
	}
	/*
		nếu 1 trong 2 mảng chưa hết thì gán
		các phần tử còn lại vào mảng a
	*/
	while (i < n1)
	{
		a[index] = x[i];
		index++;
		i++;
	}
	while (j < n2)
	{
		a[index] = y[j];
		index++;
		j++;
	}
}

void mergeSort(int a[], int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

/*
	quick Sort

*/

int partition(int a[], int l, int r)
{
	int pivot = a[r];
	int i = l - 1;
	for (int j = l; j < r; j++)
	{
		if (a[j] <= pivot)
		{
			++i;
			swap(a[i], a[j]);
		}
	}
	++i;
	swap(a[i], a[r]);
	return i; // trả về chỉ số của pivot
}

void quickSort(int a[], int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		int p = partition(a, l, r);
		quickSort(a, l, p - 1);
		quickSort(a, p + 1, r);
	}
} // quickSort(a,0,n-1);

int main()
{

	int a[5] = {5, 8, 4, 2, 3};
	quickSort(a, 0, 4);

	for (int x : a)
	{
		cout << x << ' ';
	}
}