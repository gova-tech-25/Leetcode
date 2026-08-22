class MyCalendar {
public:
    vector<pair<int,int>> events;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        
        for(auto& event : events){
            int start = event.first;
            int end = event.second;

            if(start < endTime && end > startTime){
                return false;
            }
        }
        events.push_back({startTime , endTime});

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */