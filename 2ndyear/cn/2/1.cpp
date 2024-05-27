#include <iostream>
#include <string>

enum EventType { FrameArrival };

struct Frame {
    std::string data;
};

void WaitForEvent(EventType& event) {
    // Simulate waiting for an event. For simplicity, we directly set the event to FrameArrival.
    event = FrameArrival;
}

void GetData(std::string& data) {
    // Simulate getting data from the network layer.
    std::cout << "Enter data to send: ";
    std::getline(std::cin, data);
}

void MakeFrame(Frame& frame, const std::string& data) {
    frame.data = data;
}

void SendFrame(const Frame& frame) {
    // Simulate sending a frame to the physical layer.
    std::cout << "Sending frame: " << frame.data << std::endl;
}

int main() {
    EventType event;
    std::string data;
    Frame frame;

    while (true) {
        GetData(data);
        MakeFrame(frame, data);
        SendFrame(frame);
        WaitForEvent(event);

        // Exit the loop after sending one frame for simplicity.
        // In a real protocol, this would be a continuous loop.
        break;
    }

    return 0;
}

