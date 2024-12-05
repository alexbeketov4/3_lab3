#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include "DictionaryOnSequence.h"
#include "SortedSequenceOnSequence.h"
 
template <class T>
class Histogram
{
private:
    LinkedListSequence<std::string> generateLetterGroups(int range)
    {
        std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int numGroups = (25 + range) / range;
        LinkedListSequence<std::string> groups;

        for (int i = 0; i < numGroups; i++)
        {
            int start = i * range;
            int end = std::min(start + range - 1, 25);
            std::string group = std::string(1, alphabet[start]) + "-" + std::string(1, alphabet[end]);
            groups.Append(group);
        }

        return groups;
    }
public:
    DictionaryOnSequence<std::string, int> CreateHistogram(SortedSequenceOnSequence<T>& seq, int range, const std::string& crit)
    {
        if (range <= 0)
        {
            throw "Range must be a positive integer";
        }

        DictionaryOnSequence<std::string, int> histogram;

        for (int i = 0; i < seq.GetLength(); ++i)
        {
            T element = seq.Get(i);
            std::string key;

            if (crit == "yearOfBirth")
            {
                int value = element.GetYearOfBirth();
                int lowerBound = (value / range) * range;
                int upperBound = lowerBound + range;
                std::ostringstream rangeKey;
                rangeKey << "[" << lowerBound << "-" << upperBound << "]";
                key = rangeKey.str();
            }

            else if (crit == "height")
            {
                int value = int(element.GetHeight());
                int lowerBound = (value / range) * range;
                int upperBound = lowerBound + range;
                std::ostringstream rangeKey;
                rangeKey << "[" << lowerBound << "-" << upperBound << "]";
                key = rangeKey.str();
            }

            else if (crit == "weight")
            {
                int value = int(element.GetWeight());
                int lowerBound = (value / range) * range;
                int upperBound = lowerBound + range;
                std::ostringstream rangeKey;
                rangeKey << "[" << lowerBound << "-" << upperBound << "]";
                key = rangeKey.str();
            }

            else if (crit == "firstNameLetter" || crit == "lastNameLetter")
            {
                LinkedListSequence<std::string> groups = generateLetterGroups(range);
                std::string name = (crit == "firstNameLetter") ? element.GetFirstname() : element.GetLastname();

                if (!name.empty() && std::isalpha(name[0]))
                {
                    char letter = std::toupper(name[0]);
                    int position = letter - 'A';
                    int groupIndex = position / range;
                    key = groups.Get(groupIndex);
                }

                else
                {
                    key = "N/A";
                }
            }

            else
            {
                throw "Invalid criterion specified";
            }

            if (histogram.ContainsKey(key))
            {
                int count = histogram.Get(key);
                histogram.Remove(key);
                histogram.Add(key, count + 1);
            }

            else
            {
                histogram.Add(key, 1);
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