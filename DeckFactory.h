#pragma once
template <typename C> class DeckFactory{
    public:
        virtual void shuffle() = 0;
        virtual C* getNext() = 0;
        virtual bool isEmpty() const = 0;
};