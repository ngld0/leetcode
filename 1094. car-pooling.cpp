class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        // given by description
        const size_t TRIP_LENGTH = 1000;
        vector<int> passengerChange = vector<int>(TRIP_LENGTH+1, 0);
        
        // Update passenger change for each trip
        for(auto trip : trips){
            int passenger =  trip[0], getOn = trip[1], getOff = trip[2];
            
            passengerChange[ getOn ] += passenger;
            passengerChange[ getOff ] -= passenger;
            
        }
        
        // Count total passenger for each bus top
        int carLoading = 0;
        
        for( size_t i = 0 ; i < passengerChange.size() ; i ++ ){
            
            carLoading += passengerChange[ i ];
            
            // Reject when the car is overloaded somewhere
            if( carLoading > capacity ){
                return false;
            }
        }
        
        // Accept only if all trip is safe
        return true;
    }
};
