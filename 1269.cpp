#include <iostream>
#include <set>

std::set<int>   operator-(std::set<int> aSet, std::set<int> bSet)
{
    std::set<int>::iterator itASet;
    std::set<int>::iterator itBSet;

    itASet = aSet.begin();
    itBSet = bSet.begin();
    while (1)
    {
        if (itASet == aSet.end() || itBSet == bSet.end())
            break ;
        if (*itASet < *itBSet)
            itASet++;
        else if (*itASet > *itBSet)
            itBSet++;
        else
        {
            itASet = aSet.erase(itASet);
            itBSet++;
        }
    }
    return (aSet);
}

int main(void)
{
    std::set<int>       minusSet;
    std::set<int>       aSet;
    std::set<int>       bSet;
    std::string         aLength;
    std::string         bLength;
    size_t              pos;
    int                 setSize;
    int                 num;

    std::cin >> aLength >> bLength;
    setSize = std::stoi(aLength, &pos, 10);
    if (pos != aLength.length())
        exit(1);
    for (int i = 0; i < setSize; i++)
    {
        std::cin >> num;
        aSet.insert(num);
    }
    setSize = std::stoi(bLength, &pos, 10);
    if (pos != bLength.length())
        exit(1);
    for (int i = 0; i < setSize; i++)
    {
        std::cin >> num;
        bSet.insert(num);
    }
    std::cout << (aSet - bSet).size() + (bSet - aSet).size();
    return (0);
}
