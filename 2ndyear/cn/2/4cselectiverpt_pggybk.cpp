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

void selective_repeat_piggybacked(int n_frames1, int N1, int n_frames2, int N2)
{
    vector<bool> ack1(n_frames1 + 1, false); // Acknowledgment array for sender 1
    vector<bool> ack2(n_frames2 + 1, false); // Acknowledgment array for sender 2

    int next_frame1 = 1; // Stores the next frame to be sent by sender 1.
    int next_frame2 = 1; // Stores the next frame to be sent by sender 2.
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "\n";

    while (next_frame1 <= n_frames1 || next_frame2 <= n_frames2)
    {
        // Sender 1
        if (next_frame1 <= n_frames1)
        {
            cout << "Frames sent by sender1: ";
            for (int j = next_frame1; j < min(next_frame1 + N1, n_frames1 + 1); j++)
            {
                if (!ack1[j])
                    cout << j << "a ";
            }
            cout << "\n";
        }

        // Sender 2
        if (next_frame2 <= n_frames2)
        {
            cout << "Frames sent by sender2: ";
            for (int j = next_frame2; j < min(next_frame2 + N2, n_frames2 + 1); j++)
            {
                if (!ack2[j])
                    cout << j << "b ";
            }
            cout << "\n";
        }

        // Receiver for sender 1
        for (int j = next_frame1; j < min(next_frame1 + N1, n_frames1 + 1); j++)
        {
            if (!ack1[j])
            {
                if (damaged_lost())
                {
                    cout << "Frame " << j << "a was lost or damaged\n";
                }
                else
                {
                    cout << "Acknowledgment received for Frame " << j << "a\n";
                    ack1[j] = true;
                }
            }
        }

        // Receiver for sender 2
        for (int j = next_frame2; j < min(next_frame2 + N2, n_frames2 + 1); j++)
        {
            if (!ack2[j])
            {
                if (damaged_lost())
                {
                    cout << "Frame " << j << "b was lost or damaged\n";
                }
                else
                {
                    cout << "Acknowledgment received for Frame " << j << "b\n";
                    ack2[j] = true;
                }
            }
        }

        // Move window for sender 1
        while (next_frame1 <= n_frames1 && ack1[next_frame1])
            next_frame1++;

        // Move window for sender 2
        while (next_frame2 <= n_frames2 && ack2[next_frame2])
            next_frame2++;
    }
}

int main()
{
    int n_frames1, N1, n_frames2, N2;
    cout << "Enter the number of frames to be sent by sender 1: ";
    cin >> n_frames1;
    cout << "Enter the sliding window size for sender 1: ";
    cin >> N1;
    cout << "Enter the number of frames to be sent by sender 2: ";
    cin >> n_frames2;
    cout << "Enter the sliding window size for sender 2: ";
    cin >> N2;

    selective_repeat_piggybacked(n_frames1, N1, n_frames2, N2);

    return 0;
}

