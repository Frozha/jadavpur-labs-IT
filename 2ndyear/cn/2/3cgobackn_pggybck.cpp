#include <iostream>
#include <cstdlib>
#include <ctime>

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

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    int n_frames1, n_frames2, N1, N2; // N1 & N2 are the sliding window size for senders 1 & 2 respectively
    cout << "Enter the number of frames to be sent by sender 1: ";
    cin >> n_frames1;
    cout << "Enter the sliding window size for sender 1: ";
    cin >> N1;
    cout << "Enter the number of frames in sender 2: ";
    cin >> n_frames2;
    cout << "Enter the sliding window size for sender 2: ";
    cin >> N2;

    int next_frame1 = 1; // Stores the next frame to be sent by server 1.
    int next_frame2 = 1;
    int flag = 0; // Stores the frame number of lost or damaged frame.

    int send1_done = 0; // A flag to store whether the sender1 has sent all its frames.
    int send2_done = 0;

    cout << "\n";

    while (!(send1_done && send2_done)) // While both of them have not become true
    {
        // Sender1
        if (!send1_done)
        {
            cout << "Frames sent by sender1: ";

            for (int j = next_frame1; j < min(next_frame1 + N1, n_frames1 + 1); j++)
                cout << j << "a "; // Suffix 'a' represents frames that are to be sent by sender1.
            
            cout << "\n";
        }

        // Receiver for sender1
        flag = 0;

        for (int j = next_frame1; j < min(next_frame1 + N1, n_frames1 + 1); j++)
        {
            if (damaged_lost()) // If the current frame is damaged or lost
            {
                flag = j;
                break;
            }
        }

        if (!send1_done)
        {
            // If a frame was lost or damaged, the window slides to start from that frame.
            if (flag)
            {
                cout << "\nSender 2:\nFrame " << flag << "a was lost or damaged\n"; // Sending NACK.
                next_frame1 = flag;
            }
            else
            {
                cout << "\nSender 2:\nAcknowledgment sent for Frames " << next_frame1 << "a to " << min(next_frame1 + N1 - 1, n_frames1) << "a\n";
                next_frame1 += N1;
            }
        }

        // Sender2 sends its packets
        if (!send2_done)
        {
            cout << "Frames sent by sender2: ";

            for (int j = next_frame2; j < min(next_frame2 + N2, n_frames2 + 1); j++)
                cout << j << "b ";
            
            cout << "\n";
        }

        // Receiver for sender2
        flag = 0;

        for (int j = next_frame2; j < min(next_frame2 + N2, n_frames2 + 1); j++)
        {
            if (damaged_lost()) // If the current frame is damaged or lost
            {
                flag = j;
                break;
            }
        }

        if (!send2_done)
        {
            // If a frame was lost or damaged, the window slides to start from that frame.
            if (flag)
            {
                cout << "\nSender 1:\nFrame " << flag << "b was lost or damaged\n"; // Sending NACK.
                next_frame2 = flag;
            }
            else
            {
                cout << "\nSender 1:\nAcknowledgment sent for Frames " << next_frame2 << "b to " << min(next_frame2 + N2 - 1, n_frames2) << "b\n";
                next_frame2 += N2;
            }
        }

        if (next_frame1 > n_frames1)
            send1_done = 1;
        
        if (next_frame2 > n_frames2)
            send2_done = 1;
    }

    return 0;
}

