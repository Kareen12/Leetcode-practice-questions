class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<pair<string, int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());

        //    int count = 1;
        q.push({beginWord, 1});
        st.erase(beginWord);

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            string currString = front.first;
            int currCount = front.second;

            if (currString == endWord)
            {
                return currCount;
            }

            for (int i = 0; i < currString.length(); i++)
            {
                string oldString = currString;
                // char oldChar = currString[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    currString[i] = ch;

                    if (st.find(currString) != st.end())
                    {
                        q.push({currString, currCount + 1});
                        st.erase(currString);
                    }
                }
                currString = oldString;
            }
        }
        return 0;
    }
};