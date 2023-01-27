// Adnaan Chida

#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <string>

using namespace std;

    void solve(string passcode)
    {
        // Create an empty stack
        std::stack<char> stk;

        // The first 15 characters of the string get pushed into the stack in order
        int i = 0, n = passcode.length(), k = 0;
        while (i < n and k < 15)
        {
            stk.push(passcode[i]);
            i++;
            k++;
        }

        // Create an empty queue
        std::queue<char> que;
        k = 0;

        // The next 16 characters of the string get pushed into the queue in order
        while (i < n and k < 16)
        {
            que.push(passcode[i]);
            i++;
            k++;
        }

        // Create an empty deque
        std::deque<char> deq;

        // For the remaining characters of the string in order:
        while (i < n)
        {
            switch (passcode[i])
            {
            // 1 - Pop the stack
            case '1':
                if (!stk.empty())
                    stk.pop();
                break;

            // 2 - Pop the queue
            case '2':
                if (!que.empty())
                    que.pop();
                break;

            // 3 - Pop the front of the deque
            case '3':
                if (!deq.empty())
                    deq.pop_front();
                break;

            // 4 - Pop the back of the deque
            case '4':
                if (!deq.empty())
                    deq.pop_back();
                break;

            // 5 - Move the top element of the stack to the back of queue
            case '5':
                if (!stk.empty())
                {
                    que.push(stk.top());
                    stk.pop();
                }
                break;

            // 6 - Move the front element of the queue to the top of stack
            case '6':
                if (!que.empty())
                {
                    stk.push(que.front());
                    que.pop();
                }
                break;

            // 7 - Move the top element of the stack to the front of deque
            case '7':
                if (!stk.empty())
                {
                    deq.push_front(stk.top());
                    stk.pop();
                }
                break;

            // 8 - Move the front element of the queue to the front of deque
            case '8':
                if (!que.empty())
                {
                    deq.push_front(que.front());
                    que.pop();
                }
                break;

            // Anything else - Do nothing and move on
            default:
                break;
            }
            i++;
        }

        std::cout << "How might you feel when you get this encryption scheme working properly?" << std::endl;

        // The deque will have the secret phrase in it, listed from front to back, so print it out
        while (!deq.empty())
        {
            std::cout << deq.front();
            deq.pop_front();
        }
        std::cout << std::endl;
    }
    
    int main()
    {
        // Here is your input string
        std::string passcode = "LLSNEEIRUIGNUL-CHXUADUPUGD-RTYI61IE-GDD5E0-607325-8576A598DFJ-EH8IKD7E037FJKE87--54625B6870-FJE941597---FHE7FHJ8KEN436-471369073C8767DFE-7KO8FLKE6895-8934";
        solve(passcode);


    // Cleanup
    system("PAUSE");
    return 0;
}



/*
OUTPUT:

How might you feel when you get this encryption scheme working properly?
ALL-LINED-UP
Press any key to continue . . .

C:\Users\Adnaan Chida\source\repos\Checkpoint 5\x64\Debug\Checkpoint 5.exe (process 6748) exited with code 0.
Press any key to close this window . . .
*/