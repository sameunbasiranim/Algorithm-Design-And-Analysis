#include <bits/stdc++.h>   // সব দরকারি লাইব্রেরি
using namespace std;      // std না লিখে ব্যবহার করার জন্য

int main()
{
    int arraySize;
    cin >> arraySize;     // array এর size ইনপুট

    vector<int> integerArray(arraySize);  // vector দিয়ে array তৈরি

    for (int i = 0; i < arraySize; i++)
    {
        cin >> integerArray[i];   // array এর সব মান ইনপুট
    }

    int desiredNumber;
    cin >> desiredNumber;   // যে সংখ্যাটা খুঁজবো

    sort(integerArray.begin(), integerArray.end());  
    // array ছোট থেকে বড় সাজানো (Binary Search এর জন্য দরকার)

    int l = 0;                  // বাম দিকের index
    int r = arraySize - 1;      // ডান দিকের index
    bool found = false;         // সংখ্যা পাওয়া গেছে কিনা চেক

    while (l <= r)              // যতক্ষণ search range আছে
    {
        int mid = l + (r - l) / 2;   // মাঝের index বের করা

        if (integerArray[mid] == desiredNumber)
        {
            found = true;       // সংখ্যা পাওয়া গেছে
            break;              // loop বন্ধ
        }
        else if (integerArray[mid] > desiredNumber)
        {
            r = mid - 1;        // ডান পাশ বাদ
        }
        else
        {
            l = mid + 1;        // বাম পাশ বাদ
        }
    }

    if (found)
        cout << "Yes\n";   // পাওয়া গেলে Yes
    else
        cout << "No\n";    // না পেলে No

    return 0;              // প্রোগ্রাম শেষ
}
