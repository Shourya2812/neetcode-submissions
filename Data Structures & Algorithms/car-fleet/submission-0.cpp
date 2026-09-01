class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size();

        // Store {position, time}
        vector<pair<int, double>> cars;

        for (int i = 0; i < n; i++) {

            double time = (double)(target - position[i]) / speed[i];

            cars.push_back({position[i], time});
        }

        // Closest to target first
        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double lastTime = 0;

        for (auto& car : cars) {

            double currentTime = car.second;

            // This car cannot catch the fleet ahead
            if (currentTime > lastTime) {
                fleets++;
                lastTime = currentTime;
            }

            // Otherwise it joins the existing fleet
        }

        return fleets;
    }
};