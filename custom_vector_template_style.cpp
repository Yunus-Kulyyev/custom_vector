#include <iostream>

using namespace std;

template<class varType>
class CustomVector
{
private:
    varType* expandingArray;
    int SIZE;
public:
    CustomVector()
    {
        SIZE = 0;
        expandingArray = new varType[1];
    }

    void pushToVector(varType var)
    {
        if(SIZE == 0)
        {
            expandingArray[0] = var;
        }
        else
        {
            varType* tempArray = new varType[SIZE];
            for(int i = 0; i < SIZE; i++)
            {
                tempArray[i] = expandingArray[i];
            }
            expandingArray = new varType[SIZE+1];
            for(int i = 0; i < SIZE; i++)
            {
                expandingArray[i] = tempArray[i];
            }
            expandingArray[SIZE] = var;
        }
        SIZE++;
    }

    varType getFromVector(int position)
    {
        return expandingArray[position];
    }

    int getVectorSize()
    {
        return SIZE;
    }

    void sortVector()
    {
        for(int i = 0; i < SIZE-1; i++)
        {
            for(int j = i+1; j < SIZE; j++)
            {
                if(expandingArray[i] > expandingArray[j])
                {
                    varType tempVar = expandingArray[j];
                    expandingArray[j] = expandingArray[i];
                    expandingArray[i] = tempVar;
                }
            }
        }
    }
};

int main()
{
    CustomVector<int> myVector;

    myVector.pushToVector(50);
    myVector.pushToVector(17);
    myVector.pushToVector(9);
    myVector.pushToVector(12);
    myVector.pushToVector(55);

    for(int i = 0; i < myVector.getVectorSize(); i++)
    {
        cout << myVector.getFromVector(i) << ", ";
    }

    myVector.sortVector();
    cout << endl << endl;

    for(int i = 0; i < myVector.getVectorSize(); i++)
    {
        cout << myVector.getFromVector(i) << ", ";
    }

}






