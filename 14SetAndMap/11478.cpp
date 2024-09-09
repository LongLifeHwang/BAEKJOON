#include <iostream>
#include <set>

int main(void)
{
    std::set<std::string>   ans;
    std::string             str;
    int                     size;

    std::cin >> str;
    size = str.length();
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            if (i + j > size)
                break ;
            ans.insert(str.substr(i, j));
        }
    }
    std::cout << ans.size();
    return (0);
}