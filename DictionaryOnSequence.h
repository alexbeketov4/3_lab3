#pragma once
#include "IDictionary.h"
#include "LinkedListSequence.h"
#include <stdexcept>

template<typename TKey, typename TElement>
class DictionaryOnSequence : public IDictionary<TKey, TElement> 
{
private:
    struct KeyValuePair 
    {
        TKey key;
        TElement value;

        KeyValuePair() : key(TKey()), value(TElement()) {}

        KeyValuePair(TKey key, TElement value) : key(key), value(value) {}
    };

    LinkedListSequence<KeyValuePair> list;
    int capacity;

public:
    DictionaryOnSequence(int initialCapacity = 10) : capacity(initialCapacity) {}

    int GetCount() const override 
    {
        return list.GetLength();
    }

    int GetCapacity() const override 
    {
        return capacity;
    }

    TElement Get(TKey key) const override 
    {
        for (int i = 0; i < list.GetLength(); ++i) 
        {
            if (list.Get(i).key == key) 
            {
                return list.Get(i).value;
            }
        }
        throw std::out_of_range("Key not found");
    }

    KeyValuePair GetByIndex(int index) const
    {
        if (index < 0 || index >= list.GetLength())
        {
            throw std::out_of_range("Index out of range");
        }
        return list.Get(index);
    }

    bool ContainsKey(TKey key) const override 
    {
        for (int i = 0; i < list.GetLength(); ++i) 
        {
            if (list.Get(i).key == key) 
            {
                return true;
            }
        }
        return false;
    }

    void Add(TKey key, TElement element) override 
    {
        /*if (ContainsKey(key)) 
        {
            throw std::invalid_argument("Key already exists");
        }*/
        if (GetCount() >= capacity) 
        {
            capacity *= 2;
        }
        list.Append(KeyValuePair(key, element));
    }

    void Remove(TKey key) override 
     {
        for (int i = 0; i < list.GetLength(); ++i) 
        {
            if (list.Get(i).key == key) 
            {
                list.RemoveAt(i);
                return;
            }
        }
        throw std::out_of_range("Key not found");
    }
};