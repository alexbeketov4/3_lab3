#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include "DictionaryOnSequence.h"
#include "LinkedListSequence.h"

template <class T>
class Histogram
{
public:

    DictionaryOnSequence<std::string, int> CreateHistogram(Sequence<T>& seq, int range, const std::string& crit)
    {
        DictionaryOnSequence<std::string, int> histogram;

        for (int i = 0; i < seq.GetLength(); ++i)
        {
            T element = seq.Get(i);
            int value = 0;

            if (crit == "yearOfBirth")
            {
                value = element.GetYearOfBirth();
            }
            else if (crit == "height")
            {
                value = static_cast<int>(element.GetHeight());
            }
            else if (crit == "weight")
            {
                value = static_cast<int>(element.GetWeight());
            }
            else
            {
                throw std::invalid_argument("Invalid criterion specified");
            }

            int lowerBound = (value / range) * range;
            int upperBound = lowerBound + range;
            std::ostringstream rangeKey;
            rangeKey << "[" << lowerBound << "-" << upperBound << "]";

            if (histogram.ContainsKey(rangeKey.str()))
            {
                int n = histogram.Get(rangeKey.str());
                histogram.Remove(rangeKey.str());
                histogram.Add(rangeKey.str(), n + 1);
            }
            else
            {
                histogram.Add(rangeKey.str(), 1);
            }
        }

        return histogram;
    }

    void PrintHistogram(const DictionaryOnSequence<std::string, int>& histogram)
    {
        for (int i = 0; i < histogram.GetCount(); ++i)
        {
            auto pair = histogram.GetByIndex(i);
            std::cout << pair.key << ": " << pair.value << std::endl;
        }
    }
};