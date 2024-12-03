#pragma once
#pragma once
#include "LinkedListSequence.h"
#include "ISortedSequence.h"

template <class T>
class SortedSequenceOnSequence : public ISortedSequence<T>
{
private:
	LinkedListSequence<T> data;
	Comparator<T> comp;
public:
	SortedSequenceOnSequence() :
		comp{ std::less<T>() } {}

	SortedSequenceOnSequence(const SortedSequenceOnSequence<T>& other,
		Comparator<T> comp = std::less<T>() :
		data{ other.data },
		comp{ comp } {}


	//SortedSequenceOnSequence(const ArraySequenceMutable<T>& other,



};