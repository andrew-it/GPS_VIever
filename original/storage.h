#ifndef STORAGE_H
#define STORAGE_H

#include <QDebug>

#include <stdio.h>

template<class NODETYPE>
class CIterator
{
public:
    virtual void next() = 0;
    virtual void prev() = 0;
    virtual void first() = 0;
    virtual void last() = 0;
    virtual bool eol() = 0;
};

template <class NODETYPE> class Storage;


template<class NODETYPE>
class ListNode
{
    friend class Storage < NODETYPE >;
public:
    ListNode(NODETYPE*);
    NODETYPE * getData();
    char getName();
    void printObj();
    void printInFile();
private:
    NODETYPE * data;
    ListNode<NODETYPE>*nextPtr;
    ListNode<NODETYPE>*prevPtr;
};

template <class NODETYPE>
char ListNode <NODETYPE>::getName()
{
    return this->getData()->getName();
}

template <class NODETYPE>
ListNode <NODETYPE>::ListNode(NODETYPE * info) :
data(info), nextPtr(0){

}

template <class NODETYPE>
NODETYPE * ListNode<NODETYPE>::getData(){
    return data;
}

template <class NODETYPE>
void ListNode<NODETYPE>::printObj()
{
    data->printS();
}

/////////////////////////////////////////////

template <class NODETYPE>
class Storage : public CIterator<NODETYPE>
{
public:
    Storage();
    ~Storage();
    void insertAtFront(NODETYPE *);
    void insertAtBack(NODETYPE *);
    bool removeFromFront(NODETYPE *);
    bool removeFromBack(NODETYPE *);
    bool isEmpty()const;
    void print();
    void removeCurr();
    int getSize();
    void setCurrentObject(NODETYPE *n);

    ListNode<NODETYPE> * getCurrentObject();
    ListNode<NODETYPE> * at(int i);

    void next();
    void prev();
    void first();
    void last();
    bool eol();
private:
    ListNode<NODETYPE> *firstPtr;
    ListNode<NODETYPE> *lastPtr;
    ListNode<NODETYPE> *getNewNode(NODETYPE *);
    ListNode<NODETYPE> *curPtr;
};

template <class NODETYPE>
void Storage<NODETYPE>::setCurrentObject(NODETYPE *n)
{
    int i = 0;
    for(first(); !eol(); next())
    {
        if(this->getCurrentObject()->getData() == n)
        {
            //qDebug() << "Storage::setCurrentObject complite, index =" << i;
            curPtr = this->getCurrentObject();
            break;
        }
        i++;
    }
}

template <class NODETYPE>
void Storage<NODETYPE>::removeCurr()
{
    ListNode<NODETYPE> * tmp = curPtr;
    if(firstPtr == lastPtr && lastPtr == curPtr)
        firstPtr = lastPtr = curPtr = 0;
    else
    {
    if(firstPtr == curPtr || lastPtr == curPtr)
    {
        if(firstPtr == curPtr)
            firstPtr = curPtr->nextPtr;
        if(lastPtr == curPtr)
            lastPtr = curPtr->prevPtr;
    }
    curPtr->prevPtr->nextPtr = curPtr->nextPtr;
    curPtr->nextPtr->prevPtr = curPtr->prevPtr;
    curPtr = curPtr->nextPtr;
    }
    delete(tmp);
    //qDebug() << "Storage::removeCurr()";

}


template <class NODETYPE>
ListNode<NODETYPE> *Storage<NODETYPE>::getCurrentObject()
{
    if (this->curPtr == NULL)
        this->curPtr = firstPtr;
    return this->curPtr;
}

template <class NODETYPE>
ListNode<NODETYPE> *Storage<NODETYPE>::at(int i)
{
    int k = i;
    if(i >= 0 && i <= this->getSize() && !isEmpty())
    {
        for(first(); k > 0; next())
            k--;
        return this->getCurrentObject();
    }
    else
        return NULL;
}

template <class NODETYPE>
void Storage<NODETYPE>::first()
{
    curPtr = firstPtr;
}

template <class NODETYPE>
void Storage<NODETYPE>::last()
{
    curPtr = lastPtr;
}

template <class NODETYPE>
bool Storage<NODETYPE>::eol()
{
    static bool isEnd = false;
    if ((curPtr == lastPtr) && (isEnd == false))
    {
        isEnd = true;
        return false;
    }
    else if ((curPtr == firstPtr) && (isEnd == true))
    {
        isEnd = false;
        return true;
    }
    else
        return false;
}

template <class NODETYPE>
void Storage<NODETYPE>::next()
{
    if (curPtr == lastPtr)
    {
        curPtr = firstPtr;
        return;
    }
    curPtr = curPtr->nextPtr;
}

