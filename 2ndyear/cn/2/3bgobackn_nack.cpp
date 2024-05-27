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

    int n_frames, N; // N = sliding window size
    cout << "Enter the number of frames: ";
    cin >> n_frames;
    cout << "Enter the sliding window size: ";
    cin >> N;

    int i = 1; // stores the frame to be sent next.
    int problem_occurred = 0; // a flag to indicate whether there was a lost or damaged frame.

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
                problem_occurred = 1;
                break;
            }
        }

        // sender again

        if (!problem_occurred) // if everything went fine
        {
            cout << "Acknowledgment received for Frames " << i << " to " << min(i + N - 1, n_frames) << "\n\n";
            i += N;
            continue;
        }

        // if a frame was lost or damaged, we have to send all the frames in the current window again.
        cout << "No acknowledgement received\n\nSending all the frames in the current window again\n";
    }

    return 0;
}

