// Example 12.1

#include <vector>
#include <algorithm>
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    vector<int> v;
    for (int i = 0; i < 25; i++)
        v.push_back(i);

    random_shuffle(v.begin(), v.end());

    for (int j = 0; j < 25; j++)
        cout << v[j] << " ";
    cout << endl;

    getch();
    return 0;
}

// Example 12.2

#include <list>
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    list<int> v;
    for (int i = 0; i < 25; i++)
        v.push_back(i);

    while (!v.empty()) {
        cout << v.front() << " ";
        v.pop_front();
    }
    cout << endl;

    getch();
    return 0;
}

// Example 12.3

#include <deque>
#include <algorithm>
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    deque<int> v;
    for (int i = 0; i < 25; i++)
        v.push_back(i);

    random_shuffle(v.begin(), v.end());

    while (!v.empty()) {
        cout << v.front() << " ";
        v.pop_front();
    }
    cout << endl;

    getch();
    return 0;
}

// Example 12.4

#include <stack>
#include <list>
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    stack<int, list<int>> stk;
    for (int i = 1; i < 10; i++)
        stk.push(i);

    while (!stk.empty()) {
        cout << stk.top() << endl;
        stk.pop();
    }

    getch();
    return 0;
}

// Example 12.5

#include <bitset>
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    bitset<16> b1("1011011110001011");
    bitset<16> b2 = ~b1;

    for (int i = b2.size() - 1; i >= 0; i--)
        cout << b2[i];
    cout << endl;

    getch();
    return 0;
}

// Example 12.6

#include <vector>
#include <algorithm>
#include <iostream>
#include <conio.h>

using namespace std;

const int N = 100;

int main()
{
    vector<int> iv(N);
    iv[50] = 37;

    vector<int>::iterator iter = find(iv.begin(), iv.end(), 37);

    if (iter == iv.end())
        cout << "Not found";
    else
        cout << "Found at " << iter - iv.begin() << "\n";

    getch();
    return 0;
}

// Example 12.7

#include <vector>
#include <algorithm>
#include <iostream>
#include <conio.h>

using namespace std;

int set1[] = {1, 2, 3};
int set2[] = {2, 3, 4};
vector<int> set3(10);

int main()
{
    vector<int>::iterator first = set3.begin();
    vector<int>::iterator last = set_union(set1, set1 + 3, set2, set2 + 3, first);

    while (first != last) {
        cout << *first << " ";
        ++first;
    }

    cout << endl;
    getch();
    return 0;
}

// Exercise 12.8

#include <algorithm>
#include <iostream>

using namespace std;

int arrayOne[10];
int arrayTwo[10];

int main()
{
    fill(arrayOne, arrayOne + 10, -1);

    cout << "arrayOne after fill: ";
    for (int index = 0; index < 10; index++)
        cout << arrayOne[index] << " ";
    cout << endl;

    fill_n(arrayTwo, 5, -1);

    cout << "arrayTwo after fill_n (first 5): ";
    for (int indexTwo = 0; indexTwo < 10; indexTwo++)
        cout << arrayTwo[indexTwo] << " ";
    cout << endl;

    return 0;
}

// Exercise 12.9

#include <iostream>
#include <numeric>
#include <functional>

using namespace std;

int numbersArray[] = {1, 2, 3, 4, 5};

int main()
{
    int totalSum = accumulate(numbersArray, numbersArray + 5, 0);
    cout << "Sum of numbersArray elements: " << totalSum << endl;

    int totalProduct = accumulate(numbersArray, numbersArray + 5, 1, multiplies<int>());
    cout << "Product of numbersArray elements: " << totalProduct << endl;

    return 0;
}

// Example 12.10

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

class String {
    char* str;

public:
    String() {
        str = nullptr;
    }

    String(char* s) {
        str = strdup(s);
    }

    int operator<(const String& s) const {
        return strcmp(str, s.str) < 0;
    }

    char* getStr() const {
        return str;
    }
};

ostream& operator<<(ostream& os, const String& s) {
    return os << s.getStr();
}

int main()
{
    const int N = 5;
    char* list[N] = {"apple", "orange", "banana", "grape", "pear"};

    vector<String> v;
    for (int i = 0; i < N; i++)
        v.push_back(String(list[i]));

    random_shuffle(v.begin(), v.end());

    for (int j = 0; j < N; j++)
        cout << v[j] << " ";
    cout << endl;

    sort(v.begin(), v.end());

    for (int j = 0; j < N; j++)
        cout << v[j] << " ";
    cout << endl;

    getch();
    return 0;
}

// Exercise 12.11

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    typedef map<string, long, less<string>> WordCountMap;
    WordCountMap frequencyCounter;
    string inputWord;

    while (cin >> inputWord)
        frequencyCounter[inputWord]++;

    for (WordCountMap::iterator iterator = frequencyCounter.begin(); iterator != frequencyCounter.end(); ++iterator)
        cout << iterator->first << " " << iterator->second << endl;

    return 0;
}