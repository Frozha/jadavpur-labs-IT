#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// Return whether the current frame has been damaged or lost.
int damaged_lost()
{
    return (rand() % 5 == 0); // A frame is lost or damaged with a probability of 20%.
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

void selective_repeat_nack(int n_frames, int N)
{
    vector<bool> ack(n_frames + 1, false); // Acknowledgment array

    int next_frame = 1; // Stores the next frame to be sent.
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "\n";

    while (next_frame <= n_frames)
    {
        // Sender
        cout << "Frames sent: ";

        for (int j = next_frame; j < min(next_frame + N, n_frames + 1); j++)
        {
            if (!ack[j])
                cout << j << " ";
        }

        cout << "\n";

        // Receiver
        for (int j = next_frame; j < min(next_frame + N, n_frames + 1); j++)
        {
            if (!ack[j])
            {
                if (damaged_lost())
                {
                    cout << "Frame " << j << " was lost or damaged\n";
                }
                else
                {
                    cout << "Acknowledgment received for Frame " << j << "\n";
                    ack[j] = true;
                }
            }
        }

        // Move window
        while (next_frame <= n_frames && ack[next_frame])
            next_frame++;
    }
}

int main()
{
    int n_frames, N;
    cout << "Enter the number of frames: ";
    cin >> n_frames;
    cout << "Enter the sliding window size: ";
    cin >> N;

    selective_repeat_nack(n_frames, N);

    return 0;
}