template <class NODETYPE>
void Storage<NODETYPE>::prev()
{
    if (curPtr == firstPtr)
    {
        curPtr = lastPtr;
        return;
    }
    curPtr = curPtr->prevPtr;
}

template <class NODETYPE>
Storage<NODETYPE>::Storage() :firstPtr(0), lastPtr(0){
    curPtr = firstPtr;
}

template <class NODETYPE>
Storage<NODETYPE>::~Storage()
{
    if (!isEmpty())
    {
        qDebug() << "destroying nodes... \n";
        ListNode<NODETYPE> *currentPtr = firstPtr;
        ListNode<NODETYPE> *tempPtr;
        while (currentPtr != 0)
        {
            tempPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
            delete tempPtr;
        }
    }
    qDebug() << "all nodes destroyed\n";
}

template <class NODETYPE>
void Storage<NODETYPE>::insertAtFront(NODETYPE * value) //push_front
{
    ListNode<NODETYPE> * newPtr = getNewNode(value);
    if (isEmpty())
        firstPtr = lastPtr = curPtr = newPtr;
    else
    {
        firstPtr->prevPtr = newPtr;
        newPtr->nextPtr = firstPtr;
        newPtr->prevPtr = lastPtr;
        lastPtr->nextPtr = newPtr;
        firstPtr = newPtr;
        curPtr = newPtr;
    }
}

template <class NODETYPE>
void Storage<NODETYPE>::insertAtBack(NODETYPE * value) //push_back
{
    ListNode<NODETYPE> * newPtr = getNewNode(value);
    if (isEmpty())
        firstPtr = lastPtr = curPtr = newPtr;
    else
    {
        lastPtr->nextPtr = newPtr;
        newPtr->prevPtr = lastPtr;
        newPtr->nextPtr = firstPtr;
        firstPtr->prevPtr = newPtr;
        lastPtr = newPtr;
        curPtr = newPtr;
    }
}

template <class NODETYPE>
bool Storage<NODETYPE>::removeFromFront(NODETYPE * value)
{
    if (isEmpty())
        return false;
    else
    {
        ListNode<NODETYPE> * tempPtr = firstPtr;
        if (firstPtr == lastPtr)
            firstPtr = lastPtr = 0;
        else
        {
            firstPtr = firstPtr->nextPtr;
            firstPtr->prevPtr = lastPtr;
            lastPtr->nextPtr = firstPtr;
        }
        value = tempPtr->data;
        delete tempPtr;
        return true;
    }
}

template <class NODETYPE>
bool Storage<NODETYPE>::removeFromBack(NODETYPE * value)
{
    if (isEmpty())
        return false;
    else
    {
        ListNode<NODETYPE> * tempPtr = lastPtr;
        if (firstPtr == lastPtr)
            firstPtr = lastPtr = 0;
        else
        {
            ListNode<NODETYPE> * currentPtr = firstPtr;
            while (currentPtr->nextPtr != lastPtr)
                currentPtr = currentPtr->nextPtr;

            lastPtr = currentPtr;
            currentPtr->nextPtr = firstPtr;
            firstPtr->prevPtr = currentPtr;
        }
        value = tempPtr->data;
        delete tempPtr;
        return true;
    }
}

//template <class NODETYPE>
//bool Storage<NODETYPE>::deleteCurrentObject()
//{
//    if (isEmpty())
//        return false;
//    else
//    {
//        if (firstPtr == lastPtr)
//            firstPtr = lastPtr = curPtr = 0;
//        else
//        {
//            ListNode<NODETYPE> * currentPtr = this->getCurrentObject();
//            if(currentPtr != NULL)
//            {
//                curPtr = currentPtr->nextPtr;
//                currentPtr->nextPtr = currentPtr->prevPtr;
//                currentPtr->prevPtr = currentPtr->nextPtr;
//            }
//            delete currentPtr;
//        }
//        return true;

//    }
//}

template <class NODETYPE>
int Storage<NODETYPE>::getSize()
{
    int k=0;
    if(!this->isEmpty())
    {
        for(first(); !eol(); next())
            k++;
        return k;
    }
    else return 0;
}

template <class NODETYPE>
bool Storage<NODETYPE>::isEmpty()const
{
    return firstPtr == 0;
}

template <class NODETYPE>
ListNode<NODETYPE> *Storage<NODETYPE>::getNewNode(NODETYPE * value)
{
    return new ListNode<NODETYPE>(value);
}

template <class NODETYPE>
void Storage<NODETYPE>::print()
{
    if (isEmpty())
    {
        qDebug() << "the Storage is empty";
        return;
    }
    qDebug() << "the Storage is: \n";
    for (this->first(); !this->eol(); this->next())
    {
        (this->getObject())->printObj();
    }

}







#endif // STORAGE_H
