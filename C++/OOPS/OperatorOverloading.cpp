#include <vector>
#include <iostream>
using namespace std;

bool operator ==(const vector<int> &lhs, const vector<int> &rhs)
{
    // Check if sizes are the same
    if (lhs.size() != rhs.size())
    {
        return false;
    }
    // Check if all elements are the same
    for (size_t i = 0; i < lhs.size(); ++i)
    {
        if (lhs[i] != rhs[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    vector<int> vec1 = {1, 2, 3, 4, 5};

    vector<int> vec2 = {1, 2, 3, 4, 5};
    vector<int> vec3 = {9, 2, 3, 4, 6};
    vector<int> vec4 = {1, 2, 3};

    cout << "vec1 == vec2: " << (vec1 == vec2) << endl; // Should print 1 (true)
    cout << "vec1 == vec3: " << (vec1 == vec3) << endl; // Should print 0 (false)
    cout << "vec1 == vec4: " << (vec1 == vec4) << endl; // Should print 0 (false)

    return 0;
}
