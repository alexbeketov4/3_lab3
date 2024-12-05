#pragma once
#include "LinkedListSequence.h"
#include "ISortedSequence.h"

template <class T>
class SortedSequenceOnSequence : public ISortedSequence<T>
{
private:
	LinkedListSequence<T> list;
	Comparator<T> comp;
public:
	//SortedSequenceOnSequence() : comp(std::less<T>()) {}

	SortedSequenceOnSequence(Comparator<T> comp = std::less<T>()) : comp(comp) {}

	SortedSequenceOnSequence(const SortedSequenceOnSequence<T>& other, Comparator<T> comp = std::less<T>()) :list(other.list), comp(comp) {}

	SortedSequenceOnSequence(const LinkedListSequence<T>& other, Comparator<T> comp = std::less<T>()) : comp(comp)
	{
		for (int i = 0; i != other.GetLength(); i++)
		{
			Add(other.Get(i));
		}
	}

	int GetLength() const override
	{
		return list.GetLength();
	}

	bool IsEmpty() const override
	{
		return this->GetLength() == 0;
	}

	T Get(int index) const override
	{
		return list.Get(index);
	}


	T GetFirst() const override
	{
		return list.GetFirst();
	}

	T GetLast() const override
	{
		return list.GetLast();
	}

	int IndexOf(T element) const override
	{
		int left = 0;
		int right = this->GetLength() - 1;

		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (list.Get(mid) == element)
			{
				return true;
			}
			if (comp(list.Get(mid), element))
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		return -1;
	}

	SortedSequenceOnSequence<T>* GetSubsequence(int startIndex, int endIndex) const override
	{
		LinkedListSequence<T>* subList = this->list.GetSubsequence(startIndex, endIndex);
		SortedSequenceOnSequence<T>* subSeq = new SortedSequenceOnSequence<T>(*subList, comp);

		delete subList;
		return subSeq;
	}

	void Add(T element) override
	{
		for (int i = 0; i != this->GetLength(); i++)
		{
			if (comp(element, this->Get(i)))
			{
				list.InsertAt(element, i);
				return;
			}
		}
		list.Append(element);
	}
};
