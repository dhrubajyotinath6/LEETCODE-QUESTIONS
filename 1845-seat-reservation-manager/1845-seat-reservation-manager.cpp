class SeatManager {
    // Marker to point to unreserved seats.
    int marker;

    // Min heap to store all unreserved seats.
    priority_queue<int, vector<int>, greater<int>> availableSeats;

public:
    SeatManager(int n) {
        // Set marker to the first unreserved seat.
        marker = 1;
    }

    int reserve() {
        // If min-heap has any element in it, then,
        // get the smallest-numbered unreserved seat from the min heap.
        if (!availableSeats.empty()) {
            int seatNumber = availableSeats.top();
            availableSeats.pop();
            return seatNumber;
        }

        // Otherwise, the marker points to the smallest-numbered seat.
        int seatNumber = marker;
        marker++;
        return seatNumber;
    }

    void unreserve(int seatNumber) {
        // Push unreserved seat in the min heap.
        availableSeats.push(seatNumber);
    }
};