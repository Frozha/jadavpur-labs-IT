#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// return whether the current frame has been damaged or lost.
int damaged_lost()
{
    return (rand() % 5 == 0); // a frame is lost or damaged with a probability of 20%.
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    int n_frames, N;
    cout << "Enter the number of frames: ";
    cin >> n_frames;
    cout << "Enter the sliding window size: ";
    cin >> N;

    int i = 1; // stores the frame to be sent next.
    int problem_occurred = 0; // stores the frame number of lost or damaged frame.

    cout << "\n";

    while (i <= n_frames)
    {
        // sender
        cout << "Frames sent: ";

        for (int j = i; j < min(i + N, n_frames + 1); j++)
            cout << j << " ";

        cout << "\n";

        // receiver
        problem_occurred = 0;

        for (int j = i; j < min(i + N, n_frames + 1); j++)
        {
            if (damaged_lost()) // if the current frame is damaged or lost
            {
                problem_occurred = j;
                break;
            }
        }

        // if a frame was lost or damaged, the next window starts from that frame.
        if (problem_occurred)
        {
            cout << "Frame " << problem_occurred << " was lost or damaged\n\n"; // sending NACK.
            i = problem_occurred;
            continue;
        }

        // sender again
        cout << "Acknowledgment received for Frames " << i << " to " << min(i + N - 1, n_frames) << "\n\n";
        i += N;
    }

    return 0;
}

