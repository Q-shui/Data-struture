#include <iostream>

#include <vector>

using namespace std;

template <typename Comparable>
void QuickSort(vector<Comparable>& items)
{

	if (items.size() > 1)
	{
		vector<Comparable> smaller; //存放比枢纽元数值小的元素
		vector<Comparable> same;  //存放和枢纽元数值相等的元素
		vector<Comparable> larger;  //存放比枢纽元数值大的元素

		auto chosenItem = items[items.size() / 2];  //选取的枢纽元为 1 / 2 处

		for (auto& i : items)
		{
			if (i < chosenItem)
				smaller.push_back(std::move(i));  //将比枢纽元数值小的元素存入smaller
			else if (chosenItem < i)
				larger.push_back(std::move(i));  //将比枢纽元数值大的元素存入larger
			else
				same.push_back(std::move(i));  // 将和枢纽元数值相同的元素存入same
		}

		QuickSort(smaller);  //递归调用 对smaller进行排序
		QuickSort(larger);  //递归调用 对larger进行排序
		
		//将三个vector连接起来
		std::move(begin(smaller), end(smaller), begin(items));
		std::move(begin(same), end(same), begin(items) + smaller.size());
		std::move(begin(larger), end(larger), end(items) - larger.size());

	}

}

int main()
{


	return 0;
}